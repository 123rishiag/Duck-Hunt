#include "../../Header/Gameplay/GameplayView.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Global/ServiceLocator.h"

namespace Gameplay
{
	using namespace Global;
	using namespace UI::UIElement;

	GameplayView::GameplayView() { CreateUIElements(); }

	GameplayView::~GameplayView() { Destroy(); }

	void GameplayView::Initialize()
	{
		InitializeImage();
	}

	void GameplayView::CreateUIElements()
	{
		backgroundImage = new ImageView();
	}

	void GameplayView::InitializeImage()
	{
		sf::RenderWindow* gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
		backgroundImage->Initialize(GetBackgroundTexturePath(), gameWindow->getSize().x, gameWindow->getSize().y, sf::Vector2f(0.f, 0.f));
	}

	void GameplayView::Update()
	{
		backgroundImage->SetImageAlpha(currentBackgroundAlpha);
		backgroundImage->Update();
		currentBackgroundAlpha = maxBackgroundAlpha;
	}

	void GameplayView::Render()
	{
		backgroundImage->Render();
	}

	void GameplayView::ActivateBackgroundAlpha(bool isActivated)
	{
		if (isActivated == true)
		{
			currentBackgroundAlpha = backgroundAlpha;
		}
	}

	sf::String GameplayView::GetBackgroundTexturePath()
	{
		return Config::backgroundTexturePath;
	}

	void GameplayView::Destroy()
	{
		delete(backgroundImage);
	}
}