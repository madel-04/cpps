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

/*    class FileException : public std::runtime_error {
    public:
        explicit FileException(const std::string& message) : std::runtime_error(message) {}
    };

    class DateException : public std::runtime_error {
    public:
        explicit DateException(const std::string& message) : std::runtime_error(message) {}
    };

    class ValueException : public std::runtime_error {
    public:
        explicit ValueException(const std::string& message) : std::runtime_error(message) {}*/

};

#endif