#ifndef VOLLEYBALLGAME_SRC_LEFTPLAYER_H
#define VOLLEYBALLGAME_SRC_LEFTPLAYER_H

#include "Player.h"

class LeftPlayer : public Player {
public:
    LeftPlayer(const LeftPlayer &) = delete;
    LeftPlayer & operator=(const LeftPlayer &) = delete;

    LeftPlayer();

    void update(sf::Time timePerFrame);
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

private:
    void AlignLeftIfNecessary();
    void AlignRightIfNecessary();
};

#endif //VOLLEYBALLGAME_SRC_LEFTPLAYER_H
