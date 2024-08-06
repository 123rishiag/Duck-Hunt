#pragma once
#include "../../Header/Wave/WaveConfig.h"

namespace Wave
{
    class WaveController
    {
    private:
        WaveConfig waveConfig;

        float waveTimeLeft;
        float stateTime;

        const float waveBootTime = 3.f;
        const float waveResultTime = 3.f;
        
        WaveState currentWaveState;
        WaveResult currentWaveResult;

        void UpdateWaveState();

        bool IsWaveWon() const;
        bool IsWaveLost() const;

    public:
        WaveController(const WaveConfig& config);
        ~WaveController();

        void Initialize();
        void Update();

        void UpdateConfig(const WaveConfig& config);
        sf::String GetWaveName() const;
        float GetWaveTimeLeft() const;
        void SetWaveTimeLeft();

        WaveState GetWaveState() const;
        WaveResult GetWaveResult() const;

        void Reset();
    };
}