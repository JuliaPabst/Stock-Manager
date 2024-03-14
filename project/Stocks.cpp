#include "Stocks.h"

Stocks::Stocks() :  tableSize_(1334), stocks_(tableSize_) {
}

SingleStock* Stocks::findStock(const string& name) {
    int hashValue = hashFunction(name) % tableSize_;  // Compute hash index correctly
    for (auto& stock : stocks_[hashValue]) {  // Look in the correct bucket
        if (stock.getName() == name) {
            return &stock;
        }
    }
    return nullptr;
}

int Stocks::quadraticProbing(int hash, int i, int tableSize) {
        return (hash + i * i) % tableSize_;
}

// djb2-Hashfunktion
unsigned long Stocks::hashFunction(string name) const{
    unsigned long hash = 5381;
    char current = ' ';
    for (int i = 0;  current != '\0'; i++) {
        current = name[i];
        hash = ((hash << 5) + hash) + current; // hash * 33 + c
    }

    return hash;
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
