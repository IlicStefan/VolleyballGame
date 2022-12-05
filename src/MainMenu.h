#ifndef VOLLEYBALLGAME_MAINMENU_H
#define VOLLEYBALLGAME_MAINMENU_H

#include "Application.h"
#include "ApplicationState.h"
#include "ApplicationStatus.h"
#include "Button.h"

class MainMenu : public ApplicationState {
public:
    enum class FocusedButton { START, QUIT };

    MainMenu();

    ApplicationStatus processEvents(sf::Event event) override;
    void update(sf::Time timePerFrame) override;

private:
    void draw(sf::RenderTarget & target,
              sf::RenderStates states) const override;
    void focusStart();
    void focusQuit();

    sf::Sprite mBackground;
    FocusedButton mFocusedButton;
    Button mStartButton;
    Button mQuitButton;
};

#endif // VOLLEYBALLGAME_MAINMENU_H
