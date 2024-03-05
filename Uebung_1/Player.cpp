//
// Created by Petra Scheuer on 28.02.24.
//
#include <iostream>
#include "Player.h"
#include "Spielfeld.h"

//Setter
void Player::setLifepoints(unsigned short int lifepoints){
    lifepoints_=lifepoints;
}
void Player::setReliktpoints(int reliktpoints){
    reliktpoints_=reliktpoints;
}
unsigned short int Player::getLifepoints()const{
    return lifepoints_;
}
unsigned short int Player::getReliktpoints()const{
    return reliktpoints_;
}
void Player::incrementLifepoints(){
    lifepoints_++;
}
void Player::decrementLifepoints(){
    lifepoints_--;
}
void Player::incrementReliktpoints(){
    reliktpoints_++;
}
void Player::movePlayer(Spielfeld spielfeld[][5], char input){
    switch(input){
        default:
            std::cout << "Invalider Input - bitte gib einen validen Input ein."<<std::endl;
            break;
    case 'U':
    case 'u':
        decrementX();
        break;
    case 'D':
    case 'd':
        incrementX();
        break;
    case 'R':
    case 'r':
        incrementY();
        break;
    case 'L':
    case 'l':
        decrementY();
        break;
    }
    auswirkungen(spielfeld);
}

void Player::auswirkungen(Spielfeld spielfeld[][5]){
    char aktuellerTyp = spielfeld[getPositionX()][getPositionY()].getTyp();
    switch(aktuellerTyp){
        case '_':
            spielfeld[getPositionX()][getPositionY()].setTyp('_');
            break;
        case '#':
            if ((rand() % 6) == 0) {
                decrementLifepoints();
                std::cout << "Du hast ein Leben verloren! Aktuelle Lebenspunkte: " << getLifepoints() << std::endl;
            }
            spielfeld[getPositionX()][getPositionY()].setTyp('_');
            break;
        case '@':
            incrementLifepoints();
            spielfeld[getPositionX()][getPositionY()].setTyp('_');
            break;
        case '*':
            incrementReliktpoints();
            spielfeld[getPositionX()][getPositionY()].setTyp('_');
            break;
    }
}