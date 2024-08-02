#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"
//#include "../../Header/UI/GameplayUI/GameplayUIController.h"

namespace UI
{
	using namespace Main;
	using namespace Interface;
	using namespace GameplayUI;

	UIService::UIService()
	{
		gameplayUIController = nullptr;
		CreateControllers();
	}

	void UIService::CreateControllers()
	{
		//gameplayUIController = new GameplayUI::GameplayUIController();
	}

	UIService::~UIService()
	{
		Destroy();
	}

	void UIService::Initialize()
	{
		//TextView::InitializeTextView();
		InitializeControllers();
	}

	void UIService::Update()
	{
		IUIController* uiController = GetCurrentUIController();
		if (uiController) uiController->Update();
	}

	void UIService::Render()
	{
		IUIController* uiController = GetCurrentUIController();
		if (uiController) uiController->Render();
	}

	void UIService::Show()
	{
		IUIController* uiController = GetCurrentUIController();
		if (uiController) uiController->Show();
	}

	void UIService::InitializeControllers()
	{
		//gameplayUIController->Initialize();
	}

	IUIController* UIService::GetCurrentUIController()
	{
		switch (GameService::GetGameState())
		{
		case GameState::GAMEPLAY:
			return nullptr; //gameplayUIController;
		default:
			return nullptr;
		}
	}

	void UIService::Destroy()
	{
		delete(gameplayUIController);
	}
}
