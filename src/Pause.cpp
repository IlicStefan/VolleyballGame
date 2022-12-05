#include "Pause.h"
#include "Constants.h"

Pause::Pause()
    : mResumeButton(
    {
        float(Constants::WINDOW_WIDTH) / 2 - Constants::BUTTON_WIDTH / 2,
        float(Constants::WINDOW_HEIGHT) / 2 - Constants::BUTTON_HEIGHT
            - Constants::BUTTON_MARGIN / 2
    },
    {
        Constants::BUTTON_WIDTH,
        Constants::BUTTON_HEIGHT
    },
    "RESUME"
),
      mExitButton(
          {
              float(Constants::WINDOW_WIDTH) / 2 - Constants::BUTTON_WIDTH / 2,
              float(Constants::WINDOW_HEIGHT) / 2 + Constants::BUTTON_MARGIN / 2
          },
          {
              Constants::BUTTON_WIDTH,
              Constants::BUTTON_HEIGHT
          },
          "EXIT"
      ) {
    focusResume();
}

ApplicationStatus Pause::processEvents(sf::Event event) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            focusResume();
        } else if (event.key.code == sf::Keyboard::Down) {
            focusExit();
        } else if (event.key.code == sf::Keyboard::Enter) {
            if (mFocusedButton == FocusedButton::RESUME) {
                return ApplicationStatus::GAME;
            } else if (mFocusedButton == FocusedButton::EXIT) {
                return ApplicationStatus::MAIN_MENU;
            }
        }
    }

    return ApplicationStatus::PAUSE;
}

void Pause::update(sf::Time timePerFrame) {}

void Pause::draw(sf::RenderTarget & target, sf::RenderStates states) const {
    target.draw(mResumeButton, states);
    target.draw(mExitButton, states);
}

void Pause::focusResume() {
    mResumeButton.focus(true);
    mExitButton.focus(false);
    mFocusedButton = FocusedButton::RESUME;
}

void Pause::focusExit() {
    mResumeButton.focus(false);
    mExitButton.focus(true);
    mFocusedButton = FocusedButton::EXIT;
}
