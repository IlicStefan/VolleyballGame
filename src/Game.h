#ifndef VOLLEYBALLGAME_GAME_H
#define VOLLEYBALLGAME_GAME_H

#include "Application.h"
#include "ApplicationState.h"
#include "ApplicationStatus.h"

class Game : public ApplicationState {
public:
    Game();
    ApplicationStatus processEvents(sf::Event event) override;
    void update(sf::Time timePerFrame) override;

private:
    void draw(sf::RenderTarget & target,
              sf::RenderStates states) const override;
    void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

    sf::Sprite mBall;
    sf::Sprite mBackground;
    bool mIsMovingUp;
    bool mIsMovingDown;
    bool mIsMovingLeft;
    bool mIsMovingRight;
};

#endif // VOLLEYBALLGAME_GAME_H
