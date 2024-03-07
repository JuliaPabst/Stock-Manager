#include "SingleStock.h"

SingleStock::SingleStock(string name, string wkn, string abbreviation, const DayPerformance& performance)
: name_(name), wkn_(wkn), abbreviation_(abbreviation), performance_(performance), hashValue_(0){
}

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

void SingleStock::importData(){
    cout << "You are adding a new stock" << endl;
    cout << "Name: " << endl;
    cin >> name_;
    cout << "WKN: " << endl;
    cin >> wkn_;
    cout << "Abbreviation: " << endl;
    cin >> abbreviation_;
    hashValue_ = hashFunction();
}

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
unsigned long SingleStock::hashFunction() const{
    unsigned long hash = 5381;
    for (char c : name_) {
        hash = ((hash << 5) + hash) + c; // hash * 33 + c
    }
    return hash;
}