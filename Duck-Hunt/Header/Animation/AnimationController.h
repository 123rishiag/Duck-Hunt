#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Animation/AnimationConfig.h"
#include "../../Header/UI/UIElement/ImageView.h"

namespace Animation
{
    class AnimationController
    {
    private:
        AnimationConfig animationConfig;

        sf::Vector2f animationPosition;
        UI::UIElement::ImageView* animationImage;

        void CreateUIElements();
        void InitializeImage();

        int currentFrame;
        sf::Clock clock;
        sf::Time frameTime;

    public:
        AnimationController(const AnimationConfig& config);
        ~AnimationController();

        void Initialize(sf::Vector2f position, float radius = 0.f);
        void Update();
        void Render();

        void Destroy();
    };
}