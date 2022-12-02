#include "Application.h"

Application::Application()
    : mWindow(sf::VideoMode(640, 480), "Volleyball Game"), mShape() {
  mWindow.setVerticalSyncEnabled(true);
  mShape.setRadius(40.f);
  mShape.setPosition(100.f, 100.f);
  mShape.setFillColor(sf::Color::Green);
}

void Application::run(unsigned minimumFramePerSeconds) {
  sf::Clock clock;
  sf::Time timeSinceLastUpdate = sf::Time::Zero;
  const sf::Time timePerFrame = sf::seconds(1.f / minimumFramePerSeconds);

  while (mWindow.isOpen()) {
    processEvents();
    timeSinceLastUpdate += clock.restart();

    while (timeSinceLastUpdate > timePerFrame) {
      timeSinceLastUpdate -= timePerFrame;
      update(timePerFrame);
    }
    update(timeSinceLastUpdate);

    display();
  }
}

void Application::processEvents() {
  sf::Event event;

  while (mWindow.pollEvent(event)) {
    switch (event.type) {
    case sf::Event::KeyPressed:
      handlePlayerInput(event.key.code, true);
      break;
    case sf::Event::KeyReleased:
      handlePlayerInput(event.key.code, false);
      break;
    case sf::Event::Closed:
      mWindow.close();
      break;
    }
  }
}

void Application::update(sf::Time timePerFrame) {
  sf::Vector2f movement(0.f, 0.f);

  if (mIsMovingUp) {
    movement.y -= 10.f;
  }
  if (mIsMovingDown) {
    movement.y += 10.f;
  }
  if (mIsMovingLeft) {
    movement.x -= 10.f;
  }
  if (mIsMovingRight) {
    movement.x += 10.f;
  }

  mShape.move(movement * timePerFrame.asSeconds());
}

void Application::display() {
  mWindow.clear();
  mWindow.draw(mShape);
  mWindow.display();
}

void Application::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
  if (key == sf::Keyboard::W)
    mIsMovingUp = isPressed;
  if (key == sf::Keyboard::S)
    mIsMovingDown = isPressed;
  if (key == sf::Keyboard::A)
    mIsMovingLeft = isPressed;
  if (key == sf::Keyboard::D)
    mIsMovingRight = isPressed;
}
