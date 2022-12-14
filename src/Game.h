#ifndef VOLLEYBALLGAME_GAME_H
#define VOLLEYBALLGAME_GAME_H

#include "Application.h"
#include "ApplicationState.h"
#include "ApplicationStatus.h"
#include "Ball.h"
#include "Net.h"
#include "LeftPlayer.h"
#include "RightPlayer.h"

class Game : public ApplicationState {
public:
    Game();
    ApplicationStatus processEvents(sf::Event event) override;
    void update(sf::Time timePerFrame) override;

private:
    void draw(sf::RenderTarget & target,
              sf::RenderStates states) const override;

    Net mNet;
    LeftPlayer mLeftPlayer;
    RightPlayer mRightPlayer;
    Ball mBall;
    sf::Sprite mBackground;
};

#endif // VOLLEYBALLGAME_GAME_H
