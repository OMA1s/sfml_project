#include <SFML/Graphics.hpp>
#include "GameTile.h"
#include <vector>

#ifndef _GAMEWORLD_H_
#define _GAMEWORLD_H_

class GameWorld
{
    sf::Vector2i exitPos;
    sf::Vector2i playerPos;
    std::vector<sf::Vector2i> enemyPositions;
    void setupInitialState();
    void setupEnemyPositions();
    void setupTiles();
    void redrawSprites();

    std::vector<sf::Vector2i> getFreeCoordinates(sf::Vector2i);
    bool checkIfPositionIsFree(sf::Vector2i);

    void moveEnemies();
    bool checkIfReachedExit();
    bool checkIfTouchedEnemy();
    void checkCollisionsAndMoveEnemies();
    public:
    std::vector<std::vector<GameTile *>> tiles;
    int gridLength;
    GameWorld();
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
};

#endif
