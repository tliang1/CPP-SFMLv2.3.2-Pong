#ifndef GAME_H
#define GAME_H

#include "Ball.h"
#include "CollisionManager.h"
#include "Paddle.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

/// <summary>
/// Game class for creating the pong game.
/// </summary>
class Game
{
private:
	float width, height;

	sf::Font font;
	unsigned int fontSize;

	std::vector<sf::Text> menu;
	std::vector<sf::Text> howToPlayMenu;
	std::vector<sf::Text> playerWinMenu;
	std::vector<sf::Text> cpuWinMenu;
	std::vector<sf::Text> gameOverMenu;

	std::vector<sf::RectangleShape> background;

	std::vector<sf::Text> scoreLabels;
	sf::Text playerScoreText;
	sf::Text cpuScoreText;

	// Score difference between the player and the cpu for one of them to win.
	const unsigned int scoreDifferenceForWin = 5;

	Paddle player;
	Paddle cpu;

	Ball ball;

	CollisionManager collisionManager = CollisionManager();

	void createMainMenu();
	void createHowToPlayMenu();
	void createPlayerWinMenu();
	void createCpuWinMenu();
	void createGameOverMenu();

	void createGameBackground();

	void createScoreLabels();

	void nextRound(Paddle &player, Paddle &cpu, Ball &ball);
public:
	Game(const float screenWidth, const float screenHeight);

	void startGame();
};

#endif