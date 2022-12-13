#include "Game.h"

Game::Game()
    : mNet(), mPlayer(), mBall() {}

ApplicationStatus Game::processEvents(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Escape) {
            return ApplicationStatus::PAUSE;
        }
        mPlayer.handlePlayerInput(event.key.code, true);
    } else if (event.type == sf::Event::KeyReleased) {
        mPlayer.handlePlayerInput(event.key.code, false);
    }

    return ApplicationStatus::GAME;
}

void Game::update(sf::Time timePerFrame) {
    mPlayer.update(timePerFrame);
}

void Game::draw(sf::RenderTarget & target, sf::RenderStates states) const {
    target.draw(mBackground, states);
    target.draw(mPlayer, states);
    target.draw(mBall, states);
    target.draw(mNet, states);
}
