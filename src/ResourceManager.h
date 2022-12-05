#ifndef VOLLEYBALLGAME_RESOURCEHOLDER_H
#define VOLLEYBALLGAME_RESOURCEHOLDER_H

#include <map>
#include <memory>
#include <string>
#include <SFML/Audio.hpp>

template<typename IDENTIFIER, typename RESOURCE>
class ResourceManager {
public:
    ResourceManager() = default;
    ResourceManager(const ResourceManager &) = delete;
    ResourceManager & operator=(const ResourceManager &) = delete;

    void load(const IDENTIFIER & id, const std::string & filename) {
        std::unique_ptr<RESOURCE> resource = std::make_unique<RESOURCE>();
        if (not resource->loadFromFile(filename)) {
            throw std::runtime_error(
                "ResourceManager::load - Failed to load " + filename + ".");
        }
        mResourceMap.emplace(id, std::move(resource));
    }

    template<typename SECOND_PARAMETER>
    void load(IDENTIFIER id,
              const std::string & filename,
              const SECOND_PARAMETER & secondParameter) {
        std::unique_ptr<RESOURCE> resource = std::make_unique<RESOURCE>();
        if (!resource->loadFromFile(filename, secondParameter)) {
            throw std::runtime_error(
                "ResourceManager::load - Failed to load " + filename + "."
            );
        }
        mResourceMap.emplace(id, std::move(resource));
    }

    const RESOURCE & get(const IDENTIFIER & id) const {
        return *mResourceMap.at(id);
    }

private:
    std::map<IDENTIFIER, std::unique_ptr<RESOURCE>> mResourceMap;
};

template<typename IDENTIFIER>
class ResourceManager<IDENTIFIER, sf::Music> {
public:
    ResourceManager() = default;
    ResourceManager(const ResourceManager &) = delete;
    ResourceManager & operator=(const ResourceManager &) = delete;

    void load(const IDENTIFIER & id, const std::string & filename) {
        std::unique_ptr<sf::Music> resource = std::make_unique<sf::Music>();
        if (not resource->openFromFile(filename)) {
            throw std::runtime_error(
                "ResourceManager::load - Failed to load " + filename + ".");
        }
        mResourceMap.emplace(id, std::move(resource));
    }

    const sf::Music & get(const IDENTIFIER & id) const {
        return *mResourceMap.at(id);
    }

private:
    std::map<IDENTIFIER, std::unique_ptr<sf::Music>> mResourceMap;
};

#endif // VOLLEYBALLGAME_RESOURCEHOLDER_H
