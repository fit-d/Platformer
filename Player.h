#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include <fstream>
#include <iostream>
#include <string>
#include "Platform.h"
#include <SFML\Graphics.hpp>
#include <SFML\Main.hpp>
#include <SFML\Audio.hpp>
#include <SFML\System.hpp>
#include <SFML\Window.hpp>
#include <SFML\Network.hpp>

class Player {
public:
	Player(sf::Vector2f position);

	void move(float dt, float dir_x, float dir_y);
	void update(float dt, float groundHeight, sf::FloatRect globalBounds);
	void setPosition(sf::Vector2f position);
	void render(sf::RenderWindow& window);

private:
	sf::RectangleShape player;

	const float gravity = 1;
	sf::Vector2f velocity;

	float jumpSpeed;
	float speed;
};

#endif