#include "Player.h"

Player::Player()
    : mIsMovingUp(false), mIsMovingLeft(false),
      mIsMovingRight(false) {}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const {
    target.draw(mPlayer, states);
}
