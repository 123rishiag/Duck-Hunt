#pragma once

namespace Wave
{
    struct WaveConfig
    {
        int playerPointAmmo;
        int playerAreaAmmo;
        int enemyCount;

        float waveDuration; //duration of a single wave

        WaveConfig() = default; // Use default for default constructor

        //this will allow us to initialize a wave with it's configuration.
        WaveConfig(int pPointAmmo, int pAreaAmmo, int eCount, float wDuration);
        ~WaveConfig();
    };
}