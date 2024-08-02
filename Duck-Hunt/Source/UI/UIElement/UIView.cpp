#include "../../Header/UI/UIElement/UIView.h"
#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Graphic/GraphicService.h"

namespace UI
{
	namespace UIElement
	{
		using namespace Global;
		using namespace Graphic;

		UIView::UIView() = default;

		UIView::~UIView() = default;

		void UIView::Initialize()
		{
			gameWindow = ServiceLocator::GetInstance()->GetGraphicService()->GetGameWindow();
			uiState = UIState::VISIBLE;
		}

		void UIView::Update() { }

		void UIView::Render() { }

		void UIView::Show()
		{
			uiState = UIState::VISIBLE;
		}

		void UIView::Hide()
		{
			uiState = UIState::HIDDEN;
		}
	}
}