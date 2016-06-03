#include "Ball.h"
#include <stdlib.h>
#include <random>

#define PI 3.14159265

void Ball::randomDirection()
{
	std::random_device seed;
	std::mt19937 randomNumberGenerator(seed()); // mersenne_twister
	std::uniform_int_distribution<int> idist(0, 1);

	goingUp = idist(randomNumberGenerator) != 0;
	goingLeft = idist(randomNumberGenerator) != 0;
}

Ball::Ball(const int radius, const sf::Vector2f &position, const int ballSpeed, const double minAngleInDegrees, const double maxAngleInDegrees)
	: originalPosition(position), speed(static_cast<float>(ballSpeed)), minDegree(minAngleInDegrees)
{
	randomDirection();

	if (radius < 1)
	{
		ball.setRadius(1.0f);
		ball.setOrigin(1.0f, 1.0f);
	}
	else
	{
		ball.setRadius(static_cast<float>(radius));
		ball.setOrigin(static_cast<float>(radius), static_cast<float>(radius));
	}

	ball.setPosition(originalPosition);
	ball.setFillColor(sf::Color::Red);
	ball.setOutlineColor(sf::Color::Black);
	ball.setOutlineThickness(1.0f);

	if (speed < 1.0f)
		speed = 1.0f;

	double maxDegree = maxAngleInDegrees;

	if (minDegree < 30.0)
		minDegree = 30.0;
	else if (minDegree > 75.0)
		minDegree = 75.0;

	if (maxDegree < 30.0)
		maxDegree = 30.0;
	else if (maxDegree > 75.0)
		maxDegree = 75.0;

	if (minDegree > maxDegree)
	{
		double temp = minDegree;
		minDegree = maxDegree;
		maxDegree = minDegree;
	}

	maxMinDif = maxDegree - minDegree;
}

sf::CircleShape Ball::getBall() const
{
	return ball;
}

bool Ball::isLeft() const
{
	return goingLeft;
}

void Ball::setPercentOfDegreesDifInDecimal(const double decimalPercentOfDegreeDifference)
{
	if ((decimalPercentOfDegreeDifference >= 0.0) && (decimalPercentOfDegreeDifference <= 1.0))
	{
		percentOfDegreesDifInDecimal = decimalPercentOfDegreeDifference;
	}
}

void Ball::wallCollision(const float centerY)
{
	if (centerY >= 0)
	{
		if (ball.getPosition().y < centerY)
		{
			goingUp = false;
		}
		else
		{
			goingUp = true;
		}
	}
}

void Ball::toggleHorizontalDirection()
{
	goingLeft = !goingLeft;
}

void Ball::move(const float deltaTime)
{
	if (deltaTime > 0.0f)
	{
		float xDir = (goingLeft ? -1.0f : 1.0f);
		float yDir = (goingUp ? -1.0f : 1.0f);
		float cosX = static_cast<float>(cos(((percentOfDegreesDifInDecimal * maxMinDif) + minDegree) * PI / 180.0));
		float sinY = static_cast<float>(sin(((percentOfDegreesDifInDecimal * maxMinDif) + minDegree) * PI / 180.0));
		float x = xDir * speed * cosX * deltaTime;
		float y = yDir * speed * sinY * deltaTime;

		ball.move(sf::Vector2f(x, y));
	}
}

void Ball::reset()
{
	ball.setPosition(originalPosition);
	percentOfDegreesDifInDecimal = 0.0;
	randomDirection();
}