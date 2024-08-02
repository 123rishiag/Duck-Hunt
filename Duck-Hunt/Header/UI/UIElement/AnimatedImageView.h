#pragma once
#include "../../Header/UI/UIElement/ImageView.h"
#include <functional>

namespace UI
{
	namespace UIElement
	{
		enum class AnimationType
		{
			FADE_IN,
			FADE_OUT,
		};

		class AnimatedImageView : public ImageView
		{
		private:
			// Define a function pointer type for the callback function
			using CallbackFunction = std::function<void()>;

			// Store the callback function
			CallbackFunction callbackFunction = nullptr;

			void UpdateElapsedDuration();
			void HandleAnimationProgress();
			void UpdateAnimation();

		protected:
			const float defaultAnimationDuration = 2.0f;

			AnimationType animationType;
			float animationDuration;
			float elapsedDuration;
			sf::Clock clock;

			virtual void Reset();
			void SetAnimationDuration(float duration);
			void SetAnimationType(AnimationType type);

			virtual void FadeIn();
			virtual void FadeOut();

		public:
			AnimatedImageView();
			virtual ~AnimatedImageView();

			virtual void Initialize(sf::String texturePath, float imageWidth, float imageHeight, sf::Vector2f position) override;
			virtual void Update() override;
			virtual void Render() override;

			virtual void PlayAnimation(AnimationType type, float duration, CallbackFunction animationEndCallback);

			void RegisterCallbackFuntion(CallbackFunction animationEndCallback);
		};
	}
}