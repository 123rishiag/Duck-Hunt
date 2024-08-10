#pragma once
#include "../../Header/UI/UIElement/UIView.h"

namespace UI
{
	namespace UIElement
	{
		class ImageView : public UIView
		{
		protected:
			sf::Texture imageTexture;
			sf::Sprite imageSprite;

		public:
			ImageView();
			virtual ~ImageView();

			virtual void Initialize(sf::String texturePath, float imageWidth, float imageHeight, sf::Vector2f position);
			virtual void UpdateContent() override;
			virtual void RenderContent() override;

			virtual void SetTexture(sf::String texturePath);
			virtual void SetTextureRect(sf::IntRect textureRect);
			virtual void SetScale(float width, float height);
			virtual void SetScale(float width, float height, float tileWidth, float tileHeight);
			virtual void SetPosition(sf::Vector2f position);
			virtual void SetRotation(float rotationAngle);
			virtual void SetOriginAtCentre();
			virtual void SetImageAlpha(float alpha);
			virtual void SetCentreAligned();

			const sf::Sprite& GetSprite();
		};
	}
}