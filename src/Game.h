#ifndef VOLLEYBALLGAME_GAME_H
#define VOLLEYBALLGAME_GAME_H

#include "Application.h"
#include "ApplicationState.h"
#include "ApplicationStatus.h"
#include "Ball.h"
#include "Net.h"
#include "Player.h"

class Game : public ApplicationState {
public:
    Game();
    ApplicationStatus processEvents(sf::Event event) override;
    void update(sf::Time timePerFrame) override;

private:
    void draw(sf::RenderTarget & target,
              sf::RenderStates states) const override;

    Net mNet;
    Player mPlayer;
    Ball mBall;
    sf::Sprite mBackground;
};

#endif // VOLLEYBALLGAME_GAME_H
