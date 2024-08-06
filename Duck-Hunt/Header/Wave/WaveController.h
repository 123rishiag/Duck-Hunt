#pragma once
#include "../../Header/Wave/WaveConfig.h"

namespace Wave
{
    class WaveController
    {
    private:
        WaveConfig waveConfig;

        float waveTimeLeft;

    public:
        WaveController(const WaveConfig& config);
        ~WaveController();

        void Initialize();
        void Update();

        void UpdateConfig(const WaveConfig& config);
        float GetWaveTimeLeft() const;
        void SetWaveTimeLeft();

        bool IsWaveWon() const;
        bool IsWaveLost() const;
    };
}