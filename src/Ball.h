#ifndef VOLLEYBALLGAME_SRC_BALL_H
#define VOLLEYBALLGAME_SRC_BALL_H

#include <SFML/Graphics.hpp>
#include "LeftPlayer.h"
#include "RightPlayer.h"
#include "Net.h"

class Ball : public sf::Drawable {
public:
    Ball(const Ball &) = delete;
    Ball & operator=(const Ball &) = delete;

    Ball();
    void update(sf::Time timePerFrame,
                const LeftPlayer & leftPlayer,
                const RightPlayer & rightPlayer,
                const Net & net);

private:
    void draw(sf::RenderTarget & target,
              sf::RenderStates states) const override;
    void freezeIfDrop();
    void checkForCollisionsWith(const Player & player);
    void checkForCollisionsWith(const Net & net);

    sf::Sprite mBall;
    bool mOnGround;
    sf::Vector2f mInitialPositionFromHit;
    float mVelocity;
    float mAngleInDegrees;
    float mAccumulatedTimeSinceHit;
};

#endif //VOLLEYBALLGAME_SRC_BALL_H
