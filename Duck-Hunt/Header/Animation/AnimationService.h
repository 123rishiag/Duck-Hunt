#pragma once
#include <vector>
#include <SFML/System/Vector2.hpp>
#include "../../Header/Animation/AnimationController.h"

namespace Animation
{
	enum class AnimationType
	{
		EXPLOSION,
		LOAD,
	};

	class AnimationService
	{
	private:
		std::vector<AnimationController*> animationList;
		std::vector<AnimationController*> flaggedAnimationList;

		AnimationConfig GetAnimationConfig(AnimationType animationType);
		void DestroyFlaggedAnimation();
		void Destroy();

	public:
		AnimationService();
		virtual ~AnimationService();

		void Initialize();
		void Update();
		void Render();

		void Reset();

		void SpawnAnimation(sf::Vector2f position, AnimationType animationType);
		void DestroyAnimation(AnimationController* animationController);
	};
}