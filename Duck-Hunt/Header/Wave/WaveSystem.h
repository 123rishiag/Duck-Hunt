#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Wave/WaveSystemConfig.h"

namespace Wave
{
    class WaveSystem
    {
    private:
        WaveSystemConfig waveSystemConfig;

        sf::Clock clock;
        sf::Time waveTime;

    public:
        WaveSystem(const WaveSystemConfig& config);
        ~WaveSystem();

        void Initialize();
        void Update();

        void Destroy();
    };
}