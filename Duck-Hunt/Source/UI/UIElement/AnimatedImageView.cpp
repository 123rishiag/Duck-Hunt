#include "../../Header/UI/UIElement/AnimatedImageView.h"

namespace UI
{
    namespace UIElement
    {
        AnimatedImageView::AnimatedImageView() = default;

        AnimatedImageView::~AnimatedImageView() = default;

        void AnimatedImageView::Initialize(sf::String texturePath, float imageWidth, float imageHeight, sf::Vector2f position)
        {
            ImageView::Initialize(texturePath, imageWidth, imageHeight, position);
        }

        void AnimatedImageView::RegisterCallbackFuntion(CallbackFunction animationEndCallback)
        {
            callbackFunction = animationEndCallback;
        }

        void AnimatedImageView::Update()
        {
            ImageView::Update();

            if (uiState == UIState::VISIBLE)
            {
                UpdateElapsedDuration();
                HandleAnimationProgress();
                UpdateAnimation();
            }
        }

        void AnimatedImageView::Render()
        {
            ImageView::Render();
        }

        void AnimatedImageView::PlayAnimation(AnimationType type, float duration, CallbackFunction animationEndCallback)
        {
            ImageView::Show();
            Reset();
            SetAnimationType(type);
            SetAnimationDuration(duration);
            RegisterCallbackFuntion(animationEndCallback);
        }

        void AnimatedImageView::UpdateElapsedDuration()
        {
            float deltaTime = clock.restart().asSeconds();
            elapsedDuration += deltaTime;
        }

        void AnimatedImageView::HandleAnimationProgress()
        {
            if (elapsedDuration >= animationDuration && callbackFunction)
            {
                callbackFunction();
            }
        }

        void AnimatedImageView::UpdateAnimation()
        {
            switch (animationType)
            {
            case AnimationType::FADE_IN:
                FadeIn();
                break;
            case AnimationType::FADE_OUT:
                FadeOut();
                break;
            }
        }

        void AnimatedImageView::SetAnimationDuration(float duration)
        {
            animationDuration = duration;
        }

        void AnimatedImageView::SetAnimationType(AnimationType type)
        {
            animationType = type;
        }

        void AnimatedImageView::FadeIn()
        {
            float alpha = std::min(1.0f, elapsedDuration / animationDuration);
            imageSprite.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(alpha * 255)));
        }

        void AnimatedImageView::FadeOut()
        {
            float alpha = std::max(0.0f, 1.0f - (elapsedDuration / animationDuration));
            imageSprite.setColor(sf::Color(255, 255, 255, static_cast<sf::Uint8>(alpha * 255)));
        }

        void AnimatedImageView::Reset()
        {
            animationDuration = defaultAnimationDuration;
            animationType = AnimationType::FADE_IN;
            clock.restart();
            elapsedDuration = 0.0f;
        }
    }
}