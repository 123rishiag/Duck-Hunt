#pragma once

namespace Wave
{
    struct WaveSystemConfig
    {
        int playerPointAmmo;
        int playerAreaAmmo;
        int enemyCount;

        float waveDuration; //duration of a single wave

        WaveSystemConfig() = default; // Use default for default constructor

        //this will allow us to initialize a wave with it's configuration.
        WaveSystemConfig(int pPointAmmo, int pAreaAmmo, int eCount, float wDuration);
        ~WaveSystemConfig();
    };
}