#include "Stocks.h"

Stocks::Stocks() :  tableSize_(1334), stocks_(tableSize_) {
}

int Stocks::quadraticProbing(int hash, int i, int tableSize) {
        return (hash + i * i) % tableSize_;
}

void Stocks::addToHashTable(SingleStock newStock){
    int hashValue = newStock.getHashValue() % tableSize_;
    int i = 0;
    int index = quadraticProbing(hashValue, i, tableSize_);
    while (!stocks_[index].empty() && i < tableSize_) {
        i++;
        index = quadraticProbing(hashValue, i, tableSize_);
    }
    stocks_[index].push_back(newStock);
};

void Stocks::printAll() const {
    for (const auto& bucket : stocks_) {  // Iterate over each bucket in the hash table
        for (const auto& item : bucket) {  // Iterate over each item in the list
            item.printData();  // Print the item's data
        }
    }
}

void Stocks::deleteFromHashTable(){
};
