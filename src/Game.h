#ifndef VOLLEYBALLGAME_GAME_H
#define VOLLEYBALLGAME_GAME_H

#include "Application.h"
#include "ApplicationState.h"
#include "ApplicationStatus.h"

class Game : public ApplicationState {
public:
  Game();
  virtual ApplicationStatus processEvents(sf::Event event);
  virtual void update(sf::Time timePerFrame);

private:
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
  void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

  sf::CircleShape mShape;
  bool mIsMovingUp;
  bool mIsMovingDown;
  bool mIsMovingLeft;
  bool mIsMovingRight;
};

#endif // VOLLEYBALLGAME_GAME_H
