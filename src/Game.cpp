#include "Game.h"

Game::Game()
    : mIsMovingUp(false), mIsMovingDown(false), mIsMovingLeft(false),
      mIsMovingRight(false) {
  mShape.setRadius(40.f);
  mShape.setPosition(100.f, 100.f);
  mShape.setFillColor(sf::Color::Cyan);
}

ApplicationStatus Game::processEvents(sf::Event event) {
  if (event.type == sf::Event::KeyPressed) {
    if (event.key.code == sf::Keyboard::Escape) {
      return ApplicationStatus::PAUSE;
    } else {
      handlePlayerInput(event.key.code, true);
      return ApplicationStatus::GAME;
    }
  } else if (event.type == sf::Event::KeyReleased) {
    handlePlayerInput(event.key.code, false);
    return ApplicationStatus::GAME;
  }
}

void Game::update(sf::Time timePerFrame) {
  sf::Vector2f movement(0.f, 0.f);

  if (mIsMovingUp) {
    movement.y -= 1.f;
  }
  if (mIsMovingDown) {
    movement.y += 1.f;
  }
  if (mIsMovingLeft) {
    movement.x -= 1.f;
  }
  if (mIsMovingRight) {
    movement.x += 1.f;
  }

  float speed = 50.f;
  mShape.move(movement * timePerFrame.asSeconds() * speed);
}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  target.draw(mShape, states);
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
  if (key == sf::Keyboard::W) {
    mIsMovingUp = isPressed;
  } else if (key == sf::Keyboard::S) {
    mIsMovingDown = isPressed;
  } else if (key == sf::Keyboard::A) {
    mIsMovingLeft = isPressed;
  } else if (key == sf::Keyboard::D) {
    mIsMovingRight = isPressed;
  }
}
