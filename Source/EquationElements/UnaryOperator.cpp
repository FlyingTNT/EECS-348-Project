/**
 * UnaryOperator.cpp
 * Purpose: Implement methods of UnaryOperator subclasses.
 * Author: Vivian Lara
 * Date Created: 2023-11-27
*/

#include "UnaryOperator.hpp"
#include <stdexcept>

//Negation Implementation

/**
 * Performs negation on given value.
 * @param operand The integer to be negated.
 * @param ignored Ignored. Only here for polymorphism.
 * @returns The result of the negation.
 * @throws std::runtime_error If given a nullptr.
*/
int Negation::getValue(EquationElement* operand, EquationElement* ignored) 
{
    if(operand == nullptr)//If it is given a nullptr,
    {
        throw std::runtime_error("missing operand!");
    }

    int value = operand->getValue(nullptr, nullptr);
    return -value;
}

/**
 * Implements the getPriority method to follow the order of operations.
 * Returns Negation's priority as 1
*/
int Negation::getPriority() 
{
    return 1; 
}

/**
 * Implements the getSymbol method to use in stream insertion method.
 * Returns "-".
*/
std::string Negation::getSymbol() 
{
    return "-";
}

//AbsoluteValue Implementation

/**
 * Finds the Absolute Value of a given value.
 * @param operand The integer to be evaluated.
 * @param ignored Ignored. Only here for polymorphism.
 * @returns The result of the Absolute Value operation.
 * @throws std::runtime_error If given a nullptr.
*/
int AbsoluteValue::getValue(EquationElement* operand, EquationElement* ignored) 
{
    if(operand == nullptr)//If it is given a nullptr,
    {
        throw std::runtime_error("missing operand!");
    }

    int value = operand->getValue(nullptr, nullptr);
    //if the value is less than 0 (negative), then its absolute value is its negation
    //otherwise, the positive value is equal to the absolue value
    return (value < 0) ? -value : value;
}

/**
 * Implements the getPriority method to follow the order of operations.
 * Returns AbsoluteValue;s priority as 1
*/
int AbsoluteValue::getPriority() 
{
    return 1;
}

/**
 * Implements the getSymbol method to use in stream insertion method.
 * Returns "+".
*/
std::string AbsoluteValue::getSymbol() 
{
    return "+";
}
