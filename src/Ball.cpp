#include "Ball.h"
#include "Configuration.h"
#include "Constants.h"

Ball::Ball() : mBackground(Configuration::textures.get(Textures::BALL)) {
    sf::Vector2f position = {100.f, 100.f};
    mPosition = position;
    mBackground.setPosition(position);
    mRadius = Constants::BALL_RADIUS;
    mBackground.setScale(
        mRadius / float(mBackground.getTextureRect().width),
        mRadius / float(mBackground.getTextureRect().height)
    );
}

void Ball::draw(sf::RenderTarget & target, sf::RenderStates states) const {
    target.draw(mBackground, states);
}
