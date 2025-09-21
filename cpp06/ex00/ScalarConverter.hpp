#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter {
public:
    static void convert(const std::string& literal);

private:
    ScalarConverter(); // no instanciable
    ScalarConverter(ScalarConverter const &);
    ScalarConverter& operator=(ScalarConverter const &);
    ~ScalarConverter();
};

#endif // SCALARCONVERTER_HPP
