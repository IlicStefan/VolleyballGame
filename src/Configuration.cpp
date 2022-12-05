#include "Configuration.h"

ResourceManager<Textures, sf::Texture> Configuration::textures;
ResourceManager<Fonts, sf::Font> Configuration::fonts;

void Configuration::initialize() {
    initTextures();
    initFonts();
}

void Configuration::initTextures() {
    textures.load(Textures::BACKGROUND_MAIN_MENU,
                  "../res/textures/backgroundMainMenu.jpg");
    textures.load(Textures::BACKGROUND_GAME,
                  "../res/textures/backgroundGame.jpg");
    textures.load(Textures::BALL, "../res/textures/ball.png");
    textures.load(Textures::BUTTON, "../res/textures/button.png");
}

void Configuration::initFonts() {
    fonts.load(Fonts::FRUIT_DAYS, "../res/fonts/fruit_days.otf");
}
