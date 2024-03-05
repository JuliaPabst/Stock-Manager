//
// Created by Petra Scheuer on 28.02.24.
//

#ifndef UEBUNG_1_SPIELABLAUF_H
#define UEBUNG_1_SPIELABLAUF_H

#include "Spielfeld.h"
#include "Enemy.h"
#include "Player.h"

class Spielablauf {
private:
    unsigned short int levelcount_;
public:
    static char startSequenz();
    static void clearscreen();
    static void fillSpielfeld(Spielfeld spielfeld[][5]);
    void Ausgabe(Spielfeld spielfeld[][5], Player player, Enemy enemy);
    bool reliktCheck(Spielfeld spielfeld[][5]);
    int Auswertung(Spielfeld spielfeld[][5], Player player);
    void respawn(Spielfeld spielfeld[][5]);
};


#endif //UEBUNG_1_SPIELABLAUF_H
