#ifndef VOLLEYBALLGAME_SRC_PLAYER_H
#define VOLLEYBALLGAME_SRC_PLAYER_H

#include <SFML/Graphics.hpp>
#include "ApplicationStatus.h"

class Player : public sf::Drawable {
public:
    Player(const Player &) = delete;
    Player & operator=(const Player &) = delete;

    sf::CircleShape getHead() const;
protected:
    Player();
    void update(sf::Time timePerFrame);

    bool mIsMovingUp;
    bool mIsMovingLeft;
    bool mIsMovingRight;
    sf::RectangleShape mPlayer;
    float mJumpVelocity;
    bool mOnGround;

private:
    void alignDownIfNecessary();
    void draw(sf::RenderTarget & target,
              sf::RenderStates states) const override;
};

#endif //VOLLEYBALLGAME_SRC_PLAYER_H
