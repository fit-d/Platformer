#include "GHandler.h"

GHandler::GHandler() {
	this->initVariables();
	this->initWindow();

	this->player.reset(new Player(sf::Vector2f(200, 550)));
	this->platformOne.reset(new Platform(200, 580, sf::Vector2f(50, 10), sf::Color::Black));
	this->mainMenuBtn.reset(new Button(sf::Vector2f(316.f, 235.f), sf::Vector2f(150.f, 50.f), 28, sf::Color::Black, this->font, "Play",
		sf::Color(0, 0, 0, 255), sf::Color(36, 36, 36, 255), sf::Color(71, 71, 71, 255)
	));

	this->camera = sf::View(sf::FloatRect(0.f, 0.f, 800.f, 600.f));
}

void GHandler::initVariables() {
	this->window = nullptr;

	characterInMotion = false;
	scene = 0;
	dt = 0.f;

	title.setFont(font);
	title.setString("Square");
	title.setPosition(330, 175);
	title.setCharacterSize(38);
	title.setFillColor(sf::Color::Black);

	if (!font.loadFromFile("roboto_font.ttf"))
		std::cout << "Font could not load" << std::endl;

	fpsText.setFont(font);
	fpsText.setFillColor(sf::Color::Black);
	fpsText.setPosition(0, 20);
	fpsText.setCharacterSize(22);
}

void GHandler::pollEvents() {
	while (this->window->pollEvent(this->gmEvent)) {
		switch (this->gmEvent.type) {
			case sf::Event::Closed:
				this->window->close();
				break;
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					this->window->close();
				break;
		}
	}
}


void GHandler::initWindow() {
	// setting up the height and width of the screen
	this->videoMode.height = 600;
	this->videoMode.width = 800;

	// redefining it to make it into a window
	this->window.reset(new sf::RenderWindow(this->videoMode, "Test Title", sf::Style::Titlebar | sf::Style::Close));
}

void GHandler::render() {
	this->window->clear(sf::Color(255, 255, 255, 255)); // clears the frame before it

	window->draw(fpsText);

	switch (scene) {
		case 0:
			this->mainMenuBtn->render(*window);
			window->draw(title);
			break;
		case 1:
			this->player->render(*window);
			this->platformOne->render(*window);
			break;
	}

	window->display();
}

void GHandler::update() {
	this->pollEvents();

	dt = this->clock.getElapsedTime().asSeconds(); // get the delta time

	sf::Vector2i mousePos = sf::Mouse::getPosition(*window);
	sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));

	switch (scene) {
	case 0:
		this->mainMenuBtn->update(mousePosF);
		if (this->mainMenuBtn->checkButtonState() == BTN_PRESSED) {
			scene = 1;
			characterInMotion = true;
		}
		break;
	}

	switch (characterInMotion) {
	case true:
		this->player->update(dt, platformOne->getPosition().y, platformOne->getGlobalBounds());
		break;
	default:
		break;
	}

	this->window->setFramerateLimit(60);
	this->gameTime = this->clock.getElapsedTime();

	fpsString = std::to_string(static_cast<int>(1.0f / gameTime.asSeconds()));
	fpsText.setString(fpsString);
	//fpsText.setPosition(this->player->playerHitbox->hitBox.getPosition().x + 17, this->player->playerHitbox->hitBox.getPosition().y - 17);
	fpsText.setPosition(camera.getCenter().x - 400, camera.getCenter().y - 305);
	this->clock.restart().asSeconds();
}

void GHandler::run() {
	while (this->window->isOpen()) {
		this->update();
		this->render();
	}
}