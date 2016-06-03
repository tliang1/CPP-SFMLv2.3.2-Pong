#ifndef COLLISIONMANAGER_H
#define COLLISIONMANAGER_H

#include <SFML/Graphics.hpp>
#include "Ball.h"
#include "Paddle.h"

/// <summary>
/// Collision Manager class for collision detections between a ball and a paddle.
/// </summary>
class CollisionManager
{
public:
	CollisionManager() {}

	/// <summary>
	/// If there is a collision between the ball and the paddle, the ball needs to bounce away in the opposite direction. The percentage of the minimum 
	/// degree in decimal that the ball travels must be recalculated.
	/// </summary>
	/// <returns>
	/// Returns if there is a collision between the ball and the paddle.
	/// </returns>
	bool isCollision(Ball &ball, const Paddle &paddle);
};

#endif