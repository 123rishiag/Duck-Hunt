#include "../../Header/Animation/AnimationController.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Animation/AnimationService.h"

namespace Animation
{
	using namespace Global;
	using namespace UI::UIElement;

	AnimationController::AnimationController(const AnimationConfig& config)
	{
		animationConfig = config;
		CreateUIElements();
	}

	AnimationController::~AnimationController()
	{
		delete(animationImage);
	}

	void AnimationController::Initialize(sf::Vector2f position)
	{
		animationPosition = position;
		currentFrame = 0;
		frameTime = sf::seconds(animationConfig.frameDuration);

		InitializeImage();
	}

	void AnimationController::CreateUIElements()
	{
		animationImage = new ImageView();
	}

	void AnimationController::InitializeImage()
	{
		animationImage->Initialize(animationConfig.animationTexturePath, 0, 0, animationPosition);
		animationImage->SetTextureRect(sf::IntRect(0, 0, animationConfig.tileWidth, animationConfig.tileHeight));

		animationImage->SetScale(animationConfig.spriteSheetWidth, animationConfig.spriteSheetHeight, animationConfig.tileWidth, animationConfig.tileHeight);
	}

	void AnimationController::Update()
	{
		if (clock.getElapsedTime() >= frameTime)
		{
			if (currentFrame + 1 >= animationConfig.numberOFAnimationFrames)
				Destroy();

			currentFrame = (currentFrame + 1) % animationConfig.numberOFAnimationFrames;
			clock.restart();

			animationImage->SetTextureRect(sf::IntRect(
				currentFrame * animationConfig.tileWidth,
				0,
				animationConfig.tileWidth,
				animationConfig.tileHeight));
		}
		animationImage->Update();
	}

	void AnimationController::Render()
	{
		animationImage->Render();
	}

	void AnimationController::Destroy()
	{
		ServiceLocator::GetInstance()->GetAnimationService()->DestroyAnimation(this);
	}
}