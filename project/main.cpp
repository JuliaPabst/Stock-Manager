#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "DayPerformance.h"
#include "SingleStock.h"

using namespace std;

int main() {

    //File reading
    ifstream file("ALGO.csv");
    if (!file.is_open()) {
        cerr << "Konnte die Datei nicht öffnen!" << endl;
        return 1;
    } else {
        cout << "Datei erfolgreich geöffnet!" << endl;
    }

    string line;
    getline(file, line);  // Ignoriere die erste Zeile (Überschrift)

    vector<SingleStock> stocks;

    while (getline(file, line)) {
        replace(line.begin(), line.end(), ',', '.');
        replace(line.begin(), line.end(), ';', ',');

        vector<string> tokens;
        istringstream tokenStream(line);
        string token;

        while (getline(tokenStream, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() >= 8) {
            int day, month, year;
            sscanf(tokens[0].c_str(), "%d.%d.%d", &day, &month, &year);

            DayPerformance dayPerformance(day, month, year,
                                          stod(tokens[1]), std::stod(tokens[2]), std::stod(tokens[3]),
                                          stod(tokens[4]), std::stoi(tokens[6]), std::stod(tokens[5]));

            SingleStock stock(tokens[8], "", "", dayPerformance);  // Dummy-Werte für WKN und Abkürzung, kann angepasst werden
            stocks.push_back(stock);
        }
    }

    file.close();

    for (const auto& stock : stocks) {
        stock.printData();
    }

    return 0;
}

