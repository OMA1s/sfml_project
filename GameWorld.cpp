#include "GameWorld.h"
#include <stdio.h>
#include <stdlib.h>

GameWorld::GameWorld()
{
    gridLength = 8;
    setupInitialState();
    setupTiles();
}


void GameWorld::setupInitialState()
{
    exitPos = sf::Vector2i(1,0);
    playerPos = sf::Vector2i(gridLength - 1, gridLength - 1);
    setupEnemyPositions();
}

void GameWorld::setupEnemyPositions()
{
    enemyPositions.clear();
    enemyPositions.push_back(sf::Vector2i(0,2));
    enemyPositions.push_back(sf::Vector2i(6,0));
    enemyPositions.push_back(sf::Vector2i(2,7));
}

void GameWorld::setupTiles()
{
    tiles.clear();
    std::vector<GameTile *> firstRow;
    firstRow.push_back(new GameTile("Assets/wall.png", 0, 0, false, false));
    firstRow.push_back(new GameTile("Assets/door.png", 50, 0, true, true));
    firstRow.push_back(new GameTile("Assets/wall.png", 100, 0, false, false));
    firstRow.push_back(new GameTile("Assets/wall.png", 150, 0, false, false));
    firstRow.push_back(new GameTile("Assets/wall.png", 200, 0, false, false));
    firstRow.push_back(new GameTile("Assets/wall.png", 250, 0, false, false));
    firstRow.push_back(new GameTile("Assets/enemy.png", 300, 0, true, false));
    firstRow.push_back(new GameTile("Assets/wall.png", 350, 0, false, false));
    tiles.push_back(firstRow);

    std::vector<GameTile *> secondRow;
    secondRow.push_back(new GameTile("Assets/wall.png", 0, 50, false, false));
    secondRow.push_back(new GameTile("Assets/ground.png", 50, 50, true, false));
    secondRow.push_back(new GameTile("Assets/ground.png", 100, 50, true, false));
    secondRow.push_back(new GameTile("Assets/ground.png", 150, 50, true, false));
    secondRow.push_back(new GameTile("Assets/ground.png", 200, 50, true, false));
    secondRow.push_back(new GameTile("Assets/ground.png", 250, 50, true, false));
    secondRow.push_back(new GameTile("Assets/ground.png", 300, 50, true, false));
    secondRow.push_back(new GameTile("Assets/ground.png", 350, 50, true, false));
    tiles.push_back(secondRow);

    std::vector<GameTile *> thirdRow;
    thirdRow.push_back(new GameTile("Assets/enemy.png", 0, 100, true, false));
    thirdRow.push_back(new GameTile("Assets/ground.png", 50, 100, true, false));
    thirdRow.push_back(new GameTile("Assets/ground.png", 100, 100, true, false));
    thirdRow.push_back(new GameTile("Assets/wall.png", 150, 100, false, false));
    thirdRow.push_back(new GameTile("Assets/ground.png", 200, 100, true, false));
    thirdRow.push_back(new GameTile("Assets/ground.png", 250, 100, true, false));
    thirdRow.push_back(new GameTile("Assets/wall.png", 300, 100, false, false));
    thirdRow.push_back(new GameTile("Assets/wall.png", 350, 100, false, false));
    tiles.push_back(thirdRow);

    std::vector<GameTile *> fourthRow;
    fourthRow.push_back(new GameTile("Assets/wall.png", 0, 150, false, false));
    fourthRow.push_back(new GameTile("Assets/ground.png", 50, 150, true, false));
    fourthRow.push_back(new GameTile("Assets/ground.png", 100, 150, true, false));
    fourthRow.push_back(new GameTile("Assets/wall.png", 150, 150, false, false));
    fourthRow.push_back(new GameTile("Assets/ground.png", 200, 150, true, false));
    fourthRow.push_back(new GameTile("Assets/ground.png", 250, 150, true, false));
    fourthRow.push_back(new GameTile("Assets/ground.png", 300, 150, true, false));
    fourthRow.push_back(new GameTile("Assets/wall.png", 350, 150, false, false));
    tiles.push_back(fourthRow);

    std::vector<GameTile *> fifthRow;
    fifthRow.push_back(new GameTile("Assets/wall.png", 0, 200, false, false));
    fifthRow.push_back(new GameTile("Assets/ground.png", 50, 200, true, false));
    fifthRow.push_back(new GameTile("Assets/ground.png", 100, 200, true, false));
    fifthRow.push_back(new GameTile("Assets/wall.png", 150, 200, false, false));
    fifthRow.push_back(new GameTile("Assets/wall.png", 200, 200, false, false));
    fifthRow.push_back(new GameTile("Assets/ground.png", 250, 200, true, false));
    fifthRow.push_back(new GameTile("Assets/ground.png", 300, 200, true, false));
    fifthRow.push_back(new GameTile("Assets/ground.png", 350, 200, true, false));
    tiles.push_back(fifthRow);

    std::vector<GameTile *> sixthRow;
    sixthRow.push_back(new GameTile("Assets/ground.png", 0, 250, true, false));
    sixthRow.push_back(new GameTile("Assets/ground.png", 50, 250, true, false));
    sixthRow.push_back(new GameTile("Assets/ground.png", 100, 250, true, false));
    sixthRow.push_back(new GameTile("Assets/ground.png", 150, 250, true, false));
    sixthRow.push_back(new GameTile("Assets/wall.png", 200, 250, false, false));
    sixthRow.push_back(new GameTile("Assets/ground.png", 250, 250, true, false));
    sixthRow.push_back(new GameTile("Assets/ground.png", 300, 250, true, false));
    sixthRow.push_back(new GameTile("Assets/wall.png", 350, 250, false, false));
    tiles.push_back(sixthRow);

    std::vector<GameTile *> seventhRow;
    seventhRow.push_back(new GameTile("Assets/wall.png", 0, 300, false, false));
    seventhRow.push_back(new GameTile("Assets/wall.png", 50, 300, false, false));
    seventhRow.push_back(new GameTile("Assets/ground.png", 100, 300, true, false));
    seventhRow.push_back(new GameTile("Assets/ground.png", 150, 300, true, false));
    seventhRow.push_back(new GameTile("Assets/ground.png", 200, 300, true, false));
    seventhRow.push_back(new GameTile("Assets/ground.png", 250, 300, true, false));
    seventhRow.push_back(new GameTile("Assets/wall.png", 300, 300, false, false));
    seventhRow.push_back(new GameTile("Assets/wall.png", 350, 300, false, false));
    tiles.push_back(seventhRow);

    std::vector<GameTile *> eigthRow;
    eigthRow.push_back(new GameTile("Assets/wall.png", 0, 350, false, false));
    eigthRow.push_back(new GameTile("Assets/wall.png", 50, 350, false, false));
    eigthRow.push_back(new GameTile("Assets/enemy.png", 100, 350, true, false));
    eigthRow.push_back(new GameTile("Assets/wall.png", 150, 350, false, false));
    eigthRow.push_back(new GameTile("Assets/wall.png", 200, 350, false, false));
    eigthRow.push_back(new GameTile("Assets/ground.png", 250, 350, true, false));
    eigthRow.push_back(new GameTile("Assets/ground.png", 300, 350, true, false));
    eigthRow.push_back(new GameTile("Assets/player.png", 350, 350, true, false));
    tiles.push_back(eigthRow);
}

void GameWorld::moveDown()
{
    if (playerPos.y == gridLength - 1)
    {
        return;
    }
    if (!tiles[playerPos.y + 1][playerPos.x]->isPassable)
    {
        return;
    }
    tiles[playerPos.y][playerPos.x]->setupSprite("Assets/ground.png");
    playerPos.y += 1;

    checkCollisionsAndMoveEnemies();
}

void GameWorld::moveUp()
{
    if (playerPos.y == 0)
    {
        return;
    }
    if (!tiles[playerPos.y - 1][playerPos.x]->isPassable)
    {
        return;
    }
    tiles[playerPos.y][playerPos.x]->setupSprite("Assets/ground.png");
    playerPos.y -= 1;

    checkCollisionsAndMoveEnemies();
}
void GameWorld::moveRight()
{
    if (playerPos.x == gridLength-1)
    {
        return;
    }
    if (!tiles[playerPos.y][playerPos.x + 1]->isPassable)
    {
        return;
    }
    tiles[playerPos.y][playerPos.x]->setupSprite("Assets/ground.png");
    playerPos.x += 1;

    checkCollisionsAndMoveEnemies();
}
void GameWorld::moveLeft()
{
    if (playerPos.x == 0)
    {
        return;
    }
    if (!tiles[playerPos.y][playerPos.x - 1]->isPassable)
    {
        return;
    }
    tiles[playerPos.y][playerPos.x]->setupSprite("Assets/ground.png");
    playerPos.x -= 1;

    checkCollisionsAndMoveEnemies();
}

void GameWorld::redrawSprites()
{
    tiles[playerPos.y][playerPos.x]->setupSprite("Assets/player.png");

    for (int i = 0; i < enemyPositions.size(); i++)
    {
        sf::Vector2i currentEnemyPos = enemyPositions[i];
        tiles[currentEnemyPos.y][currentEnemyPos.x]->setupSprite("Assets/enemy.png");
    }
}

bool GameWorld::checkIfPositionIsFree(sf::Vector2i pos)
{
    if (pos.x < 0 || pos.y < 0 || pos.x > 7 || pos.y > 7)
    {
        return false;
    }
    if (!tiles[pos.y][pos.x]->isPassable)
    {
        return false;
    }
    if (tiles[pos.y][pos.x]->isExit)
    {
        return false;
    }
    return true;
}

std::vector<sf::Vector2i> GameWorld::getFreeCoordinates(sf::Vector2i currentPosition)
{
    std::vector<sf::Vector2i> freePositions;
    std::vector<sf::Vector2i> allPositions;
    
    allPositions.push_back(sf::Vector2i(currentPosition.x - 1, currentPosition.y));
    allPositions.push_back(sf::Vector2i(currentPosition.x - 1, currentPosition.y - 1));
    allPositions.push_back(sf::Vector2i(currentPosition.x, currentPosition.y - 1));
    allPositions.push_back(sf::Vector2i(currentPosition.x + 1, currentPosition.y - 1));
    allPositions.push_back(sf::Vector2i(currentPosition.x + 1, currentPosition.y));
    allPositions.push_back(sf::Vector2i(currentPosition.x +- 1, currentPosition.y + 1));
    allPositions.push_back(sf::Vector2i(currentPosition.x, currentPosition.y + 1));
    allPositions.push_back(sf::Vector2i(currentPosition.x - 1, currentPosition.y + 1));

    for (int i  = 0; i < 8; i++)
    {
        if (checkIfPositionIsFree(allPositions[i]))
        {
            freePositions.push_back(allPositions[i]);
        }
    }
    return freePositions;
}

void GameWorld::moveEnemies()
{
    for (int i = 0; i < enemyPositions.size(); i++)
    {
        sf::Vector2i cuurentEnemyPos = enemyPositions[i];
        std::vector<sf::Vector2i> freePositions = getFreeCoordinates(cuurentEnemyPos);
        int randomIndex = rand() % (freePositions.size() - 1);
        sf::Vector2i newPos = freePositions[randomIndex];

        tiles[cuurentEnemyPos.y][cuurentEnemyPos.x]->setupSprite("Assets/ground.png");
        enemyPositions[i] = newPos;
    }
}

void GameWorld::checkCollisionsAndMoveEnemies()
{
    if (checkIfReachedExit())
    {
        setupInitialState();
        return;
    }

    moveEnemies();
    if (checkIfTouchedEnemy())
    {
        setupInitialState();
        return;
    }
    redrawSprites();
}

bool GameWorld::checkIfReachedExit()
{
    return playerPos.x == exitPos.x && playerPos.y == exitPos.y;
}

bool GameWorld::checkIfTouchedEnemy()
{
    for (int i {0}; i < enemyPositions.size(); i++)
    {
        sf::Vector2i currentEnemyPos = enemyPositions[i];
        if (playerPos.x == currentEnemyPos.x && playerPos.y == currentEnemyPos.y)
        {
            return true;
        }
    }
    return false;
}