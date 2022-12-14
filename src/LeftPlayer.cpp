#include "LeftPlayer.h"
#include "Constants.h"

LeftPlayer::LeftPlayer() {
    mPlayer.setPosition(Constants::PLAYER_STARTING_POSITION_FROM_FRAME,
                        Constants::WINDOW_HEIGHT - Constants::PLAYER_HEIGHT);
    mPlayer.setSize({Constants::PLAYER_WIDTH, Constants::PLAYER_HEIGHT});
    mPlayer.setFillColor(sf::Color::Blue);
}

void LeftPlayer::update(sf::Time timePerFrame) {
    Player::update(timePerFrame);
    AlignLeftIfNecessary();
    AlignRightIfNecessary();
}

void LeftPlayer::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::W) {
        mIsMovingUp = isPressed;
    } else if (key == sf::Keyboard::A) {
        mIsMovingLeft = isPressed;
    } else if (key == sf::Keyboard::D) {
        mIsMovingRight = isPressed;
    }
}

void LeftPlayer::AlignLeftIfNecessary() {
    constexpr float border = 0.f;

    if (mPlayer.getPosition().x < border) {
        mPlayer.setPosition(border, mPlayer.getPosition().y);
    }
}

void LeftPlayer::AlignRightIfNecessary() {
    constexpr float border =
        (Constants::WINDOW_WIDTH - Constants::NET_WIDTH) / 2.f
            - Constants::PLAYER_WIDTH;

    if (border < mPlayer.getPosition().x) {
        mPlayer.setPosition(border, mPlayer.getPosition().y);
    }
}
