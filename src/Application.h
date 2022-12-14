#ifndef VOLLEYBALLGAME_APPLICATION_H
#define VOLLEYBALLGAME_APPLICATION_H

#include "ApplicationStatus.h"
#include "ApplicationState.h"
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

class Application {
public:
    Application(const Application &) = delete;
    Application & operator=(const Application &) = delete;

    Application();
    void run(unsigned minimumFramePerSeconds);

private:
    void processEvents();
    void update(sf::Time timePerFrame);
    void render();

    sf::RenderWindow mWindow;
    ApplicationStatus mStatus;
    std::vector<std::unique_ptr<ApplicationState>> mStates;
};

#endif // VOLLEYBALLGAME_APPLICATION_H
