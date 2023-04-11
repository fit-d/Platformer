#include "Player.h"

Player::Player(sf::Vector2f position) {
	player.setSize(sf::Vector2f(25, 25));
	player.setFillColor(sf::Color::Black);
	player.setOutlineColor(sf::Color::Blue);
	player.setOutlineThickness(1);
	player.setPosition(position);

	sf::Vector2f velocity(sf::Vector2f(0, 0));

	jumpSpeed = 27.5f;
	speed = 15.5f;
}

void Player::move(float dt, float dir_x, float dir_y){
	this->player.move(dir_x * this->speed * dt, dir_y * speed * dt);
}

void Player::update(float dt, float groundHeight, sf::FloatRect globalBounds) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player.getGlobalBounds().intersects(globalBounds) == true) {
		if (player.getPosition().y + player.getSize().y > groundHeight) {
			velocity.y = -jumpSpeed;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) 
		velocity.x = -speed;	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) 
		velocity.x = speed;

	if (player.getGlobalBounds().intersects(globalBounds) == false) {
		if (player.getPosition().y + player.getSize().y < groundHeight) {
			velocity.y += gravity;
		}
	}
	else
		player.setPosition(player.getPosition().x, groundHeight - player.getSize().y);

	this->move(dt, velocity.x, velocity.y);
	velocity.x = 0;
}

void Player::setPosition(sf::Vector2f position) {
	this->player.setPosition(position);
}

void Player::render(sf::RenderWindow& window) {
	window.draw(this->player);
}