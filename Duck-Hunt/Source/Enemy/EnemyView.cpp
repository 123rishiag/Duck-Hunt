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
		enemyImage->Initialize(EnemyConfig::GetEnemyTexturePath(enemyController->GetEnemyType()), enemySpriteWidth, enemySpriteHeight, enemyController->GetEnemyPosition());
	}

	void EnemyView::Update()
	{
		enemyImage->SetPosition(enemyController->GetEnemyPosition());
		enemyImage->SetOriginAtCentre();
		enemyImage->Update();
	}

	void EnemyView::Render()
	{
		enemyImage->Render();
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
