#pragma once

#ifndef GHANDLER_H
#define GHANDLER_H

#include "Player.h"
#include "Platform.h"
#include "Button.h"
#include <memory>
#include <fstream>
#include <iostream>
#include <string>
#include <SFML\Graphics.hpp>
#include <SFML\Main.hpp>
#include <SFML\Audio.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Network.hpp>

class GHandler {
public:
	// constructor
	GHandler();

	// access private variables
	void run();

	void update();
	void render();
	void pollEvents();

private:
	void initVariables();
	void initWindow();

	std::unique_ptr<Player> player;

	float dt; // delta time

	std::unique_ptr<Platform> platformOne;
	
	std::unique_ptr<Button> mainMenuBtn;

	sf::Font font;
	
	sf::Text title;

	sf::Time gameTime;
	sf::Clock clock;

	std::string fpsString;
	sf::Text fpsText;

	int scene;
	bool characterInMotion;

	sf::View camera;

	std::unique_ptr<sf::RenderWindow> window;
	sf::VideoMode videoMode;
	sf::Event gmEvent;
};

#endif // GAME_H