//
// Created by Petra Scheuer on 28.02.24.
//
#include <iostream>
#include <cstdlib> // Für die Verwendung von rand()
#include "Enemy.h"

void Enemy::moveTowardsPlayer(Player& player) {
    int playerX = player.getPositionX();
    int playerY = player.getPositionY();

    int enemyX = getPositionX();
    int enemyY = getPositionY();

    if (playerX < enemyX) {
        decrementX();  // Bewege nach links
    } else if (playerX > enemyX) {
        incrementX();  // Bewege nach rechts
    }

    if (playerY < enemyY) {
        decrementY();  // Bewege nach oben
    }
    else if (playerY > enemyY) {
        incrementY();  // Bewege nach unten
    }
    if((player.getPositionX() == getPositionX()) &&(player.getPositionY() == getPositionY())){
        attackPlayer(player);
    }
}
void Enemy::attackPlayer(Player& player){
    std::cout << "Attacke - du verlierst ein Leben" << std::endl;
    player.decrementLifepoints();

    unsigned short int newX = rand() % 5;
    unsigned short int newY = rand() % 5;

    setPositionX(newX);
    setPositionY(newY);
}
