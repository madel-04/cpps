#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <fstream>
#include <sstream>

class BitcoinExchange 
{
private:
    bool isValidDate(const std::string &date) const;

public:
std::map<std::string, float> _data;
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);

    void loadDatabase(const std::string& filename);
    float getExchangeRate(const std::string& date) const;
    void processInput(const std::string& inputFile) const;
};

#endif

/*
std::map es un árbol binario de búsqueda balanceado en el que cada nodo
tiene un par clave-valor
Las claves se ordenan alfabeticamente y se autobalancea para mantener
operaciones eficientes

*/