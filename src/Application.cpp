#include "Application.h"
#include "Constants.h"
#include "Game.h"
#include "MainMenu.h"
#include "Pause.h"

Application::Application()
    : mWindow(
    sf::VideoMode(
        Constants::WINDOW_WIDTH,
        Constants::WINDOW_HEIGHT),
    "Volleyball Game") {
    mWindow.setVerticalSyncEnabled(true);
    mStatus = ApplicationStatus::MAIN_MENU;
    mStates.push_back(std::make_unique<MainMenu>());
}

void Application::run(unsigned minimumFramePerSeconds) {
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    const sf::Time
        timePerFrame = sf::seconds(1.f / float(minimumFramePerSeconds));

    while (mWindow.isOpen()) {
        processEvents();
        timeSinceLastUpdate += clock.restart();

        while (timeSinceLastUpdate > timePerFrame) {
            timeSinceLastUpdate -= timePerFrame;
            update(timePerFrame);
        }
        update(timeSinceLastUpdate);

        render();
    }
}

void Application::processEvents() {
    sf::Event event;

    while (mWindow.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            mWindow.close();
        }

        ApplicationStatus status = mStates.back()->processEvents(event);

        if (mStatus == status) {
            continue;
        }

        if (mStatus == ApplicationStatus::MAIN_MENU) {
            if (status == ApplicationStatus::EXIT) {
                mWindow.close();
            } else if (status == ApplicationStatus::GAME) {
                mStates.push_back(std::make_unique<Game>());
                mStatus = ApplicationStatus::GAME;
            }
        } else if (mStatus == ApplicationStatus::GAME) {
            if (status == ApplicationStatus::PAUSE) {
                mStates.push_back(std::make_unique<Pause>());
                mStatus = ApplicationStatus::PAUSE;
            }
        } else if (mStatus == ApplicationStatus::PAUSE) {
            if (status == ApplicationStatus::GAME) {
                mStates.pop_back(); // pop Pause
                mStatus = ApplicationStatus::GAME;
            } else if (status == ApplicationStatus::MAIN_MENU) {
                mStates.pop_back(); // pop Pause
                mStates.pop_back(); // pop Game
                mStatus = ApplicationStatus::MAIN_MENU;
            }
        }
    }
}

void Application::update(sf::Time timePerFrame) {
    mStates.back()->update(timePerFrame);
}

void Application::render() {
    mWindow.clear();

    if (mStatus == ApplicationStatus::PAUSE) {
        mWindow.draw(*mStates.end()[-2]); // Draw Game
        mWindow.draw(*mStates.back());    // Draw Pause
    } else {
        mWindow.draw(*mStates.back());
    }

    mWindow.display();
}
