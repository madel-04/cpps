#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <string>
#include <sstream>

class RPN
{
private:
    std::stack<int> _stack;

public:
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();

    int evaluate(const std::string &expression);
};

#endif

/*
El contendor tiene funcionalidad LIFO (Last In, First Out)
Por defecto usa std::deque internamiente, y solo permite el acceso
al elemento superior (top)
No permite la iteración ni acceso aleatorio

Se usa este contenedor xq el último operando es el primero que se usa
*/