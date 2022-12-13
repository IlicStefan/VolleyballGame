#ifndef VOLLEYBALLGAME_SRC_PLAYER_H
#define VOLLEYBALLGAME_SRC_PLAYER_H

#include <SFML/Graphics.hpp>
#include "ApplicationStatus.h"

class Player : public sf::Drawable {
public:
    Player(const Player &) = delete;
    Player & operator=(const Player &) = delete;

    Player();
    void update(sf::Time timePerFrame);
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
    void draw(sf::RenderTarget & target,
              sf::RenderStates states) const override;

    sf::RectangleShape mPlayer;
    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingLeft;
    bool mIsMovingRight;
};

#endif //VOLLEYBALLGAME_SRC_PLAYER_H
