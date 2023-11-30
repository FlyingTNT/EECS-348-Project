/**
 * UnaryOperator.hpp
 * Purpose: Class to represent unary operators, with specific subclasses.
 * Author: Vivian Lara
 * Date Created: 2023-11-27
*/
#ifndef UNARY_OPERATOR_H
#define UNARY_OPERATOR_H

#include "EquationElement.hpp"

/**
 * An operator in the equation with a single operand. The operator proceeds its operand.
*/
class UnaryOperator : public EquationElement 
{
public:
    virtual float getValue(EquationElement* ignored, EquationElement* operand) override = 0;
    virtual int getPriority() override = 0;
    virtual std::string getSymbol() override = 0;
};

/**
 * Represented with the “-” symbol. Its value equals the value of its operand, multiplied by negative one.  
*/
class Negation : public UnaryOperator 
{
public:
    float getValue(EquationElement* ignored, EquationElement* operand) override;
    int getPriority() override;
    std::string getSymbol() override;
};

/**
 * Represented with the “+” symbol. Its value equals the absolute value of its operand, or the square root of the square of its operand.
*/
class AbsoluteValue : public UnaryOperator 
{
public:
    float getValue(EquationElement* ignored, EquationElement* operand) override;
    int getPriority() override;
    std::string getSymbol() override;
};

#endif
