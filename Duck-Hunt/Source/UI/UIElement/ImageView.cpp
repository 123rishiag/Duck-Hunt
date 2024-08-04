#include "../../Header/UI/UIElement/ImageView.h"

namespace UI
{
    namespace UIElement
    {
        ImageView::ImageView() = default;

        ImageView::~ImageView() = default;

        void ImageView::Initialize(sf::String texturePath, float imageWidth, float imageHeight, sf::Vector2f position)
        {
            UIView::Initialize();
            SetTexture(texturePath);
            SetScale(imageWidth, imageHeight);
            SetPosition(position);
        }

        void ImageView::Update()
        {
            UIView::Update();
        }

        void ImageView::Render()
        {
            UIView::Render();

            if (uiState == UIState::VISIBLE)
            {
                gameWindow->draw(imageSprite);
            }
        }

        void ImageView::SetTexture(sf::String texturePath)
        {
            if (imageTexture.loadFromFile(texturePath))
            {
                imageSprite.setTexture(imageTexture);
            } 
        }

        void ImageView::SetTextureRect(sf::IntRect textureRect)
        {
            imageSprite.setTextureRect(textureRect);
        }

        void ImageView::SetScale(float width, float height)
        {
            SetScale(width, height, imageSprite.getTexture()->getSize().x, imageSprite.getTexture()->getSize().y);
        }

        void ImageView::SetScale(float width, float height, float tileWidth, float tileHeight)
        {
            float scaleX = width / tileWidth;
            float scaleY = height / tileHeight;

            imageSprite.setScale(scaleX, scaleY);
        }

        void ImageView::SetPosition(sf::Vector2f position)
        {
            imageSprite.setPosition(position);
        }

        void ImageView::SetRotation(float rotationAngle)
        {
            imageSprite.setRotation(rotationAngle);
        }

        void ImageView::SetOriginAtCentre()
        {
            imageSprite.setOrigin(imageSprite.getLocalBounds().width / 2, imageSprite.getLocalBounds().height / 2);
        }

        void ImageView::SetImageAlpha(float alpha)
        {
            sf::Color color = imageSprite.getColor();
            color.a = alpha;
            imageSprite.setColor(color);
        }

        void ImageView::SetCentreAligned()
        {
            float xPosition = (gameWindow->getSize().x / 2) - (imageSprite.getGlobalBounds().width / 2);
            float yPosition = imageSprite.getGlobalBounds().getPosition().y;

            imageSprite.setPosition(xPosition, yPosition);
        }

        const sf::Sprite& ImageView::GetSprite()
        {
            return imageSprite; //returns the sprite.
        }
    }
}