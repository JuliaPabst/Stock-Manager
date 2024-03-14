#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include "DayPerformance.h"
#include "SingleStock.h"
#include "Stocks.h"

using namespace std;

int main() {

    // add single stock
    Stocks allStocks;
    DayPerformance dummyPerformance(0, 0, 0, 0, 0, 0, 0, 0, 0);

    /*
    SingleStock newStock("", "", "", dummyPerformance);
    newStock.importData();
    //newStock.printData();
    allStocks.addToHashTable(newStock);
    cout << "another one" << endl;
    SingleStock anotherStock("", "", "", dummyPerformance);
    anotherStock.importData();
    //anotherStock.printData();
    allStocks.addToHashTable(anotherStock);

    allStocks.printAll();
    */

/*
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
            allStocks.addToHashTable(stock);
        }
    }


    file.close();
    allStocks.printAll();
*/

    std::ifstream file("ALGO.csv");
    if (!file.is_open()) {
        std::cerr << "Konnte die Datei nicht öffnen!" << std::endl;
        return 1;
    } else {
        std::cout << "Datei erfolgreich geöffnet!" << std::endl;
    }

    std::string line;
    std::getline(file, line);  // Ignoriere die erste Zeile (Überschrift)

    std::vector<SingleStock> stocks;
    int lineNumber = 0;  // Startet mit 0, da die erste Datenzeile als Zeile 1 zählt

    while (std::getline(file, line)) {
        lineNumber++;  // Aktualisiere die Zeilennummer für jede gelesene Zeile

        // Zeilennummer-basierte Abkürzungs(Zeichencode)-Zuweisung
        std::string abbreviation;
        std::string name;

        if (lineNumber >= 1 && lineNumber <= 250) {
            abbreviation = "MSFT";
            name = "Microsoft Corporation";
        } else if (lineNumber >= 251 && lineNumber <= 504) {
            abbreviation = "RY4C";
            name = "Ryanair Holding";
        } else if (lineNumber >= 505 && lineNumber <= 755) {
            abbreviation = "TSLA";
            name = "Tesla, Inc.";
        } else if (lineNumber >= 756 && lineNumber <= 1008) {
            abbreviation = "PKTM";
            name = "PIERER Mobility AG";
        }

        std::replace(line.begin(), line.end(), ',', '.');
        std::replace(line.begin(), line.end(), ';', ',');

        std::vector<std::string> tokens;
        std::istringstream tokenStream(line);
        std::string token;

        while (std::getline(tokenStream, token, ',')) {
            tokens.push_back(token);
        }

        if (tokens.size() >= 8) {
            int day, month, year;
            sscanf(tokens[0].c_str(), "%d.%d.%d", &day, &month, &year);

            DayPerformance dayPerformance(day, month, year,
                                          std::stod(tokens[1]), std::stod(tokens[2]), std::stod(tokens[3]),
                                          std::stod(tokens[4]), std::stoi(tokens[6]), std::stod(tokens[5]));

            SingleStock stock(name, "", abbreviation, dayPerformance);  // Verwende abbreviation für die Abkürzung, has Value == HASH VALUE

            SingleStock* existingStock = allStocks.findStock(stock.getName());
            if (existingStock) {
                existingStock->addPerformance(dayPerformance);

            } else {
                allStocks.addToHashTable(stock);
            }
        }
    }

    file.close();

    /*for (const auto& stock : stocks) {
        stock.printData();
    } */

    allStocks.printAll();
    return 0;
}

