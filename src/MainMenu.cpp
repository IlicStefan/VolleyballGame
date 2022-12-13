#include "MainMenu.h"
#include "Configuration.h"
#include "Constants.h"
#include "Textures.h"

MainMenu::MainMenu()
    : mBackground(Configuration::textures.get(Textures::BACKGROUND_MAIN_MENU)),
      mStartButton({Constants::BUTTON_MARGIN, Constants::BUTTON_MARGIN},
                   {Constants::BUTTON_WIDTH, Constants::BUTTON_HEIGHT},
                   "START"),
      mQuitButton({Constants::BUTTON_MARGIN,
                   Constants::BUTTON_HEIGHT
                       + 2 * Constants::BUTTON_MARGIN},
                  {Constants::BUTTON_WIDTH,
                   Constants::BUTTON_HEIGHT},
                  "QUIT") {
    mBackground.setScale(
        float(Constants::WINDOW_WIDTH) / mBackground.getGlobalBounds().width,
        float(Constants::WINDOW_HEIGHT) / mBackground.getGlobalBounds().height);
    focusStart();
}

ApplicationStatus MainMenu::processEvents(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            focusStart();
        } else if (event.key.code == sf::Keyboard::Down) {
            focusQuit();
        } else if (event.key.code == sf::Keyboard::Enter) {
            if (mFocusedButton == FocusedButton::START) {
                return ApplicationStatus::GAME;
            } else if (mFocusedButton == FocusedButton::QUIT) {
                return ApplicationStatus::EXIT;
            }
        }
    }

    return ApplicationStatus::MAIN_MENU;
}

void MainMenu::update(sf::Time timePerFrame) {}

void MainMenu::draw(sf::RenderTarget & target, sf::RenderStates states) const {
    target.draw(mBackground, states);
    target.draw(mStartButton, states);
    target.draw(mQuitButton, states);
}

void MainMenu::focusStart() {
    mStartButton.focus(true);
    mQuitButton.focus(false);
    mFocusedButton = FocusedButton::START;
}

void MainMenu::focusQuit() {
    mStartButton.focus(false);
    mQuitButton.focus(true);
    mFocusedButton = FocusedButton::QUIT;
}
