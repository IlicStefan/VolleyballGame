#ifndef VOLLEYBALLGAME_SRC_CONFIGURATION_H
#define VOLLEYBALLGAME_SRC_CONFIGURATION_H

#include "ResourceManager.h"
#include "Textures.h"
#include "Fonts.h"
#include <SFML/Graphics.hpp>

class Configuration {
public:
    Configuration() = delete;
    Configuration(const Configuration &) = delete;
    Configuration & operator=(const Configuration &) = delete;

    static ResourceManager<Textures, sf::Texture> textures;
    static ResourceManager<Fonts, sf::Font> fonts;

    static void initialize();

private:
    static void initTextures();
    static void initFonts();
};

#endif //VOLLEYBALLGAME_SRC_CONFIGURATION_H
