#include "Player.h"
#include "Constants.h"

Player::Player()
    : mIsMovingUp(false), mIsMovingLeft(false),
      mIsMovingRight(false) {}

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

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const {
    target.draw(mPlayer, states);
}
