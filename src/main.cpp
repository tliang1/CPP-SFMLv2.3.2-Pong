// main.cpp : Pong game

#include "stdafx.h"
#include "Game.h"

int main()
{
	const float width = 1600.0f;
	const float height = 900.0f;
	Game game(width, height);
	game.startGame();

	return 0;
}