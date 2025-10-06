#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &other) { *this = other; }
RPN &RPN::operator=(const RPN &other)
{
    if (this != &other)
        this->_stack = other._stack;
    return *this;
}
RPN::~RPN() {}

int RPN::evaluate(const std::string &expression)
{
    std::istringstream ss(expression);
    std::string token;

    while (ss >> token)
    {
        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (_stack.size() < 2)
                throw std::runtime_error("Error: insufficient operands.");

            int b = _stack.top(); _stack.pop();
            int a = _stack.top(); _stack.pop();
            int result;

            if (token == "+") result = a + b;
            else if (token == "-") result = a - b;
            else if (token == "*") result = a * b;
            else
            {
                if (b == 0)
                    throw std::runtime_error("Error: division by zero.");
                result = a / b;
            }

            _stack.push(result);
        }
        else
        {
            std::istringstream val(token);
            int num;
            val >> num;

            if (val.fail() || num < 0 || num >= 10)
                throw std::runtime_error("Error: invalid number.");

            _stack.push(num);
        }
    }

    if (_stack.size() != 1)
        throw std::runtime_error("Error");

    return _stack.top();
}
