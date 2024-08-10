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
		uiControllers.fill(nullptr); // Initialize all pointers to nullptr
		CreateControllers();
	}

	void UIService::CreateControllers()
	{
		// Create objects and insert them in the array in the required order
		uiControllers = {
			new SplashScreen::SplashScreenUIController(),
			new MainMenu::MainMenuUIController(),
			new Instruction::InstructionUIController(),
			new GameplayUI::GameplayUIController()
		};
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
		for (auto& controller : uiControllers)
		{
			if (controller)
			{
				controller->Initialize();
			}
		}
	}

	IUIController* UIService::GetCurrentUIController()
	{
		switch (GameService::GetGameState())
		{
		case GameState::SPLASH_SCREEN:
			return uiControllers[0];
		case GameState::MAIN_MENU:
			return uiControllers[1];
		case GameState::INSTRUCTIONS:
			return uiControllers[2];
		case GameState::GAMEPLAY:
			return uiControllers[3];
		default:
			return nullptr;
		}
	}

	void UIService::Destroy()
	{
		for (auto& controller : uiControllers)
		{
			delete (controller);
			controller = nullptr;
		}
	}
}
