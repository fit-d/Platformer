#include "Platform.h"

Platform::Platform(float x, float y, sf::Vector2f size, sf::Color color) {
	platform.setSize(size);
	platform.setPosition(x, y);
	platform.setFillColor(color);
}

void Platform::setPosition(float x, float y) {
	platform.setPosition(x, y);
}

sf::Vector2f Platform::getPosition() {
	return platform.getPosition();
}

sf::FloatRect Platform::getGlobalBounds() {
	return platform.getGlobalBounds();
}

void Platform::render(sf::RenderWindow& window) {
	window.draw(this->platform);
}