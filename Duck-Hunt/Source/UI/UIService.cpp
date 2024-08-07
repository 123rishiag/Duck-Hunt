#include "../../Header/UI/UIService.h"
#include "../../Header/Main/GameService.h"
#include "../../Header/UI/UIElement/TextView.h" 
#include "../../Header/UI/SplashScreen/SplashScreenUIController.h"
#include "../../Header/UI/MainMenu/MainMenuUIController.h"
#include "../../Header/UI/Instruction/InstructionUIController.h"
#include "../../Header/UI/GameplayUI/GameplayUIController.h"

namespace UI
{
	using namespace Main;
	using namespace UIElement;
	using namespace Interface;
	using namespace SplashScreen;
	using namespace MainMenu;
	using namespace Instruction;
	using namespace GameplayUI;

	UIService::UIService()
	{
		splashScreenUIController = nullptr;
		mainMenuController = nullptr;
		instructionController = nullptr;
		gameplayUIController = nullptr;
		CreateControllers();
	}

	void UIService::CreateControllers()
	{
		splashScreenUIController = new SplashScreen::SplashScreenUIController();
		mainMenuController = new MainMenu::MainMenuUIController();
		instructionController = new Instruction::InstructionUIController();
		gameplayUIController = new GameplayUI::GameplayUIController();
	}

	UIService::~UIService()
	{
		Destroy();
	}

	void UIService::Initialize()
	{
		TextView::InitializeTextView();
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

	void UIService::ShowMainMenu()
	{
		GameService::SetGameState(GameState::MAIN_MENU);
		Show();
	}

	void UIService::InitializeControllers()
	{
		splashScreenUIController->Initialize();
		mainMenuController->Initialize();
		instructionController->Initialize();
		gameplayUIController->Initialize();
		
	}

	IUIController* UIService::GetCurrentUIController()
	{
		switch (GameService::GetGameState())
		{
		case GameState::SPLASH_SCREEN:
			return splashScreenUIController;
		case GameState::MAIN_MENU:
			return mainMenuController;
		case GameState::INSTRUCTIONS:
			return instructionController;
		case GameState::GAMEPLAY:
			return gameplayUIController;
		default:
			return nullptr;
		}
	}

	void UIService::Destroy()
	{
		delete(splashScreenUIController);
		delete(mainMenuController);
		delete(instructionController);
		delete(gameplayUIController);
	}
}
