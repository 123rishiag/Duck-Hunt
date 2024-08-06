#include "../../Header/Wave/WaveSystemConfig.h"

namespace Wave
{
    WaveSystemConfig::WaveSystemConfig(int pPointAmmo, int pAreaAmmo, int eCount, float wDuration)
    {
        playerPointAmmo = pPointAmmo;
        playerAreaAmmo = pAreaAmmo;
        enemyCount = eCount;
        waveDuration = wDuration;
    }
    WaveSystemConfig::~WaveSystemConfig() { }
}