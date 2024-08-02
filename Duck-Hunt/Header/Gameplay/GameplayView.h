#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/UIElement/ImageView.h"

namespace Gameplay
{
    class GameplayView
    {
    private:

        UI::UIElement::ImageView* backgroundImage;

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
    };
}