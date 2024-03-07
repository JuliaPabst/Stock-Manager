#include "SingleStock.h"

SingleStock::SingleStock(string name, string wkn, string abbreviation, const DayPerformance& performance)
: name_(name), wkn_(wkn), abbreviation_(abbreviation), performance_(performance), hashValue_(hashFunction()) {}

string SingleStock::getName() const {
    return name_;}

string SingleStock::getWkn() const {
    return wkn_; }

string SingleStock::getAbbreviation() const {
    return abbreviation_; }

const DayPerformance& SingleStock::getPerformance() const {
    return performance_; }

int SingleStock::getHashValue() const {
    return hashValue_; }

void SingleStock::printData() const {
    cout << "Name: " << getName() << endl;
    cout << "WKN: " << getWkn() << endl;
    cout << "Abbreviation: " << getAbbreviation() << endl;
    cout << "Day Performance:" << endl;
    cout << "  Date: " << getPerformance().getDay() << "." << getPerformance().getMonth() << "." << SingleStock::getPerformance().getYear() << endl;
    cout << "  Open: " << getPerformance().getOpen() << endl;
    cout << "  High: " << getPerformance().getHigh() << endl;
    cout << "  Low: " << getPerformance().getLow() << endl;
    cout << "  Close: " << getPerformance().getClose() << endl;
    cout << "  Adj Close: " << getPerformance().getAdjClose() << endl;
    cout << "  Volume: " << getPerformance().getVolume() << endl;
    cout << "Hash Value: " << getHashValue() << endl;
    cout << "-------------------------" << endl;
}

// djb2-Hashfunktion
unsigned long SingleStock::hashFunction() {
    unsigned long hash = 5381;
    for (char c : name_) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash;
}