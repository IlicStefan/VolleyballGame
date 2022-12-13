#ifndef VOLLEYBALLGAME_BUTTON_H
#define VOLLEYBALLGAME_BUTTON_H

#include <SFML/Graphics.hpp>
#include <string>

class Button : public sf::Drawable {
public:
    Button(const Button &) = delete;
    Button & operator=(const Button &) = delete;

    Button(const sf::Vector2f & position,
           const sf::Vector2f & size,
           const std::string & text);
    void focus(bool focused);

private:
    void draw(sf::RenderTarget & target,
              sf::RenderStates states) const override;
    void setBackgroundPosition(const sf::Vector2f & position);
    void setBackgroundSize(const sf::Vector2f & size);
    void initText(const std::string & text);
    void setTextPosition();

    bool mIsFocused;
    sf::Sprite mBackground;
    sf::Text mText;
    sf::Font mFont;
};

#endif // VOLLEYBALLGAME_BUTTON_H
