#include "MainMenu.h"

MainMenu::MainMenu() : mSelectedButton(Button::START_GAME) {
  mStartGameButton.setPosition(290.f, 210.f);
  mStartGameButton.setSize({60.f, 20.f});
  mStartGameButton.setFillColor(sf::Color::Green);

  mExitGameButton.setPosition(290.f, 250.f);
  mExitGameButton.setSize({60.f, 20.f});
  mExitGameButton.setFillColor(sf::Color::Red);
}

ApplicationStatus MainMenu::processEvents(sf::Event event) {
  if (event.type == sf::Event::KeyPressed) {
    if (event.key.code == sf::Keyboard::Up) {
      mSelectedButton = Button::START_GAME;
    } else if (event.key.code == sf::Keyboard::Down) {
      mSelectedButton = Button::EXIT;
    } else if (event.key.code == sf::Keyboard::Enter) {
      if (mSelectedButton == Button::START_GAME) {
        return ApplicationStatus::GAME;
      } else if (mSelectedButton == Button::EXIT) {
        return ApplicationStatus::EXIT;
      }
    }
  }

  return ApplicationStatus::MAIN_MENU;
}

void MainMenu::update(sf::Time timePerFrame) {}

void MainMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const {
  sf::RectangleShape selectedButtonShadow;

  if (mSelectedButton == Button::START_GAME) {
    selectedButtonShadow = mStartGameButton;
  } else {
    selectedButtonShadow = mExitGameButton;
  }

  selectedButtonShadow.setPosition(selectedButtonShadow.getPosition().x - 3.f,
                                   selectedButtonShadow.getPosition().y - 3.f);
  selectedButtonShadow.setSize({selectedButtonShadow.getSize().x + 6.f,
                                selectedButtonShadow.getSize().y + 6.f});

  selectedButtonShadow.setFillColor(sf::Color::Yellow);

  target.draw(selectedButtonShadow, states);
  target.draw(mStartGameButton, states);
  target.draw(mExitGameButton, states);
}
