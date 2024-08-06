#include "../../Header/Wave/WaveConfig.h"

namespace Wave
{
    WaveConfig::WaveConfig(sf::String wName, int pPointAmmo, int pAreaAmmo, int eCount, float wDuration)
    {
        waveName = wName;
        playerPointAmmo = pPointAmmo;
        playerAreaAmmo = pAreaAmmo;
        enemyCount = eCount;
        waveDuration = wDuration;
    }
    WaveConfig::~WaveConfig() { }
}