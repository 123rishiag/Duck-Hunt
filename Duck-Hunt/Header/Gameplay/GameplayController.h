#pragma once
#include <SFML/Graphics.hpp>

namespace Gameplay
{
    class GameplayView;

    class GameplayController
    {
    private:
        GameplayView* gameplayView;

    public:
        GameplayController();
        ~GameplayController();

        void Initialize();
        void Update();
        void Render();
    };
}