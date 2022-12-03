#ifndef VOLLEYBALLGAME_MAINMENU_H
#define VOLLEYBALLGAME_MAINMENU_H

#include "Application.h"
#include "ApplicationState.h"
#include "ApplicationStatus.h"

class MainMenu : public ApplicationState {
public:
  enum class Button { START_GAME, EXIT };

  MainMenu();

  virtual ApplicationStatus processEvents(sf::Event event);
  virtual void update(sf::Time timePerFrame);

private:
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  Button mSelectedButton;
  sf::RectangleShape mStartGameButton;
  sf::RectangleShape mExitGameButton;
};

#endif // VOLLEYBALLGAME_MAINMENU_H
