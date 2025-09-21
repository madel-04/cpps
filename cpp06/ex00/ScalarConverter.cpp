#include "ScalarConverter.hpp"
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <iomanip>
#include <limits>
#include <cmath>


// Funciones auxiliares para detectar el tipo
namespace {
    bool isCharLiteral(const std::string& s) {
        return s.size() == 1 && !std::isdigit(s[0]);
    }

    bool isIntLiteral(const std::string& s) {
        size_t i = 0;
        if (s[i] == '+' || s[i] == '-') i++;
        if (i >= s.size()) return false;
        for (; i < s.size(); i++) {
            if (!std::isdigit(s[i])) return false;
        }
        return true;
    }

    bool isFloatLiteral(const std::string& s) {
        if (s == "nanf" || s == "+inff" || s == "-inff") return true;
        if (s.back() != 'f') return false;
        bool hasDot = false;
        for (size_t i = 0; i < s.size()-1; i++) {
            if (s[i] == '.') hasDot = true;
            else if (!std::isdigit(s[i]) && s[i] != '+' && s[i] != '-') return false;
        }
        return hasDot;
    }

    bool isDoubleLiteral(const std::string& s) {
        if (s == "nan" || s == "+inf" || s == "-inf") return true;
        bool hasDot = false;
        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == '.') hasDot = true;
            else if (!std::isdigit(s[i]) && s[i] != '+' && s[i] != '-') return false;
        }
        return hasDot;
    }
}

static void printChar(double value) {
    std::cout << "char: ";
    if (std::isnan(value) || value < 0 || value > 127) {
        std::cout << "impossible\n";
    } else if (!isprint(static_cast<int>(value))) {
        std::cout << "Non displayable\n";
    } else {
        std::cout << "'" << static_cast<char>(value) << "'\n";
    }
}

static void printInt(double value) {
    std::cout << "int: ";
    if (std::isnan(value) || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min()) {
        std::cout << "impossible\n";
    } else {
        std::cout << static_cast<int>(value) << "\n";
    }
}

static void printFloat(double value) {
    std::cout << "float: ";
    float f = static_cast<float>(value);
    if (std::isnan(f))
        std::cout << "nanf\n";
    else if (std::isinf(f))
        std::cout << (f > 0 ? "+inff\n" : "-inff\n");
    else {
        std::cout << std::fixed << std::setprecision((f == static_cast<int>(f)) ? 1 : 6);
        std::cout << f << "f\n";
    }
}

static void printDouble(double value) {
    std::cout << "double: ";
    if (std::isnan(value))
        std::cout << "nan\n";
    else if (std::isinf(value))
        std::cout << (value > 0 ? "+inf\n" : "-inf\n");
    else {
        std::cout << std::fixed << std::setprecision((value == static_cast<int>(value)) ? 1 : 6);
        std::cout << value << "\n";
    }
}

void ScalarConverter::convert(const std::string& literal) {
    double value = 0.0;

    try {
        if (isCharLiteral(literal))
            value = static_cast<double>(literal[0]);
        else if (isIntLiteral(literal))
            value = static_cast<double>(std::stoi(literal));
        else if (isFloatLiteral(literal))
            value = static_cast<double>(std::stof(literal));
        else if (isDoubleLiteral(literal))
            value = static_cast<double>(std::stod(literal));
        else {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: impossible\n";
            std::cout << "double: impossible\n";
            return;
        }
    } catch (std::exception&) {
        std::cout << "char: impossible\n";
        std::cout << "int: impossible\n";
        std::cout << "float: impossible\n";
        std::cout << "double: impossible\n";
        return;
    }

    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

/*
void ScalarConverter::convert(const std::string& literal) {
    double value = 0.0;

    try {
        if (isCharLiteral(literal)) {
            value = static_cast<double>(literal[0]);
        }
        else if (isIntLiteral(literal)) {
            // usar stoll para no perder rango y luego castearlo a double
            long long tmp = std::stoll(literal);
            value = static_cast<double>(tmp);
        }
        else if (isFloatLiteral(literal)) {
            value = static_cast<double>(std::stof(literal));
        }
        else if (isDoubleLiteral(literal)) {
            value = static_cast<double>(std::stod(literal));
        }
        else {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: impossible\n";
            std::cout << "double: impossible\n";
            return;
        }
    }
    catch (std::exception&) {
        // OJO: aquí no abortes todas las conversiones
        // intenta parsear con stod como último recurso
        try {
            value = std::stod(literal);
        } catch (...) {
            std::cout << "char: impossible\n";
            std::cout << "int: impossible\n";
            std::cout << "float: impossible\n";
            std::cout << "double: impossible\n";
            return;
        }
    }

    // imprimir con las funciones auxiliares
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}
*/
