#ifndef VOLLEYBALLGAME_SRC_NET_H
#define VOLLEYBALLGAME_SRC_NET_H

#include <SFML/Graphics.hpp>

class Net : public sf::Drawable {
public:
    Net(const Net &) = delete;
    Net & operator=(const Net &) = delete;

    Net();
    sf::RectangleShape getShape() const;
private:
    void draw(sf::RenderTarget & target,
              sf::RenderStates states) const override;

    sf::RectangleShape mNet;
};

#endif //VOLLEYBALLGAME_SRC_NET_H
