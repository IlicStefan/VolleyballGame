#ifndef VOLLEYBALLGAME_APPLICATIONSTATE_H
#define VOLLEYBALLGAME_APPLICATIONSTATE_H

#include "Application.h"
#include "ApplicationStatus.h"
#include <SFML/Graphics.hpp>

class ApplicationState : public sf::Drawable {
public:
  virtual ~ApplicationState(){};

  virtual ApplicationStatus processEvents(sf::Event event) = 0;
  virtual void update(sf::Time timePerFrame) = 0;

private:
  virtual void draw(sf::RenderTarget &target,
                    sf::RenderStates states) const = 0;
};

#endif // VOLLEYBALLGAME_APPLICATIONSTATE_H
