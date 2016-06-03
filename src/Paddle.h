#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

/// <summary>
/// Paddle class for creating the paddle.
/// </summary>
class Paddle
{
private:
	sf::RectangleShape paddle;
	sf::Vector2f originalPosition = sf::Vector2f(0.0f, 0.0f);

	float speed = 1.0f, minY = 0.0f, maxY = 0.0f;
	bool collisionRight = true;
public:
	Paddle() {}

	/// <summary>
	/// Construct the paddle of the game and set its size, position, speed, direction of collision detection, and its vertical bounds.
	/// </summary>
	/// <param name="paddleWidth">
	/// The pixel width of the paddle. Min: 1
	/// </param>
	/// <param name="paddleHeight">
	/// The pixel height of the paddle. Min: 1
	/// </param>
	/// <param name="paddlePosition">
	/// The initial position of the paddle. X Min: 25.0f
	/// </param>
	/// <param name="paddleSpeed">
	/// The speed of the paddle in pixels. Min: 1
	/// </param>
	/// <param name="collisionRightSide">
	/// Collision detection on the Left or right side of the paddle.
	/// </param>
	/// <param name="minimumY">
	/// The minimum position the paddle can go in pixels. Min: 0
	/// </param>
	/// <param name="maximumY">
	/// The maximum position the paddle can go in pixels.
	/// </param>
	Paddle(const int paddleWidth, const int paddleHeight, const sf::Vector2f &paddlePosition, const int paddleSpeed, const bool collisionRightSide, 
		const int minimumY, const int maximumY);
	
	sf::RectangleShape getPaddle() const;
	bool isCollisionRight() const;

	/// <summary>
	/// Move the paddle up or down using deltatime because of frame dependent.
	/// </summary>
	/// <param name="deltaTime">
	/// The change in time per frame in seconds.
	/// </param>
	/// <param name="Up">
	/// Move up or down.
	/// </param>
	void move(const float deltaTime, const bool Up);

	void reset();
};

#endif