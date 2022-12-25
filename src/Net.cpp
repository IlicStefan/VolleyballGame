#include "Net.h"
#include "Constants.h"

Net::Net() {
    mNet.setPosition((Constants::WINDOW_WIDTH - Constants::NET_WIDTH) / 2,
                     Constants::WINDOW_HEIGHT - Constants::NET_HEIGHT);
    mNet.setSize({Constants::NET_WIDTH, Constants::NET_HEIGHT});
    mNet.setFillColor(sf::Color::Yellow);
}

sf::RectangleShape Net::getShape() const {
    return mNet;
}

void Net::draw(sf::RenderTarget & target, sf::RenderStates states) const {
    target.draw(mNet, states);
}
