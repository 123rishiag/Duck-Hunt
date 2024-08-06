#pragma once
#include <SFML/Graphics.hpp>
#include "../../Header/Wave/WaveConfig.h"

namespace Wave
{
    class WaveController
    {
    private:
        WaveConfig waveConfig;

        sf::Clock clock;
        sf::Time waveTime;

    public:
        WaveController(const WaveConfig& config);
        ~WaveController();

        void Initialize();
        void Update();

        bool IsWaveWon() const;
        bool IsWaveLost() const;

        void Destroy();
    };
}