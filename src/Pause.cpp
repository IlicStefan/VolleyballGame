#include "Pause.h"

Pause::Pause() : mSelectedButton(Button::RESUME_GAME) {
  mResumeGameButton.setPosition(250.f, 230.f);
  mResumeGameButton.setSize({60.f, 20.f});
  mResumeGameButton.setFillColor(sf::Color::Green);

  mGoToMainMenuButton.setPosition(330.f, 230.f);
  mGoToMainMenuButton.setSize({60.f, 20.f});
  mGoToMainMenuButton.setFillColor(sf::Color::Red);
}

ApplicationStatus Pause::processEvents(sf::Event event) {
  if (event.type == sf::Event::KeyPressed) {
    if (event.key.code == sf::Keyboard::Left) {
      mSelectedButton = Button::RESUME_GAME;
    } else if (event.key.code == sf::Keyboard::Right) {
      mSelectedButton = Button::GO_TO_MAIN_MENU;
    } else if (event.key.code == sf::Keyboard::Enter) {
      if (mSelectedButton == Button::RESUME_GAME) {
        return ApplicationStatus::GAME;
      } else if (mSelectedButton == Button::GO_TO_MAIN_MENU) {
        return ApplicationStatus::MAIN_MENU;
      }
    }
  }

  return ApplicationStatus::PAUSE;
}

void Pause::update(sf::Time timePerFrame) {}

void Pause::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  sf::RectangleShape selectedButtonShadow;

  if (mSelectedButton == Pause::Button::RESUME_GAME) {
    selectedButtonShadow = mResumeGameButton;
  } else {
    selectedButtonShadow = mGoToMainMenuButton;
  }

  selectedButtonShadow.setPosition(selectedButtonShadow.getPosition().x - 3.f,
                                   selectedButtonShadow.getPosition().y - 3.f);
  selectedButtonShadow.setSize({selectedButtonShadow.getSize().x + 6.f,
                                selectedButtonShadow.getSize().y + 6.f});

  selectedButtonShadow.setFillColor(sf::Color::Yellow);

  target.draw(selectedButtonShadow, states);
  target.draw(mResumeGameButton, states);
  target.draw(mGoToMainMenuButton, states);
}
