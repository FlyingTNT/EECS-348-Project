/**
 * BinaryOperator.hpp
 * Purpose: A class to represent binary operators, with its respective specific subclasses.
 * Author: Vivian Lara
 * Date Created: 2023-11-27
*/

#ifndef BINARY_OPERATOR_H
#define BINARY_OPERATOR_H
#include "EquationElement.hpp"

/**
* An operator in the equation with two operands (preceding and proceeding).
*/
class BinaryOperator : public EquationElement 
{
public:
    virtual double getValue(EquationElement* preceding, EquationElement* proceeding) override = 0;
    virtual int getPriority() override = 0;
    virtual std::string getSymbol() override = 0;
};

/**
 * Represented with the “+” symbol. Its value equals the sum of its operands.
*/
class Addition : public BinaryOperator 
{
public:
    double getValue(EquationElement* preceding, EquationElement* proceeding) override;
    int getPriority() override;
    std::string getSymbol() override;
};

/**
 * Represented with the  “-” symbol. Its value equals the difference between its first operand and its second.
*/
class Subtraction : public BinaryOperator 
{
public:
    double getValue(EquationElement* preceding, EquationElement* proceeding) override;
    int getPriority() override;
    std::string getSymbol() override;
};

/**
 * Represented with the “*” symbol. Its value equals the product of its operands.
*/
class Multiplication : public BinaryOperator 
{
public:
    double getValue(EquationElement* preceding, EquationElement* proceeding) override;
    int getPriority() override;
    std::string getSymbol() override;
};

/**
 * Represented with the “/” symbol.
 * Its value equals the quotient of its first and second operands, truncating any fractional values.
 * If its second operand is zero, an error exists.
*/
class Division : public BinaryOperator 
{
public:
    double getValue(EquationElement* preceding, EquationElement* proceeding) override;
    int getPriority() override;
    std::string getSymbol() override;
};

/**
 * Represented with the “%” symbol. Its value equals the value of its first operand mod its second,
 * or the remainder of its first operand divided by its second.
 * If its second operand is zero, an error exists.
*/
class Modulo : public BinaryOperator 
{
public:
    double getValue(EquationElement* preceding, EquationElement* proceeding) override;
    int getPriority() override;
    std::string getSymbol() override;
};

/**
 * Represented with the “^” symbol. Its value equals its first operand to the power of its second operand,
 * or one multiplied by its first operand a number of times equal to its second operand. 
 * The second operand may not be negative; if it is, an error exists.
*/
class Exponentiation : public BinaryOperator 
{
public:
    double getValue(EquationElement* preceding, EquationElement* proceeding) override;
    int getPriority() override;
    std::string getSymbol() override;
};

#endif
