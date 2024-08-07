#include "../../Header/Animation/AnimationConfig.h"

namespace Animation
{
    AnimationConfig::AnimationConfig(sf::String texturePath, float spriteWidth, float spriteHeight,
        float tWidth, float tHeight, int frames, float duration)
    {
        animationTexturePath = texturePath;
        spriteSheetWidth = spriteWidth;
        spriteSheetHeight = spriteHeight;
        tileWidth = tWidth;
        tileHeight = tHeight;
        numberOFAnimationFrames = frames;
        frameDuration = duration;
    }
    AnimationConfig::~AnimationConfig() { }
}