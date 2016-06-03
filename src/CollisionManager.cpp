#include "CollisionManager.h"

bool CollisionManager::isCollision(Ball &ball, const Paddle &paddle)
{
	float paddleXMin = paddle.getPaddle().getPosition().x;
	float paddleXMax = paddleXMin + (paddle.getPaddle().getLocalBounds().width / 2.0f);
	float paddleYMin = paddle.getPaddle().getPosition().y - (paddle.getPaddle().getLocalBounds().height / 2.0f);
	float paddleYMax = paddleYMin + paddle.getPaddle().getLocalBounds().height;

	// For CPU paddle only
	if (!paddle.isCollisionRight())
	{
		paddleXMin = paddle.getPaddle().getPosition().x - (paddle.getPaddle().getLocalBounds().width / 2.0f);
		paddleXMax = paddle.getPaddle().getPosition().x;
	}

	float ballX = ball.getBall().getPosition().x;
	float ballY = ball.getBall().getPosition().y;

	if ((ballX >= paddleXMin) && (ballX <= paddleXMax) && (ballY >= paddleYMin) && (ballY <= paddleYMax))
	{
		float midPaddleY = paddle.getPaddle().getPosition().y;
		if (ballY < midPaddleY)
		{
			ball.setPercentOfDegreesDifInDecimal(static_cast<double>(((midPaddleY - ballY) / (midPaddleY - paddleYMin))));
		}
		else if (ballY > midPaddleY)
		{
			ball.setPercentOfDegreesDifInDecimal(static_cast<double>(((ballY - midPaddleY) / (paddleYMax - midPaddleY))));
		}
		else
		{
			ball.setPercentOfDegreesDifInDecimal(0.0);
		}
		return true;
	}
	return false;
}