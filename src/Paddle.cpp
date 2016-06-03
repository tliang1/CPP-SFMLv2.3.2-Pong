#include "Paddle.h"

Paddle::Paddle(const int paddleWidth, const int paddleHeight, const sf::Vector2f &paddlePosition, const int paddleSpeed, const bool collisionRightSide, 
	const int minimumY, const int maximumY) : originalPosition(paddlePosition), speed(static_cast<float>(paddleSpeed)), 
	collisionRight(collisionRightSide), minY(static_cast<float>(minimumY)), maxY(static_cast<float>(maximumY))
{
	float pW = static_cast<float>(paddleWidth);
	float pH = static_cast<float>(paddleHeight);

	if (pW < 1.0f)
		pW = 1.0f;

	if (pH < 1.0f)
		pH = 1.0f;

	if (originalPosition.x < 25.0f)
		originalPosition.x = 25.0f;

	if (speed < 1.0f)
		speed = 1.0f;

	if (minY < 0.0f)
		minY = 0.0f;

	if (maxY < minY)
		maxY = minY;

	paddle.setSize(sf::Vector2f(pW, pH));
	paddle.setOrigin(paddleWidth / 2.0f, paddleHeight / 2.0f);
	paddle.setPosition(originalPosition);
	paddle.setFillColor(sf::Color::Blue);
	paddle.setOutlineColor(sf::Color::Black);
	paddle.setOutlineThickness(1.0f);
}

sf::RectangleShape Paddle::getPaddle() const
{
	return paddle;
}

bool Paddle::isCollisionRight() const
{
	return collisionRight;
}

void Paddle::move(const float deltaTime, const bool Up)
{
	if (deltaTime > 0.0f)
	{
		float y = speed * deltaTime;
		if (Up)
		{
			if ((paddle.getPosition().y - y) > (minY + (paddle.getSize().y / 2.0f)))
			{
				paddle.move(sf::Vector2f(0.0f, -y));
			}
			else
			{
				paddle.move(sf::Vector2f(0.0f, minY - paddle.getPosition().y + (paddle.getSize().y / 2.0f)));
			}
		}
		else
		{
			if ((paddle.getPosition().y + y) < (maxY - (paddle.getSize().y / 2.0f)))
			{
				paddle.move(sf::Vector2f(0.0f, y));
			}
			else
			{
				paddle.move(sf::Vector2f(0.0f, maxY - paddle.getPosition().y - (paddle.getSize().y / 2.0f)));
			}
		}
	}
}

void Paddle::reset()
{
	paddle.setPosition(originalPosition);
}