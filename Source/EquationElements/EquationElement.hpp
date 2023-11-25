/**
 * EquationElement.hpp
 * Purpose: A class to represent a token in an equation.
 * Author: C. Cooper
 * Date Created: 2023-11-22
*/

#ifndef EQUATION_EMENENT_H
#define EQUATION_EMENENT_H
#include <string>

/**
 * An item in an equation, such as a number or an operation.
*/
class EquationElement
{
    public:
    virtual int getValue(EquationElement& preceding, EquationElement& proceeding) = 0;//Passes by reference
    virtual int getPriority() = 0;
    virtual std::string getSymbol();
    friend std::ostream& operator << (std::ostream& stream, EquationElement& element);
};

#endif