#ifndef VOLLEYBALLGAME_SRC_RIGHTPLAYER_H
#define VOLLEYBALLGAME_SRC_RIGHTPLAYER_H

#include "Player.h"

class RightPlayer : public Player {
public:
    RightPlayer(const RightPlayer &) = delete;
    RightPlayer & operator=(const RightPlayer &) = delete;

    RightPlayer();

    void update(sf::Time timePerFrame);
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
    void alignLeftIfNecessary();
    void alignRightIfNecessary();
};

#endif //VOLLEYBALLGAME_SRC_RIGHTPLAYER_H
