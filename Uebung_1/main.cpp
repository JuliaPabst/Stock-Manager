//Inculdes
#include <iostream>


//Klassenincludes
#include "Spielfeld.h"
#include "Player.h"
#include "Enemy.h"
#include "Spielablauf.h"

int main() {
    //Variablendeklaration
    const unsigned short int maxLength =5;
    char input = ' ';


    // Instanzen initialisieren
    Player myHero(0,0,' ',5,0);
    Enemy myEnemy(4,4,'E');
    Spielablauf Game{};

    //Spielfeld wird erstellt und danach die Startsequenz ausgeführt
    Spielfeld mySpielfeld[maxLength][maxLength];
    Game.fillSpielfeld (mySpielfeld);
    myHero.setSign(Game.startSequenz());

    while(67){
        if(input == 'X' || myHero.getLifepoints() == 0){
            break;
        }
        std::cout<<"UP(U),DOWN(D),RIGHT(R),LEFT(L) - END GAME(X)"<<std::endl<<std::endl;
        Game.Ausgabe(mySpielfeld, myHero, myEnemy);
        std::cin >> input;
        myHero.movePlayer(mySpielfeld, input);
        myEnemy.moveTowardsPlayer(myHero);
        Game.Auswertung(mySpielfeld,myHero);

        Game.clearscreen();
    }
    return 0;
}

