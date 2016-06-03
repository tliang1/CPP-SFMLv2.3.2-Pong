#include "Game.h"
#include <stdlib.h>

void Game::createMainMenu()
{
	sf::Text gameTitle(std::string("Pong"), font, fontSize);
	gameTitle.setStyle(sf::Text::Bold);
	gameTitle.setColor(sf::Color::Black);
	gameTitle.setOrigin(gameTitle.getGlobalBounds().width / 2.0f, gameTitle.getGlobalBounds().height / 2.0f);
	gameTitle.setPosition(width / 2.0f, height * 0.125f);

	sf::Text gameCreatorName(std::string("By Tony Liang"), font, fontSize);
	gameCreatorName.setStyle(sf::Text::Bold);
	gameCreatorName.setColor(sf::Color::Black);
	gameCreatorName.setOrigin(gameCreatorName.getGlobalBounds().width / 2.0f, gameCreatorName.getGlobalBounds().height / 2.0f);
	gameCreatorName.setPosition(width / 2.0f, height * 0.25f);

	sf::Text mainMenuDescription(std::string("Press H for help"), font, fontSize);
	mainMenuDescription.setStyle(sf::Text::Bold);
	mainMenuDescription.setColor(sf::Color::Black);
	mainMenuDescription.setOrigin(mainMenuDescription.getGlobalBounds().width / 2.0f, mainMenuDescription.getGlobalBounds().height / 2.0f);
	mainMenuDescription.setPosition(width / 2.0f, height * 0.625f);

	sf::Text mainMenuDescription2(std::string("Press any other key to play"), font, fontSize);
	mainMenuDescription2.setStyle(sf::Text::Bold);
	mainMenuDescription2.setColor(sf::Color::Black);
	mainMenuDescription2.setOrigin(mainMenuDescription2.getGlobalBounds().width / 2.0f, mainMenuDescription2.getGlobalBounds().height / 2.0f);
	mainMenuDescription2.setPosition(width / 2.0f, height * 0.75f);

	menu.push_back(gameTitle);
	menu.push_back(gameCreatorName);
	menu.push_back(mainMenuDescription);
	menu.push_back(mainMenuDescription2);
}

void Game::createHowToPlayMenu()
{
	sf::Text howToPlayTitle(std::string("How To Play"), font, fontSize);
	howToPlayTitle.setStyle(sf::Text::Bold);
	howToPlayTitle.setColor(sf::Color::Black);
	howToPlayTitle.setOrigin(howToPlayTitle.getGlobalBounds().width / 2.0f, howToPlayTitle.getGlobalBounds().height / 2.0f);
	howToPlayTitle.setPosition(width / 2.0f, height * 0.125f);

	sf::Text instructions(std::string("W/S or Up/Down keys to move paddle."), font, fontSize);
	instructions.setStyle(sf::Text::Bold);
	instructions.setColor(sf::Color::Black);
	instructions.setOrigin(instructions.getGlobalBounds().width / 2.0f, instructions.getGlobalBounds().height / 2.0f);
	instructions.setPosition(width / 2.0f, height * 0.25f);

	sf::Text instructions2(std::string("First one to get five more points than the opponent wins."), font, fontSize);
	instructions2.setStyle(sf::Text::Bold);
	instructions2.setColor(sf::Color::Black);
	instructions2.setOrigin(instructions2.getGlobalBounds().width / 2.0f, instructions2.getGlobalBounds().height / 2.0f);
	instructions2.setPosition(width / 2.0f, height * 0.375f);

	sf::Text instructions3(std::string("Press any key to return to the main menu."), font, fontSize);
	instructions3.setStyle(sf::Text::Bold);
	instructions3.setColor(sf::Color::Black);
	instructions3.setOrigin(instructions3.getGlobalBounds().width / 2.0f, instructions3.getGlobalBounds().height / 2.0f);
	instructions3.setPosition(width / 2.0f, height * 0.75f);

	howToPlayMenu.push_back(howToPlayTitle);
	howToPlayMenu.push_back(instructions);
	howToPlayMenu.push_back(instructions2);
	howToPlayMenu.push_back(instructions3);
}

void Game::createPlayerWinMenu()
{
	sf::Text playerWinTitle(std::string("Player Wins!"), font, fontSize);
	playerWinTitle.setStyle(sf::Text::Bold);
	playerWinTitle.setColor(sf::Color::Black);
	playerWinTitle.setOrigin(playerWinTitle.getGlobalBounds().width / 2.0f, playerWinTitle.getGlobalBounds().height / 2.0f);
	playerWinTitle.setPosition(width / 2.0f, height * 0.125f);

	sf::Text instructions(std::string("Press any key to continue"), font, fontSize);
	instructions.setStyle(sf::Text::Bold);
	instructions.setColor(sf::Color::Black);
	instructions.setOrigin(instructions.getGlobalBounds().width / 2.0f, instructions.getGlobalBounds().height / 2.0f);
	instructions.setPosition(width / 2.0f, height * 0.75f);

	playerWinMenu.push_back(playerWinTitle);
	playerWinMenu.push_back(instructions);
}

void Game::createCpuWinMenu()
{
	sf::Text cpuWinTitle(std::string("CPU Wins!"), font, fontSize);
	cpuWinTitle.setStyle(sf::Text::Bold);
	cpuWinTitle.setColor(sf::Color::Black);
	cpuWinTitle.setOrigin(cpuWinTitle.getGlobalBounds().width / 2.0f, cpuWinTitle.getGlobalBounds().height / 2.0f);
	cpuWinTitle.setPosition(width / 2.0f, height * 0.125f);

	sf::Text instructions(std::string("Press any key to continue"), font, fontSize);
	instructions.setStyle(sf::Text::Bold);
	instructions.setColor(sf::Color::Black);
	instructions.setOrigin(instructions.getGlobalBounds().width / 2.0f, instructions.getGlobalBounds().height / 2.0f);
	instructions.setPosition(width / 2.0f, height * 0.75f);

	cpuWinMenu.push_back(cpuWinTitle);
	cpuWinMenu.push_back(instructions);
}

void Game::createGameOverMenu()
{
	sf::Text gameOverTitle(std::string("Game Over!"), font, fontSize);
	gameOverTitle.setStyle(sf::Text::Bold);
	gameOverTitle.setColor(sf::Color::Black);
	gameOverTitle.setOrigin(gameOverTitle.getGlobalBounds().width / 2.0f, gameOverTitle.getGlobalBounds().height / 2.0f);
	gameOverTitle.setPosition(width / 2.0f, height * 0.125f);

	sf::Text instructions(std::string("Press any key to continue"), font, fontSize);
	instructions.setStyle(sf::Text::Bold);
	instructions.setColor(sf::Color::Black);
	instructions.setOrigin(instructions.getGlobalBounds().width / 2.0f, instructions.getGlobalBounds().height / 2.0f);
	instructions.setPosition(width / 2.0f, height * 0.75f);

	gameOverMenu.push_back(gameOverTitle);
	gameOverMenu.push_back(instructions);
}

void Game::createGameBackground()
{
	const float borderSize = 2.0f;
	sf::RectangleShape topLine(sf::Vector2f(width, borderSize));
	topLine.setFillColor(sf::Color::Black);

	sf::RectangleShape bottomLine(sf::Vector2f(width, borderSize));
	bottomLine.setPosition(sf::Vector2f(0.0f, height - borderSize));
	bottomLine.setFillColor(sf::Color::Black);

	sf::RectangleShape leftLine(sf::Vector2f(borderSize, height));
	leftLine.setFillColor(sf::Color::Black);

	sf::RectangleShape rightLine(sf::Vector2f(borderSize, height));
	rightLine.setPosition(sf::Vector2f(width - borderSize, 0.0f));
	rightLine.setFillColor(sf::Color::Black);

	sf::RectangleShape centerLine(sf::Vector2f(borderSize, height));
	centerLine.setPosition(sf::Vector2f((width / 2.0f) - (borderSize / 2.0f), 0.0f));
	centerLine.setFillColor(sf::Color::Black);

	background.push_back(topLine);
	background.push_back(bottomLine);
	background.push_back(leftLine);
	background.push_back(rightLine);
	background.push_back(centerLine);
}

void Game::createScoreLabels()
{
	sf::Text playerScoreLabel(std::string("Player"), font, fontSize);
	playerScoreLabel.setStyle(sf::Text::Bold);
	playerScoreLabel.setColor(sf::Color::Black);
	playerScoreLabel.setOrigin(playerScoreLabel.getLocalBounds().width / 2.0f, playerScoreLabel.getLocalBounds().height / 2.0f);
	playerScoreLabel.setPosition(sf::Vector2f(width / 4.0f, height / 45.0f));

	playerScoreText.setString(std::string("0"));
	playerScoreText.setFont(font);
	playerScoreText.setCharacterSize(fontSize);
	playerScoreText.setStyle(sf::Text::Bold);
	playerScoreText.setColor(sf::Color::Black);
	playerScoreText.setOrigin(playerScoreText.getLocalBounds().width / 2.0f, playerScoreText.getLocalBounds().height / 2.0f);
	playerScoreText.setPosition(sf::Vector2f(width / 4.0f, height * 4.0f / 45.0f));

	sf::Text cpuScoreLabel(std::string("CPU"), font, fontSize);
	cpuScoreLabel.setStyle(sf::Text::Bold);
	cpuScoreLabel.setColor(sf::Color::Black);
	cpuScoreLabel.setOrigin(cpuScoreLabel.getLocalBounds().width / 2.0f, cpuScoreLabel.getLocalBounds().height / 2.0f);
	cpuScoreLabel.setPosition(sf::Vector2f(width * 0.75f, height / 45.0f));

	cpuScoreText.setString(std::string("0"));
	cpuScoreText.setFont(font);
	cpuScoreText.setCharacterSize(fontSize);
	cpuScoreText.setStyle(sf::Text::Bold);
	cpuScoreText.setColor(sf::Color::Black);
	cpuScoreText.setOrigin(cpuScoreText.getLocalBounds().width / 2.0f, cpuScoreText.getLocalBounds().height / 2.0f);
	cpuScoreText.setPosition(sf::Vector2f(width * 0.75f, height * 4.0f / 45.0f));

	scoreLabels.push_back(playerScoreLabel);
	scoreLabels.push_back(cpuScoreLabel);
}

void Game::nextRound(Paddle &player, Paddle &cpu, Ball &ball)
{
	player.reset();
	cpu.reset();
	ball.reset();
}

Game::Game(const float screenWidth, const float screenHeight): width(screenWidth), height(screenHeight)
{
	font.loadFromFile("Fonts/TooneyNoodleNF.ttf");
	fontSize = static_cast<unsigned int>(25.0f * width / height);

	createMainMenu();
	createHowToPlayMenu();
	createPlayerWinMenu();
	createCpuWinMenu();
	createGameOverMenu();

	createGameBackground();

	// Create player and cpu paddles
	const int paddleWidth = static_cast<int>(width * (3.0f / 200.0f));
	const int paddleHeight = static_cast<int>(height * (16.0f / 75.0f));
	player = Paddle(paddleWidth, paddleHeight, sf::Vector2f(25.0f, height / 2.0f), static_cast<int>(height * 0.75f), true, 0, 
		static_cast<int>(height));

	const float cpuOffsetX = static_cast<float>(width - paddleWidth - 25.0f);
	cpu = Paddle(paddleWidth, paddleHeight, sf::Vector2f(cpuOffsetX, height / 2.0f), static_cast<int>(height * 0.7f), false, 0, 
		static_cast<int>(height));

	// Create ball
	const int ballRadius = static_cast<int>(height / 90.0f);
	ball = Ball(ballRadius, sf::Vector2f(width / 2.0f, height / 2.0f), static_cast<int>(width * 0.625f));

	// Create player and cpu labels and texts
	createScoreLabels();
}

void Game::startGame()
{
	using namespace sf;

	RenderWindow window(VideoMode(static_cast<int>(width), static_cast<int>(height)), "Pong", Style::Fullscreen);
	window.setFramerateLimit(60);

	bool isMainMenu = true, isHowToPlayMenu = false, isRoundWinMenu = false, isGameOverMenu = false;

	bool isPlaying = false;

	bool isWin = false, isPlayerWin = false, isGameOver = false;

	int playerScore = 0, cpuScore = 0;

	Clock clock;

	while (window.isOpen())
	{
		Event event;

		// Record deltatime every frame
		float dt = clock.restart().asSeconds();

		while (window.pollEvent(event))
		{
			// Exit the game
			if ((event.type == Event::Closed) || Keyboard::isKeyPressed(Keyboard::Escape))
			{
				window.close();
			}

			// Start the game
			else if (event.type == Event::KeyPressed)
			{
				if (isMainMenu)
				{
					isMainMenu = false;
					isHowToPlayMenu = false;
					isRoundWinMenu = false;
					isGameOverMenu = false;
					isPlaying = false;
					isWin = false;
					isPlayerWin = false;
					isGameOver = false;

					if (Keyboard::isKeyPressed(Keyboard::H))
					{
						isHowToPlayMenu = true;
					}
					else
					{
						isPlaying = true;
					}
				}
				else if (isHowToPlayMenu)
				{
					isHowToPlayMenu = false;
					isMainMenu = true;
				}
				else
				{
					if (isRoundWinMenu)
					{
						isRoundWinMenu = false;
						if (!isGameOver)
						{
							isPlaying = true;
						}
					}
					else if (isGameOverMenu)
					{
						isGameOverMenu = false;
						isMainMenu = true;
						isPlaying = false;
						isGameOver = false;
					}

					isWin = false;
					isPlayerWin = false;
				}
			}
		}

		// Use up and down arrow keys or W and S keys for paddle movement
		if (isPlaying && (Keyboard::isKeyPressed(Keyboard::Up) || Keyboard::isKeyPressed(Keyboard::W)))
		{
			player.move(dt, true);
		}

		if (isPlaying && (Keyboard::isKeyPressed(Keyboard::Down) || Keyboard::isKeyPressed(Keyboard::S)))
		{
			player.move(dt, false);
		}

		if (isPlaying)
		{
			ball.move(dt);

			// Reflect ball left or right when collided with a paddle
			if (!ball.isLeft())
			{
				if (collisionManager.isCollision(ball, cpu))
					ball.toggleHorizontalDirection();
			}
			else
			{
				if (collisionManager.isCollision(ball, player))
					ball.toggleHorizontalDirection();
			}

			// Reflect ball up or down when collided with top or bottom walls
			if ((ball.getBall().getPosition().y < ball.getBall().getRadius()) || ball.getBall().getPosition().y > (height - ball.getBall().getRadius()))
			{
				ball.wallCollision(height / 2.0f);
			}

			// Score player or cpu and go to next round until game is over
			if (ball.getBall().getPosition().x < 1)
			{
				++cpuScore;
				cpuScoreText.setString(std::to_string(cpuScore));
				cpuScoreText.setOrigin(cpuScoreText.getLocalBounds().width / 2.0f, cpuScoreText.getLocalBounds().height / 2.0f);
				cpuScoreText.setPosition(width * 0.75f, cpuScoreText.getPosition().y);

				isPlaying = false;
				isWin = true;
				isPlayerWin = false;
				isRoundWinMenu = true;
				if (static_cast<unsigned int>(abs(cpuScore - playerScore)) >= scoreDifferenceForWin)
				{
					isGameOver = true;
					isGameOverMenu = true;
					playerScore = 0;
					cpuScore = 0;
				}
			}
			else if (ball.getBall().getPosition().x > width)
			{
				++playerScore;
				playerScoreText.setString(std::to_string(playerScore));
				playerScoreText.setOrigin(playerScoreText.getLocalBounds().width / 2.0f, playerScoreText.getLocalBounds().height / 2.0f);
				playerScoreText.setPosition(width / 4.0f, playerScoreText.getPosition().y);

				isPlaying = false;
				isWin = true;
				isPlayerWin = true;
				isRoundWinMenu = true;
				if (static_cast<unsigned int>(abs(playerScore - cpuScore)) >= scoreDifferenceForWin)
				{
					isGameOver = true;
					isGameOverMenu = true;
					playerScore = 0;
					cpuScore = 0;
				}
			}

			// CPU follows ball's y direction if the ball is heading the right direction
			if (!ball.isLeft())
			{
				if (ball.getBall().getPosition().y < cpu.getPaddle().getPosition().y)
				{
					cpu.move(dt, true);
				}
				else
				{
					cpu.move(dt, false);
				}
			}

			// CPU goes back to the middle
			else
			{
				if ((cpu.getPaddle().getPosition().y < ((height / 2.0f) - (cpu.getPaddle().getLocalBounds().height / 10.0f))) || 
					(cpu.getPaddle().getPosition().y > ((height / 2.0f) + (cpu.getPaddle().getLocalBounds().height / 10.0f))))
				{
					if (cpu.getPaddle().getPosition().y > (height / 2.0f))
					{
						cpu.move(dt, true);
					}
					else
					{
						cpu.move(dt, false);
					}
				}
			}
		}

		// Draw the game
		window.clear(Color(200, 200, 200, 255));

		if (!isPlaying)
		{
			// Round win
			if (isWin)
			{
				if (isPlayerWin)
				{
					for (sf::Text text : playerWinMenu)
						window.draw(text);
				}
				else
				{
					for (sf::Text text : cpuWinMenu)
						window.draw(text);
				}

				nextRound(player, cpu, ball);
			}

			// Game over
			else if (isGameOver)
			{
				for (sf::Text text : gameOverMenu)
					window.draw(text);

				nextRound(player, cpu, ball);
			}

			// How to play menu
			else if (isHowToPlayMenu)
			{
				for (sf::Text text : howToPlayMenu)
					window.draw(text);
			}

			// Main menu
			else
			{
				for (sf::Text text : menu)
					window.draw(text);
			}
		}
		else
		{
			for (sf::RectangleShape rectangle : background)
				window.draw(rectangle);

			window.draw(player.getPaddle());
			window.draw(cpu.getPaddle());
			window.draw(ball.getBall());

			for (sf::Text text : scoreLabels)
				window.draw(text);

			window.draw(playerScoreText);
			window.draw(cpuScoreText);
		}

		window.display();
	}
}