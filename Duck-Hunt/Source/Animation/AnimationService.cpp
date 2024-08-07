#include "../../Header/Animation/AnimationService.h"
#include "../../Header/Animation/AnimationConfig.h"
#include "../../Header/Global/Config.h"

namespace Animation
{
	AnimationService::AnimationService() { }

	AnimationService::~AnimationService() { Destroy(); }

	void AnimationService::Initialize() { }

	void AnimationService::Update()
	{
		for (AnimationController* animationController : animationList)
			animationController->Update();

		DestroyFlaggedAnimation();
	}

	void AnimationService::Render()
	{
		for (AnimationController* animationController : animationList)
			animationController->Render();
	}

	void AnimationService::SpawnAnimation(sf::Vector2f position, AnimationType animationType)
	{
		AnimationController* animationController = new AnimationController(GetAnimationConfig(animationType));
		animationController->Initialize(position);
		animationList.push_back(animationController);
	}

	void AnimationService::DestroyAnimation(AnimationController* animationController)
	{
		flaggedAnimationList.push_back(animationController);
		animationList.erase(std::remove(animationList.begin(), animationList.end(), animationController), animationList.end());
	}

	AnimationConfig AnimationService::GetAnimationConfig(AnimationType animationType)
	{
		switch (animationType)
		{
		case Animation::AnimationType::EXPLOSION:
			return AnimationConfig(Global::Config::explosionTexturePath, 70.0f, 80.0f, 14.28f, 20.0f, 7, 0.03f);
		case Animation::AnimationType::LOAD:
			return AnimationConfig(Global::Config::loadIconTexturePath, 70.0f, 80.0f, 14.28f, 15.5f, 12, 0.03f);
		}
	}

	void AnimationService::DestroyFlaggedAnimation()
	{
		for (AnimationController* animationController : flaggedAnimationList)
			delete (animationController);

		flaggedAnimationList.clear();
	}

	void AnimationService::Reset() { Destroy(); }

	void AnimationService::Destroy()
	{
		for (AnimationController* animationController : animationList)
			delete (animationController);
	}
}