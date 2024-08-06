#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/UIElement/ImageView.h"

namespace Gameplay
{
    class GameplayView
    {
    private:

        UI::UIElement::ImageView* backgroundImage;
        float currentBackgroundAlpha;
        const float backgroundAlpha = 200.f;
        const float maxBackgroundAlpha = 255.f;

        void CreateUIElements();
        void InitializeImage();
        sf::String GetBackgroundTexturePath();

        void Destroy();

    public:
        GameplayView();
        ~GameplayView();

        void Initialize();
        void Update();
        void Render();

        void ActivateBackgroundAlpha(bool isActivated = false);
    };
}