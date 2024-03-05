// Spielfeld.h

#ifndef UEBUNG_1_SPIELFELD_H
#define UEBUNG_1_SPIELFELD_H

class Spielfeld {
private:
    char typ;
    bool betreten;

public:
    // Constructor
    Spielfeld();

    // Getter for 'typ'
    char getTyp() const;

    // Setter for 'typ'
    void setTyp(char newTyp);

    // Getter for 'betreten'
    bool getisBetreten() const;

    // Setter for 'betreten'
    void setisBetreten(bool newBetreten);
};

#endif // UEBUNG_1_SPIELFELD_H
