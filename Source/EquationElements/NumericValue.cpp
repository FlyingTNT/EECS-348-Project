/**
 * NumericValue.cpp
 * Purpose: Implementation of the class defined in NumericValue.hpp
 * Author: C. Cooper
 * Date Created: 2023-11-25
*/

#include "NumericValue.hpp"
#include <string>

/**
 * Creates a NumericValue representing the given integer.
 * @param value The value of this EquationElement.
*/
NumericValue::NumericValue(int value)
{
    this->value = value;
}

/**
 * Gets the value of this number. Just returns the value passed in its constructor.
 * @param preceding Ignored. Only here for polymorphism.
 * @param proceeding Ignored. Only here for polymorphism.
 * @returns The value of this number.
*/
int NumericValue::getValue(EquationElement* preceding, EquationElement* proceeding)
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
 * This is just the integer that it contains.
 * @returns A string representation of this element
*/
std::string NumericValue::getSymbol() 
{
    return std::to_string(value);//Uses to_string to get a string repr of the value.
}