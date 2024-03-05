// Spielfeld.cpp
#include "Spielfeld.h"

    // Constructor
    Spielfeld::Spielfeld() {}

    // Getter for 'typ'
    char Spielfeld::getTyp() const {
        return typ;
    }

    // Setter for 'typ'
    void Spielfeld::setTyp(char newTyp) {
        typ = newTyp;
    }

    // Getter for 'betreten'
    bool Spielfeld::getisBetreten() const {
        return betreten;
    }

    // Setter for 'betreten'
    void Spielfeld::setisBetreten(bool newBetreten) {
        betreten = newBetreten;
    }



