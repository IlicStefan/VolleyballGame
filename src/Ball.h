#ifndef VOLLEYBALLGAME_SRC_BALL_H
#define VOLLEYBALLGAME_SRC_BALL_H

#include <SFML/Graphics.hpp>

class Ball : public sf::Drawable {
public:
    Ball(const Ball &) = delete;
    Ball & operator=(const Ball &) = delete;

    Ball();

private:
    void draw(sf::RenderTarget & target,
              sf::RenderStates states) const override;

    sf::Vector2f mPosition;
    float mRadius;
    sf::Sprite mBackground;
};

#endif //VOLLEYBALLGAME_SRC_BALL_H
