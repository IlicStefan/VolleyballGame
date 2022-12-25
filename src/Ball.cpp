#include "Ball.h"
#include "Configuration.h"
#include "Constants.h"
#include <cmath>

Ball::Ball()
    : mBall(Configuration::textures.get(Textures::BALL)),
      mOnGround(false), mAngleInDegrees(90.f), mVelocity(0.f),
      mAccumulatedTimeSinceHit(0.f) {
    sf::Vector2f initialPosition = {Constants::BALL_STARTING_POSITION_X,
                                    Constants::BALL_STARTING_POSITION_Y};
    mInitialPositionFromHit = initialPosition;
    mBall.setPosition(initialPosition);
    mBall.setScale(
        Constants::BALL_RADIUS / float(mBall.getTextureRect().width),
        Constants::BALL_RADIUS / float(mBall.getTextureRect().height)
    );
}

void Ball::update(sf::Time timePerFrame,
                  const LeftPlayer & leftPlayer,
                  const RightPlayer & rightPlayer,
                  const Net & net) {
    if (mOnGround) {
        return;
    }

    const float deltaTime = timePerFrame.asSeconds();
    mAccumulatedTimeSinceHit += deltaTime * Constants::BALL_SPEED;
    const float mAngleInRadians = mAngleInDegrees * M_PI / 180.f;

    sf::Vector2f movement{std::cos(mAngleInRadians), std::sin(mAngleInRadians)};
    movement *= mVelocity;
    movement.y += Constants::BALL_GRAVITY * mAccumulatedTimeSinceHit / 2.f;
    movement *= mAccumulatedTimeSinceHit;

    mBall.setPosition(mInitialPositionFromHit + movement);

    checkForCollisionsWith(leftPlayer);
    checkForCollisionsWith(rightPlayer);
    checkForCollisionsWith(net);
    freezeIfDrop();
}

void Ball::freezeIfDrop() {
    constexpr float
        border = Constants::WINDOW_HEIGHT - Constants::BALL_RADIUS;

    if (border < mBall.getPosition().y) {
        mBall.setPosition(mBall.getPosition().x, border);
        mOnGround = true;
        mVelocity = 0.f;
        mAngleInDegrees = 0.f;
        mAccumulatedTimeSinceHit = 0.f;
    }
}

void Ball::draw(sf::RenderTarget & target, sf::RenderStates states) const {
    target.draw(mBall, states);
}

void Ball::checkForCollisionsWith(const Player & player) {
    // To do..
}

void Ball::checkForCollisionsWith(const Net & net) {
    // To do..
}
