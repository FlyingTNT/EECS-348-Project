/**
 * NumericValue.cpp
 * Purpose: Implementation of the class defined in NumericValue.hpp
 * Author: C. Cooper
 * Date Created: 2023-11-28
*/

#include "NumericValue.hpp"
#include <string>
#include <sstream>
#include <iomanip>

/**
 * Creates a NumericValue representing the given float.
 * @param value The value of this EquationElement.
*/
NumericValue::NumericValue(double value)
{
    this->value = value;
}

/**
 * Gets the value of this number. Just returns the value passed in its constructor.
 * @param preceding Ignored. Only here for polymorphism.
 * @param proceeding Ignored. Only here for polymorphism.
 * @returns The value of this number.
*/
double NumericValue::getValue(EquationElement* preceding, EquationElement* proceeding)
{
    return value;
}

/**
 * Gets the priority of this element.
 * For a NumericValue, this is 0.
 * @returns The priority of this element (0).
*/
int NumericValue::getPriority()
{
    return 0;
}

/**
 * Returns a string representation of this element. 
 * This is just the double that it contains, to three places.
 * @returns A string representation of this element
*/
std::string NumericValue::getSymbol() 
{
    //This code taken from https://stackoverflow.com/questions/29200635/convert-float-to-string-with-precision-number-of-decimal-digits-specified
    std::stringstream stream;
    stream << std::fixed << std::setprecision(3) << value;
    return stream.str();
}
