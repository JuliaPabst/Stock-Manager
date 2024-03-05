//
// Created by Petra Scheuer on 28.02.24.
//

#ifndef UEBUNG_1_CHARAKTER_H
#define UEBUNG_1_CHARAKTER_H


class Charakter {
private:
    unsigned short int position_x;
    unsigned short int position_y;
    char sign_;

public:
    Charakter(unsigned short int x, unsigned short int y,char sign) : position_x(x), position_y(y), sign_(sign) {};
    //getter
    unsigned short int getPositionX() const;
    unsigned short int getPositionY() const;
    char getSign();
    //setter
    void setPositionX(unsigned short int x);
    void setPositionY(unsigned short int y);
    void setSign(char sign);
    void incrementX();
    void incrementY();
    void decrementY();
    void decrementX();
};


#endif //UEBUNG_1_CHARAKTER_H
