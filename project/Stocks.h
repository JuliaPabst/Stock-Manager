#ifndef ALGO_P1_STOCKS_H
#define ALGO_P1_STOCKS_H
#import "SingleStock.h"
#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Stocks {
public:
    Stocks();
    int quadraticProbing(int hash, int i, int tableSize);
    void addToHashTable(SingleStock newStock);
    void deleteFromHashTable();
    void printAll() const;

private:
    int tableSize_;
    vector<list<SingleStock>> stocks_;
    void deleteFromHashList();
};


#endif //ALGO_P1_STOCKS_H
