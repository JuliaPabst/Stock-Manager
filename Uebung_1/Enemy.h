//
// Created by Petra Scheuer on 28.02.24.
//
#ifndef UEBUNG_1_ENEMY_H
#define UEBUNG_1_ENEMY_H

#include "Charakter.h"
#include "Spielfeld.h"
#include "Player.h"

class Enemy : public Charakter {
public:
    Enemy(unsigned short int x, unsigned short int y, char sign)
            : Charakter(x, y, sign) {};
    void moveTowardsPlayer(Player& player);
    void attackPlayer(Player& player);


};


#endif //UEBUNG_1_ENEMY_H
