#ifndef VOLLEYBALLGAME_SRC_PLAYER_H
#define VOLLEYBALLGAME_SRC_PLAYER_H

#include <SFML/Graphics.hpp>
#include "ApplicationStatus.h"

class Player : public sf::Drawable {
public:
    Player(const Player &) = delete;
    Player & operator=(const Player &) = delete;

    Player();

protected:
    bool mIsMovingUp;
    bool mIsMovingLeft;
    bool mIsMovingRight;
    sf::RectangleShape mPlayer;

private:
    void draw(sf::RenderTarget & target,
              sf::RenderStates states) const override;
};

#endif //VOLLEYBALLGAME_SRC_PLAYER_H
