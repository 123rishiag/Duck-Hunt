#include "../../Header/Enemy/EnemyView.h"
#include "../../Header/Global/Config.h"
#include "../../Header/Enemy/EnemyController.h"
#include"../../Header/Enemy/EnemyConfig.h"

namespace Enemy
{

	using namespace Global;
	using namespace UI::UIElement;

	EnemyView::EnemyView() { CreateUIElements(); }

	EnemyView::~EnemyView() { Destroy(); }

	void EnemyView::Initialize(EnemyController* controller)
	{
		enemyController = controller;
		InitializeImage();
	}

	void EnemyView::CreateUIElements()
	{
		enemyImage = new ImageView();
	}


	void EnemyView::InitializeImage()
	{
		enemyImage->Initialize(GetEnemyTexturePath(), enemySpriteWidth, enemySpriteHeight, enemyController->GetEnemyPosition());
	}

	void EnemyView::Update()
	{
		enemyImage->SetPosition(enemyController->GetEnemyPosition());
		//enemyImage->SetOriginAtCentre();
		enemyImage->Update();
	}

	void EnemyView::Render()
	{
		enemyImage->Render();
	}

	sf::String EnemyView::GetEnemyTexturePath()
	{
		switch (enemyController->GetEnemyType())
		{
		case::Enemy::EnemyType::DUCK:
			return Config::duckTexturePath;
		case::Enemy::EnemyType::POWER_DUCK:
			return Config::powerDuckTexturePath;
		}
	}

	const sf::Sprite& EnemyView::GetEnemySprite() const
	{
		return enemyImage->GetSprite();
	}

	void EnemyView::Destroy()
	{
		delete(enemyImage);
	}
}
