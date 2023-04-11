#ifndef BUTTON_H
#define BUTTON_H

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

// if the button is getting hovered over, etc
enum button_states { BTN_IDLE = 0, BTN_HOVER, BTN_PRESSED };

class Button {
private:
	short unsigned buttonState; // get the button stat

	// button stuff
	sf::RectangleShape button;
	sf::Font font;
	sf::Text text;

	sf::Color idleColor;
	sf::Color activeColor;
	sf::Color hoverColor;

public:
	Button(sf::Vector2f position, sf::Vector2f size, int fontSize, sf::Color color, sf::Font font, std::string Text, sf::Color idleColor, sf::Color activeColor, sf::Color hoverColor);

	// Accessors
	const bool isPressed() const; // mouse pressed?

	// Functions
	void update(const sf::Vector2f mousePos); // mousePos for getting the mouse position
	void render(sf::RenderWindow& window); // get the render window
	void setPosition(sf::Vector2f position);
	short unsigned checkButtonState(); // get button state
};

#endif BUTTON_H