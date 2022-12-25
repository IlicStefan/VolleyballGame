#ifndef VOLLEYBALLGAME_CONSTANTS_H
#define VOLLEYBALLGAME_CONSTANTS_H

namespace Constants {
    constexpr unsigned int WINDOW_WIDTH = 1600;
    constexpr unsigned int WINDOW_HEIGHT = 900;

    constexpr float BUTTON_WIDTH = 400.f;
    constexpr float BUTTON_HEIGHT = 200.f;
    constexpr float BUTTON_MARGIN = 60.f;
    constexpr unsigned int BUTTON_TEXT_CHARACTER_SIZE = 100u;

    constexpr float GAME_SPEED = 300.f;

    constexpr float BALL_RADIUS = 100.f;
    constexpr float BALL_SPEED = 5.f;
    constexpr float BALL_GRAVITY = 5.f;
    constexpr float BALL_STARTING_POSITION_X = 100.f;
    constexpr float BALL_STARTING_POSITION_Y = 100.f;

    constexpr float PLAYER_WIDTH = 100.f;
    constexpr float PLAYER_HEIGHT = 200.f;
    constexpr float PLAYER_STARTING_POSITION_FROM_FRAME = 100.f;
    constexpr float PLAYER_GRAVITY = 3.f;
    constexpr float PLAYER_JUMP_VELOCITY = -2.f;

    constexpr float NET_WIDTH = 10.f;
    constexpr float NET_HEIGHT = 400.f;
};

#endif // VOLLEYBALLGAME_CONSTANTS_H
