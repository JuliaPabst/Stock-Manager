#include "Charakter.h"
// Created by Petra Scheuer on 28.02.24.

//getter
unsigned short int Charakter::getPositionX() const{
    return position_x;
}
unsigned short int Charakter::getPositionY() const{
    return position_y;
}
char Charakter::getSign(){
    return sign_;
}

//setter
void Charakter::setPositionX(unsigned short int x){
    position_x=x;
}
void Charakter::setPositionY(unsigned short int y){
    position_y=y;
}
void Charakter::setSign(char sign){
    sign_=sign;
}
void Charakter::incrementX(){
    unsigned short int x= getPositionX();
    x++;
    if(x ==5){
        x=0;
    }
    setPositionX(x);

}
void Charakter::incrementY(){
    unsigned short int y= getPositionY();
    y++;
    if(y ==5){
        y=0;
    }
    setPositionY(y);

}
void Charakter::decrementY(){
    unsigned short int y= getPositionY();

    if(y ==0){
        y=4;
    }
    else{
        y--;
    }
    setPositionY(y);
}
void Charakter::decrementX(){
    unsigned short int x= getPositionX();

    if(x ==0){
        x=4;
    }
    else{
        x--;
    }
    setPositionX(x);
}

