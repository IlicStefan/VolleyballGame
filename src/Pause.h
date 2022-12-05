#ifndef VOLLEYBALLGAME_PAUSE_H
#define VOLLEYBALLGAME_PAUSE_H

#include "Application.h"
#include "ApplicationState.h"
#include "ApplicationStatus.h"
#include "Button.h"

class Pause : public ApplicationState {
public:
    Pause(const Pause &) = delete;
    Pause & operator=(const Pause &) = delete;

    enum class FocusedButton { RESUME, EXIT };

    Pause();
    ApplicationStatus processEvents(sf::Event event) override;
    void update(sf::Time timePerFrame) override;

private:
    void draw(sf::RenderTarget & target,
              sf::RenderStates states) const override;
    void focusResume();
    void focusExit();

    FocusedButton mFocusedButton;
    Button mResumeButton;
    Button mExitButton;
};

#endif // VOLLEYBALLGAME_PAUSE_H
