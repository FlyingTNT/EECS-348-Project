/**
 * NumericValue.hpp
 * Purpose: A class to represent a double value in an equation.
 * Author: C. Cooper
 * Date Created: 2023-11-28
*/

#ifndef NUMERIC_VAL_H
#define NUMERIC_VAL_H

#include "EquationElement.hpp"
#include <string>

/**
 * Represents a constant floating point value in an equation.
*/
class NumericValue : public EquationElement
{
    private:
    double value;

    public:
    NumericValue(double);
    double getValue(EquationElement*, EquationElement*) override;
    int getPriority() override;
    std::string getSymbol() override;
};

#endif