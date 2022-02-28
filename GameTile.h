#include <SFML/Graphics.hpp>

#ifndef _GAMETILE_H_
#define _GAMETILE_H_

class GameTile
{
    public:
    bool isPassable;
    bool isExit;
    sf::Vector2f pos;
    sf::Texture texture;
    sf::Sprite sprite;

    GameTile(std::string, float, float, bool, bool);

    bool setupSprite(std::string);
};

#endif