#ifndef VOLLEYBALLGAME_APPLICATIONSTATE_H
#define VOLLEYBALLGAME_APPLICATIONSTATE_H

#include "Application.h"
#include "ApplicationStatus.h"
#include <SFML/Graphics.hpp>

class ApplicationState : public sf::Drawable {
public:
    ApplicationState() = default;
    ApplicationState(ApplicationState &) = delete;
    ApplicationState & operator=(const ApplicationState &) = delete;

    virtual ApplicationStatus processEvents(sf::Event event) = 0;
    virtual void update(sf::Time timePerFrame) = 0;

private:
    void draw(sf::RenderTarget & target,
              sf::RenderStates states) const override = 0;
};

#endif // VOLLEYBALLGAME_APPLICATIONSTATE_H
