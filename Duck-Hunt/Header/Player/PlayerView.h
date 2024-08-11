#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/UIElement/ImageView.h"

namespace Player {
    class PlayerController;

    class PlayerView
    {
    private:
        float playerSpriteWidth = 60.f;
        float playerSpriteHeight = 60.f;

        PlayerController* playerController; // ptr to player controller
        UI::UIElement::ImageView* playerImage;

        void CreateUIElements();
        void InitializeImage();
        sf::String GetPlayerTexturePath();

        void Destroy();

    public:
        PlayerView();
        ~PlayerView();

        void Initialize(PlayerController* controller); // we pass a pointer of type controller because we need to use this in the view.
        void Update();
        void Render();

        const sf::Sprite& GetPlayerSprite() const;
    };
}