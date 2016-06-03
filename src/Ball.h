#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>

/// <summary>
/// Ball class for creating the ball.
/// </summary>
class Ball
{
private:
	sf::CircleShape ball = sf::CircleShape();
	sf::Vector2f originalPosition = sf::Vector2f(0.0f, 0.0f);
	
	double minDegree = 30.0, maxMinDif = 45.0, percentOfDegreesDifInDecimal = 0.0;
	float speed = 0.0f;
	bool goingUp = true, goingLeft = false;

	void randomDirection();
public:
	Ball() {}

	/// <summary>
	/// Construct the ball of the game and set its radius, position, speed, and movement ranges.
	/// </summary>
	/// <param name="radius">
	/// The radius in pixels of the ball. Min: 1
	/// </param>
	/// <param name="position">
	/// The initial position in pixels of the ball.
	/// </param>
	/// <param name="ballSpeed">
	/// The max speed in pixels of the ball. Min: 1
	/// </param>
	/// <param name="minAngleInDegrees">
	/// The minimum angle in degrees that the ball can travel. Degree range(30 to 75)
	/// </param>
	/// <param name="maxAngleInDegrees">
	/// The maximum angle in degrees that the ball can travel. Degree range(30 to 75)
	/// </param>
	Ball(const int radius, const sf::Vector2f &position, const int ballSpeed = 1, const double minAngleInDegrees = 30.0, 
		const double maxAngleInDegrees = 75.0);

	sf::CircleShape getBall() const;
	bool isLeft() const;

	/// <summary>
	/// Set the percent of the difference between the minimum and maximum degree in decimal.
	/// </summary>
	/// <param name="decimalPercentOfDegreeDifference">
	/// The percentage of the difference between the minimum and maximum degree in decimal that the ball can travel. Range: (0.00 to 1.00)
	/// </param>
	void setPercentOfDegreesDifInDecimal(const double decimalPercentOfDegreeDifference);

	/// <summary>
	/// Toggle ball's vertical direction when collided with the top and bottom of the screen. The center Y position is needed to ensure the ball stays in
	/// the same direction until collision is detected.
	/// </summary>
	/// <param name="centerY">
	/// The center y value of the screen in pixels. Note: Nonnegative only.
	/// </param>
	void wallCollision(const float centerY);

	void toggleHorizontalDirection();

	/// <summary>
	/// Move the ball using deltatime because of frame dependent.
	/// </summary>
	/// <param name="deltaTime">
	/// The change in time per frame in seconds.
	/// </param>
	void move(const float deltaTime);

	void reset();
};

#endif
