#pragma once
#include <SFML/Graphics.hpp>

namespace Wave
{
    enum class WaveState
    {
        WAVE_BOOT,
        WAVE_PLAY,
        WAVE_RESULT,
    };

    enum class WaveResult
    {
        WAVE_UNDECIDED,
        WAVE_WON,
        WAVE_LOST,
    };

    enum class WaveType
    {
        WAVE_1,
        WAVE_2,
        WAVE_END,
    };

    struct WaveConfig
    {
        sf::String waveName;
        int playerPointAmmo;
        int playerAreaAmmo;
        int enemyCount;

        float waveDuration; //duration of a wave

        WaveConfig() = default; // Use default for default constructor

        //this will allow us to initialize a wave with it's configuration.
        WaveConfig(sf::String wName, int pPointAmmo, int pAreaAmmo, int eCount, float wDuration);
        ~WaveConfig();
    };
}