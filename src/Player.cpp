#include "Player.h"
#include "Constants.h"

Player::Player()
    : mIsMovingUp(false), mIsMovingLeft(false),
      mIsMovingRight(false), mJumpVelocity(0.f), mOnGround(true) {}

sf::CircleShape Player::getHead() const {
    sf::CircleShape result;
    result.setRadius(Constants::PLAYER_WIDTH);
    result.setPosition(mPlayer.getPosition());

    return result;
}

void Player::update(sf::Time timePerFrame) {
    sf::Vector2f movement(0.f, mJumpVelocity);

    if (mIsMovingUp and mOnGround) {
        mJumpVelocity = Constants::PLAYER_JUMP_VELOCITY;
        mOnGround = false;
    }
    if (mIsMovingLeft) {
        movement.x -= 1.f;
    }
    if (mIsMovingRight) {
        movement.x += 1.f;
    }

    mPlayer.move(movement * timePerFrame.asSeconds() * Constants::GAME_SPEED);
    alignDownIfNecessary();
    mJumpVelocity += Constants::PLAYER_GRAVITY * timePerFrame.asSeconds();
}

void Player::alignDownIfNecessary() {
    constexpr float
        border = Constants::WINDOW_HEIGHT - Constants::PLAYER_HEIGHT;

    if (border < mPlayer.getPosition().y) {
        mPlayer.setPosition(mPlayer.getPosition().x, border);
        mOnGround = true;
    }
}

void Player::draw(sf::RenderTarget & target, sf::RenderStates states) const {
    target.draw(mPlayer, states);
}
