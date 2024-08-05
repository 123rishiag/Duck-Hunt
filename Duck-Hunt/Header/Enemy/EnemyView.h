#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/UI/UIElement/ImageView.h"

namespace Enemy
{
    enum class EnemyType;
    class EnemyController;

    class EnemyView
    {
    private:
        const float enemySpriteWidth = 80.f;
        const float enemySpriteHeight = 80.f;

        EnemyController* enemyController;
        UI::UIElement::ImageView* enemyImage;

        void CreateUIElements();
        void InitializeImage();

        void Destroy();

    public:
        EnemyView();
        ~EnemyView();

        void Initialize(EnemyController* controller);
        void Update();
        void Render();

        const sf::Sprite& GetEnemySprite() const;
    };
}