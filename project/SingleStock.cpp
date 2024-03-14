#include "SingleStock.h"

SingleStock::SingleStock(string name, string wkn, string abbreviation, const DayPerformance& performance)
: name_(name), wkn_(wkn), abbreviation_(abbreviation){
    hashValue_ = hashFunction();
    performance_.push_back(performance);
}

string SingleStock::getName() const {
    return name_;}

string SingleStock::getWkn() const {
    return wkn_; }

string SingleStock::getAbbreviation() const {
    return abbreviation_; }

vector<DayPerformance> SingleStock::getPerformance() const {
    return performance_; }

unsigned long SingleStock::getHashValue() const {
    return hashValue_; }

void SingleStock::addPerformance(const DayPerformance& performance) {
    performance_.push_back(performance);
}
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
    cout << "Name: " << name_ << endl;
    cout << "WKN: " << wkn_ << endl;
    cout << "Abbreviation: " << abbreviation_ << endl;
    cout << "Hash Value: " << hashValue_ << endl;
    cout << "-------------------------" << endl;
}

void SingleStock::printPerformance() const{

    for (const DayPerformance& performance : performance_){
        cout << "Name: " << name_ << endl;
        cout << "  Date: " << performance.getDay() << "." << performance.getMonth() << "." << performance.getYear() << endl;
        cout << "  Open: " << performance.getOpen() << endl;
        cout << "  High: " << performance.getHigh() << endl;
        cout << "  Low: " << performance.getLow() << endl;
        cout << "  Close: " << performance.getClose() << endl;
        cout << "  Adj Close: " << performance.getAdjClose() << endl;
        cout << "  Volume: " << performance.getVolume() << endl;
        cout << " " << endl;
    }
}

// djb2-Hashfunktion
unsigned long SingleStock::hashFunction() const{
    unsigned long hash = 5381;
    char current = ' ';
    for (int i = 0;  current != '\0'; i++) {
        current = name_[i];
        hash = ((hash << 5) + hash) + current; // hash * 33 + c
    }

    return hash;
}