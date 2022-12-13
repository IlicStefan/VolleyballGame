#include "Button.h"
#include "Configuration.h"
#include "Constants.h"
#include "Textures.h"
#include "Fonts.h"
#include <iostream>

Button::Button(const sf::Vector2f & position,
               const sf::Vector2f & size,
               const std::string & text)
    : mBackground(Configuration::textures.get(Textures::BUTTON)),
      mIsFocused(false) {
    setBackgroundPosition(position);
    setBackgroundSize(size);
    initText(text);
    setTextPosition();
}

void Button::focus(bool focused) {
    mIsFocused = focused;
    if (mIsFocused) {
        mText.setFillColor(sf::Color::Yellow);
    } else {
        mText.setFillColor(sf::Color::White);
    }
}

void Button::draw(sf::RenderTarget & target, sf::RenderStates states) const {
    target.draw(mBackground);
    target.draw(mText);
}

void Button::setBackgroundPosition(const sf::Vector2f & position) {
    mBackground.setPosition(position);
}

void Button::setBackgroundSize(const sf::Vector2f & size) {
    mBackground.setScale(
        size.x / float(mBackground.getTextureRect().width),
        size.y / float(mBackground.getTextureRect().height)
    );
}

void Button::initText(const std::string & text) {
    mFont = Configuration::fonts.get(Fonts::FRUIT_DAYS);
    mText.setFont(mFont);
    mText.setCharacterSize(Constants::BUTTON_TEXT_CHARACTER_SIZE);
    mText.setString(text);
}

void Button::setTextPosition() {
    sf::Vector2f textMovement;
    textMovement.x =
        (mBackground.getGlobalBounds().width - mText.getGlobalBounds().width)
            / 2.f;
    textMovement.y =
        (mBackground.getGlobalBounds().height - mText.getGlobalBounds().height)
            / 3.f;
    mText.setPosition(mBackground.getPosition() + textMovement);
}
