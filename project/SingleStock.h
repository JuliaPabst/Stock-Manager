#ifndef ALGO_P1_SINGLESTOCK_H
#define ALGO_P1_SINGLESTOCK_H
#include <iostream>
#include "DayPerformance.h"

using namespace std;

class SingleStock {
public:
    SingleStock(string name, string wkn, string abbreviation, const DayPerformance& performance);
    string getName() const;
    string getWkn() const;
    string getAbbreviation() const;
    const DayPerformance& getPerformance() const;
    int getHashValue() const;
    void printData() const;
    unsigned long hashFunction();

private:
    string name_;
    string wkn_;
    string abbreviation_;
    DayPerformance performance_;
    int hashValue_;

};


#endif //ALGO_P1_SINGLESTOCK_H
