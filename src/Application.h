#ifndef VOLLEYBALLGAME_APPLICATION_H
#define VOLLEYBALLGAME_APPLICATION_H

#include <SFML/Graphics.hpp>

class Application {
public:
  Application();
  void run(unsigned minimumFramePerSeconds);

private:
  void processEvents();
  void update(sf::Time timePerFrame);
  void display();

  void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);

  sf::RenderWindow mWindow;
  sf::CircleShape mShape;
  bool mIsMovingUp;
  bool mIsMovingDown;
  bool mIsMovingLeft;
  bool mIsMovingRight;
};

#endif // VOLLEYBALLGAME_APPLICATION_H
