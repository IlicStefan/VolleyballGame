#include "RightPlayer.h"
#include "Constants.h"

RightPlayer::RightPlayer() {
    mPlayer.setPosition(Constants::WINDOW_WIDTH - Constants::PLAYER_WIDTH
                            - Constants::PLAYER_STARTING_POSITION_FROM_FRAME,
                        Constants::WINDOW_HEIGHT - Constants::PLAYER_HEIGHT);
    mPlayer.setSize({Constants::PLAYER_WIDTH, Constants::PLAYER_HEIGHT});
    mPlayer.setFillColor(sf::Color::Red);
}

void RightPlayer::update(sf::Time timePerFrame) {
    Player::update(timePerFrame);
    alignLeftIfNecessary();
    alignRightIfNecessary();
}

void RightPlayer::handlePlayerInput(sf::Keyboard::Key key, bool isPressed) {
    if (key == sf::Keyboard::Up) {
        mIsMovingUp = isPressed;
    } else if (key == sf::Keyboard::Left) {
        mIsMovingLeft = isPressed;
    } else if (key == sf::Keyboard::Right) {
        mIsMovingRight = isPressed;
    }
}

void RightPlayer::alignLeftIfNecessary() {
    constexpr float
        border = (Constants::WINDOW_WIDTH + Constants::NET_WIDTH) / 2.f;

    if (mPlayer.getPosition().x < border) {
        mPlayer.setPosition(border, mPlayer.getPosition().y);
    }
}

void RightPlayer::alignRightIfNecessary() {
    constexpr float border = Constants::WINDOW_WIDTH - Constants::PLAYER_WIDTH;

    if (border < mPlayer.getPosition().x) {
        mPlayer.setPosition(border, mPlayer.getPosition().y);
    }
}
