#include "Game.h"

Game::Game()
    : mNet(), mLeftPlayer(), mRightPlayer(), mBall() {}

ApplicationStatus Game::processEvents(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) {
            return ApplicationStatus::PAUSE;
        }
        mLeftPlayer.handlePlayerInput(event.key.code, true);
        mRightPlayer.handlePlayerInput(event.key.code, true);
    } else if (event.type == sf::Event::KeyReleased) {
        mLeftPlayer.handlePlayerInput(event.key.code, false);
        mRightPlayer.handlePlayerInput(event.key.code, false);
    }

    return ApplicationStatus::GAME;
}

void Game::update(sf::Time timePerFrame) {
    mLeftPlayer.update(timePerFrame);
    mRightPlayer.update(timePerFrame);
}

void Game::draw(sf::RenderTarget & target, sf::RenderStates states) const {
    target.draw(mBackground, states);
    target.draw(mLeftPlayer, states);
    target.draw(mRightPlayer, states);
    target.draw(mBall, states);
    target.draw(mNet, states);
}
