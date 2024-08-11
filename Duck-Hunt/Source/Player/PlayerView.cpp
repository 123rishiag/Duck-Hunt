#include "../../Header/Player/PlayerView.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Player/PlayerController.h"

namespace Player {

	using namespace Global;
	using namespace UI::UIElement;

	PlayerView::PlayerView() { CreateUIElements(); }

	PlayerView::~PlayerView() { Destroy(); }

	void PlayerView::Initialize(PlayerController* controller)
	{
		playerController = controller;
		InitializeImage();
	}

	void PlayerView::CreateUIElements()
	{
		playerImage = new ImageView();
	}

	void PlayerView::InitializeImage()
	{
		playerImage->Initialize(GetPlayerTexturePath(), playerSpriteWidth, playerSpriteHeight, playerController->GetPlayerPosition());
	}

	void PlayerView::Update()
	{
		// Updating player radius based on type of bullet selected
		playerImage->SetScale(playerController->GetBulletRadius() * 2, playerController->GetBulletRadius() * 2);
		playerImage->SetPosition(playerController->GetPlayerPosition());
		playerImage->SetOriginAtCentre();
		playerImage->SetImageAlpha(50.f);
		playerImage->Update();
	}

	void PlayerView::Render()
	{
		playerImage->Render();
	}

	sf::String PlayerView::GetPlayerTexturePath()
	{
		return Config::playerTexturePath;
	}

	const sf::Sprite& PlayerView::GetPlayerSprite() const
	{
		return playerImage->GetSprite();
	}

	void PlayerView::Destroy()
	{
		delete(playerImage);
	}
}
