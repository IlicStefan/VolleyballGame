#ifndef VOLLEYBALLGAME_PAUSE_H
#define VOLLEYBALLGAME_PAUSE_H

#include "Application.h"
#include "ApplicationState.h"
#include "ApplicationStatus.h"

class Pause : public ApplicationState {
public:
  enum class Button { RESUME_GAME, GO_TO_MAIN_MENU };

  Pause();
  virtual ApplicationStatus processEvents(sf::Event event);
  virtual void update(sf::Time timePerFrame);

private:
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

  Button mSelectedButton;
  sf::RectangleShape mResumeGameButton;
  sf::RectangleShape mGoToMainMenuButton;
};

#endif // VOLLEYBALLGAME_PAUSE_H
