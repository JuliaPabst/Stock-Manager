//
// Created by Petra Scheuer on 28.02.24.
//
#ifndef UEBUNG_1_PLAYER_H
#define UEBUNG_1_PLAYER_H

#include "Charakter.h"
#include "Spielfeld.h"


class Player : public Charakter{
private:
    unsigned short int lifepoints_;
    unsigned short int reliktpoints_;


public:
    Player(unsigned short int x, unsigned short int y, char sign, unsigned short int lifepoints, unsigned short int reliktpoints)
            : Charakter(x, y, sign), lifepoints_(lifepoints), reliktpoints_(reliktpoints) {};

    //Setter
    void setLifepoints(unsigned short int lifepoints);
    void setReliktpoints(int reliktpoints);
    //Getter
    unsigned short int getLifepoints()const;
    unsigned short int getReliktpoints()const;

    void incrementLifepoints();
    void decrementLifepoints();
    void incrementReliktpoints();

    void movePlayer(Spielfeld spielfeld[][5], char input);
    void auswirkungen(Spielfeld spielfeld[][5]);
};


#endif //UEBUNG_1_PLAYER_H
