#include "GameTile.h"
#include <iostream>

GameTile::GameTile(std::string textureName, float x, float y, bool passable, bool exit)
{
    if (!setupSprite(textureName))
    {
        std::cout<<"Could not load tile sprite\n";
        return;
    }
    pos = sf::Vector2f(x, y);
    sprite.setPosition(pos);
    isPassable = passable;
    isExit = exit;
}

bool GameTile::setupSprite(std::string textureName)
{
    if (!texture.loadFromFile(textureName))
    {
        std::cout<<"Could not load texture\n";
        return false;
    }
    texture.setSmooth(true);
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0,0,50,50));
    return true;
}