#pragma once

#ifndef PLATFORM_H
#define PLATFORM_H

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

class Platform {
public:
	Platform(float x, float y, sf::Vector2f size, sf::Color color);

	void setPosition(float x, float y);
	void render(sf::RenderWindow& window);
	sf::Vector2f getPosition();
	sf::FloatRect getGlobalBounds();

private:
	sf::RectangleShape platform;
};

#endif