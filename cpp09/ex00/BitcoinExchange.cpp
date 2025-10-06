#include "BitcoinExchange.hpp"

// Constructor / Destructor
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        this->_data = other._data;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::isValidDate(const std::string &date) const
{
    if (date.length() != 10 || date[4] != '-' || date[7] != '-')
        return false;

    int year, month, day;
    char sep1, sep2;
    std::istringstream ss(date);
    ss >> year >> sep1 >> month >> sep2 >> day;

    if (ss.fail() || sep1 != '-' || sep2 != '-')
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    // Handle months with fewer than 31 days
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // Leap year check
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
        daysInMonth[1] = 29;

    if (day > daysInMonth[month - 1])
        return false;

    return true;
}


void BitcoinExchange::loadDatabase(const std::string &filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open database file.");

    std::string line;
    std::getline(file, line); // skip the header (e.g., "date,exchange_rate")

    while (std::getline(file, line))
    {
        std::istringstream ss(line);
        std::string date;
        std::string valueStr;

        if (std::getline(ss, date, ',') && std::getline(ss, valueStr))
        {
            try
            {
                std::istringstream valueStream(valueStr);
                float rate;
                valueStream >> rate;

                _data[date] = rate;
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error: invalid value in database => " << line << std::endl;
            }
        }
    }

    file.close();
}

float BitcoinExchange::getExchangeRate(const std::string &date) const
{
    std::map<std::string, float>::const_iterator it = _data.find(date);

    if (it != _data.end())
        return it->second;

    // If date not found, find closest lower date
    it = _data.lower_bound(date);

    if (it == _data.begin())
        throw std::runtime_error("Error: no earlier date in database.");

    --it; // move to the previous (earlier) date
    return it->second;
}

void BitcoinExchange::processInput(const std::string &inputFile) const
{
    std::ifstream file(inputFile.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    std::getline(file, line); // skip the first header line

    while (std::getline(file, line))
    {
        if (line.empty())
            continue;

        std::istringstream ss(line);
        std::string date;
        std::string valueStr;

        if (!std::getline(ss, date, '|') || !std::getline(ss, valueStr))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        // Trim spaces
        date.erase(0, date.find_first_not_of(" \t"));
        date.erase(date.find_last_not_of(" \t") + 1);
        valueStr.erase(0, valueStr.find_first_not_of(" \t"));
        valueStr.erase(valueStr.find_last_not_of(" \t") + 1);

        // Convert value
        std::istringstream valStream(valueStr);
        float value;
        valStream >> value;

        // Validate numeric value
        if (valStream.fail())
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value < 0)
        {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000)
        {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }

        try
        {
            if (!isValidDate(date))
            {
                std::cerr << "Error: bad input => " << date << std::endl;
                continue;
            }
            float rate = getExchangeRate(date);
            std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cerr << "Error: bad input => " << date << std::endl;
        }
    }

    file.close();
}
