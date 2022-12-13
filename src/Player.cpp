#include "Player.h"
#include "Constants.h"

Player::Player()
    : mIsMovingUp(false), mIsMovingDown(false), mIsMovingLeft(false),
      mIsMovingRight(false) {
    mPlayer.setPosition(100.f,
                        Constants::WINDOW_HEIGHT - Constants::PLAYER_HEIGHT);
    mPlayer.setSize({Constants::PLAYER_WIDTH, Constants::PLAYER_HEIGHT});
    mPlayer.setFillColor(sf::Color::Cyan);
}

void Player::update(sf::Time timePerFrame) {
    sf::Vector2f movement(0.f, 0.f);

    if (mIsMovingUp) {
        movement.y -= 1.f;
    }
    if (mIsMovingLeft) {
        movement.x -= 1.f;
    }
    if (mIsMovingRight) {
        movement.x += 1.f;
    }

    mPlayer.move(movement * timePerFrame.asSeconds() * Constants::PLAYER_SPEED);
}

void Player::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::W) {
        mIsMovingUp = isPressed;
    } else if (key == sf::Keyboard::A) {
        mIsMovingLeft = isPressed;
    } else if (key == sf::Keyboard::D) {
        mIsMovingRight = isPressed;
    }
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const {
    target.draw(mPlayer, states);
}
