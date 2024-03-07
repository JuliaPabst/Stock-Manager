#ifndef ALGO_P1_HASHTABLE_H
#define ALGO_P1_HASHTABLE_H
#include <iostream>
#include <list>
#include <string>
using namespace std;


class Hashtable {
private:
    static const int hashGroups = 10;
    list<pair<int, string>> table[hashGroups];

};


#endif //ALGO_P1_HASHTABLE_H
