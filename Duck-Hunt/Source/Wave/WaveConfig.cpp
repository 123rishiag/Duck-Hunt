#include "../../Header/Wave/WaveConfig.h"

namespace Wave
{
    WaveConfig::WaveConfig(int pPointAmmo, int pAreaAmmo, int eCount, float wDuration)
    {
        playerPointAmmo = pPointAmmo;
        playerAreaAmmo = pAreaAmmo;
        enemyCount = eCount;
        waveDuration = wDuration;
    }
    WaveConfig::~WaveConfig() { }
}