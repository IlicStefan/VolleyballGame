#include "Game.h"
#include "Configuration.h"
#include "Constants.h"

Game::Game()
    : mBackground(Configuration::textures.get(Textures::BACKGROUND_GAME)),
      mNet(), mLeftPlayer(), mRightPlayer(), mBall() {
    mBackground.setScale(
        float(Constants::WINDOW_WIDTH) / mBackground.getGlobalBounds().width,
        float(Constants::WINDOW_HEIGHT) / mBackground.getGlobalBounds().height);
}

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
    mBall.update(timePerFrame, mLeftPlayer, mRightPlayer, mNet);
}

void Game::draw(sf::RenderTarget & target, sf::RenderStates states) const {
    target.draw(mBackground, states);
    target.draw(mLeftPlayer, states);
    target.draw(mRightPlayer, states);
    target.draw(mBall, states);
    target.draw(mNet, states);
}
