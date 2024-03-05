//
// Created by Petra Scheuer on 28.02.24.
//
#include "Spielablauf.h"
#include <iostream>

char Spielablauf::startSequenz() {
    std::string Playersname;
    std::cout << "Willkommen beim Oasen Crawler. Bitte gib deinen Namen ein" << std::endl;
    while (true) {
        if (std::getline(std::cin, Playersname)) {
            if (!Playersname.empty()) {
                std::cout << "Hallo " << Playersname << std::endl << std::endl;
                break; // Eingabe war gültig, die Schleife wird verlassen
            } else {
                std::cout << "Ungültige Eingabe. Bitte gib einen gültigen Namen ein." << std::endl;
            }
        } else {
            // Fehler beim Einlesen der Eingabe
            std::cin.clear(); // Fehlerzustand zurücksetzen
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Puffer leeren
            std::cout << "Fehler bei der Eingabe. Bitte versuche es erneut." << std::endl;
        }
    }
    return Playersname[0];
}
void Spielablauf::clearscreen() {
#ifdef _WIN32
        system("cls");
#else
        system("clear");
#endif

}
void Spielablauf::fillSpielfeld(Spielfeld spielfeld[][5]) {
    int wahrscheinlichkeiten[4]={40,40,10,10};
    unsigned short int reliktcount =0;
    while(67){
        for (unsigned short int i = 0; i < 5; ++i) {
            for (unsigned short int j = 0; j < 5; ++j) {
                int zufallszahl = rand() % 100 + 1;
                if (zufallszahl <= wahrscheinlichkeiten[0]) {
                    spielfeld[i][j].setTyp('_'); //leeres Spielfeld
                    spielfeld[i][j].setisBetreten(false);
                } else if (zufallszahl <= wahrscheinlichkeiten[0] + wahrscheinlichkeiten[1]) {
                    spielfeld[i][j].setTyp('#');
                    spielfeld[i][j].setisBetreten(false);
                } else if (zufallszahl <= wahrscheinlichkeiten[0] + wahrscheinlichkeiten[1] + wahrscheinlichkeiten[2]) {
                    spielfeld[i][j].setTyp('@');
                    spielfeld[i][j].setisBetreten(false);
                } else{
                    spielfeld[i][j].setTyp('*');
                    spielfeld[i][j].setisBetreten(false);
                    reliktcount++;
                }
            }
        }
        if(reliktcount !=0){
            break;
        }
        else{
            continue;
        }
    }
}
void Spielablauf::Ausgabe(Spielfeld spielfeld[][5], Player player, Enemy enemy) {
    std::cout << "Leben: " << player.getLifepoints() << std::endl;
    std::cout << "Gesammelte Relikte: " << player.getReliktpoints() << std::endl;


    for (unsigned short int i = 0; i < 5; ++i) {
        for (unsigned short int j = 0; j < 5; ++j) {
            if (player.getPositionX() == i && player.getPositionY() == j) {
                std::cout << player.getSign();
            } else if (enemy.getPositionX() == i && enemy.getPositionY() == j) {
                std::cout << enemy.getSign();
            } else {
                std::cout << spielfeld[i][j].getTyp();
            }
        }
        std::cout << std::endl;
    }
}

bool Spielablauf::reliktCheck(Spielfeld spielfeld[][5]){
    for (unsigned short int i = 0; i < 5; ++i) {
        for (unsigned short int j = 0; j < 5; ++j) {
            if (spielfeld[i][j].getTyp() == '*') {
                return true;  // Es gibt noch ein Relikt im Spielfeld
            }
        }
    }
    return false;  // Kein Relikt im Spielfeld gefunden
}

int Spielablauf::Auswertung(Spielfeld spielfeld[][5],Player player){
    if(reliktCheck(spielfeld) == false){
        std::cout << "Du hast Level "<< levelcount_ <<" gewonnen!"<<std::endl;
        levelcount_++;
        player.setLifepoints(5);
        respawn(spielfeld);

    }
    if (player.getLifepoints() == 0) {
        std::cout << "GAME OVER!"<< std::endl;
        return 0;
    }
}
void Spielablauf::respawn(Spielfeld spielfeld[][5]) {
    int wahrscheinlichkeiten[4] = {40, 40+(levelcount_), 10-(levelcount_), 10}; //je höher das Level desto mehr gefahrenfelder, desto weniger brunnen
    unsigned short int reliktcount = 0;

    for (unsigned short int i = 0; i < 5; ++i) {
        for (unsigned short int j = 0; j < 5; ++j) {
            int zufallszahl = rand() % 100 + 1;
            if (zufallszahl <= wahrscheinlichkeiten[0]) {
                spielfeld[i][j].setTyp('_'); // leeres Spielfeld
                spielfeld[i][j].setisBetreten(false);
            } else if (zufallszahl <= wahrscheinlichkeiten[0] + wahrscheinlichkeiten[1]) {
                spielfeld[i][j].setTyp('#');
                spielfeld[i][j].setisBetreten(false);
            } else if (zufallszahl <= wahrscheinlichkeiten[0] + wahrscheinlichkeiten[1] + wahrscheinlichkeiten[2]) {
                spielfeld[i][j].setTyp('@');
                spielfeld[i][j].setisBetreten(false);
            } else {
                spielfeld[i][j].setTyp('*');
                spielfeld[i][j].setisBetreten(false);
                reliktcount++;
            }
        }
    }
}
