/**
 * BinaryOperator.cpp
 * Purpose: Implement binary operator subclass methods.
 * Author: Vivian Lara
 * Date Created: 2023-11-27
*/

#include "BinaryOperator.hpp"
#include <stdexcept>
#include <cmath>
#include <cstring>

//Addition implementation

/**
 * Performs addition on its given operands.
 * @param firstOperand The operand preceeding the operator.
 * @param secondOperand The operand proceeding the operator.
 * @returns The result of the addition of the two values.
 * @throws std::runtime_error If given a nullptr
*/
double Addition::getValue(EquationElement* preceding, EquationElement* proceeding) 
{
    if(preceding == nullptr || proceeding == nullptr)//If it is given nullpointers,
    {
        /*
            There are basically two cases where this might happen:
            1. It is being treated as a NumericValue (operand). In this case, both will be nullpointers
            2. It is the first/last item in the equation. In this case, only one will be nullptr.
        */
        if(preceding == nullptr && preceding == nullptr)//If they are both nullptr,
        {
            throw std::runtime_error("cannot use operator as operand!");
        }
        //If only one is nullptr,
        throw std::runtime_error(getSymbol() + " is missing an operand!");
    }

    double firstOperand;
    double secondOperand;
    try
    {
        firstOperand = preceding->getValue(nullptr, nullptr);
        secondOperand = proceeding->getValue(nullptr, nullptr);
    }catch(std::runtime_error err)
    {
        if(std::strcmp(err.what(), "cannot use operator as operand!") == 0)//If the error is because one of the operands is actually an operator,
        {
            throw std::runtime_error(getSymbol() + " is missing an operand!");
        }
        //Otherwise,
        throw err;//Just pass the error on.
    }

    return firstOperand + secondOperand;
}

/**
 * Implements the getPriority method to follow the order of operations.
 * Returns Addition's priority as 1
*/
int Addition::getPriority() 
{
    return 1;
}

/**
 * Implements the getSymbol method to use in stream insertion method.
 * Returns "+".
*/
std::string Addition::getSymbol() 
{
    return "+";
}

//Subtraction implementation

/**
 * Performs subtraction on its given operands.
 * @param firstOperand The operand preceeding the operator.
 * @param secondOperand The operand proceeding the operator.
 * @returns The result of the subtraction of the two values.
 * @throws std::runtime_error If given a nullptr.
*/
double Subtraction::getValue(EquationElement* preceding, EquationElement* proceeding) 
{
    if(preceding == nullptr || proceeding == nullptr)//If it is given nullpointers,
    {
        /*
            There are basically two cases where this might happen:
            1. It is being treated as a NumericValue (operand). In this case, both will be nullpointers
            2. It is the first/last item in the equation. In this case, only one will be nullptr.
        */
        if(preceding == nullptr && preceding == nullptr)//If they are both nullptr,
        {
            throw std::runtime_error("cannot use operator as operand!");
        }
        //If only one is nullptr,
        throw std::runtime_error(getSymbol() + " is missing an operand!");
    }

    double firstOperand;
    double secondOperand;
    try
    {
        firstOperand = preceding->getValue(nullptr, nullptr);
        secondOperand = proceeding->getValue(nullptr, nullptr);
    }catch(std::runtime_error err)
    {
        if(std::strcmp(err.what(), "cannot use operator as operand!") == 0)//If the error is because one of the operands is actually an operator,
        {
            throw std::runtime_error(getSymbol() + " is missing an operand!");
        }
        //Otherwise,
        throw err;//Just pass the error on.
    }
    
    return firstOperand - secondOperand;
}

/**
 * Implements the getPriority method to follow the order of operations.
 * Returns Subtraction's priority as 1
*/
int Subtraction::getPriority() 
{
    return 1;
}

/**
 * Implements the getSymbol method to use in stream insertion method.
 * Returns "-".
*/
std::string Subtraction::getSymbol() 
{
    return "-";
}

// Multiplication implementation

/**
 * Performs multiplication on its given operands.
 * @param firstOperand The operand preceeding the operator.
 * @param secondOperand The operand proceeding the operator.
 * @returns The result of the multiplication of the two values.
 * @throws std::runtime_error If given a nullptr.
*/
double Multiplication::getValue(EquationElement* preceding, EquationElement* proceeding) 
{
    if(preceding == nullptr || proceeding == nullptr)//If it is given nullpointers,
    {
        /*
            There are basically two cases where this might happen:
            1. It is being treated as a NumericValue (operand). In this case, both will be nullpointers
            2. It is the first/last item in the equation. In this case, only one will be nullptr.
        */
        if(preceding == nullptr && preceding == nullptr)//If they are both nullptr,
        {
            throw std::runtime_error("cannot use operator as operand!");
        }
        //If only one is nullptr,
        throw std::runtime_error(getSymbol() + " is missing an operand!");
    }

    double firstOperand;
    double secondOperand;
    try
    {
        firstOperand = preceding->getValue(nullptr, nullptr);
        secondOperand = proceeding->getValue(nullptr, nullptr);
    }catch(std::runtime_error err)
    {
        if(std::strcmp(err.what(), "cannot use operator as operand!") == 0)//If the error is because one of the operands is actually an operator,
        {
            throw std::runtime_error(getSymbol() + " is missing an operand!");
        }
        //Otherwise,
        throw err;//Just pass the error on.
    }
    
    return firstOperand * secondOperand;
}

/**
 * Implements the getPriority method to follow the order of operations.
 * Returns Multiplication's priority as 2
*/
int Multiplication::getPriority() 
{
    return 3;
}

/**
 * Implements the getSymbol method to use in stream insertion method.
 * Returns "*".
*/
std::string Multiplication::getSymbol() 
{
    return "*";
}

// Division implementation

/**
 * Performs division on its given operands.
 * @param firstOperand The operand preceeding the operator (numerator).
 * @param secondOperand The operand proceeding the operator (denominator).
 * @returns The result of the division of the two values.
 * @throws runtime_error If the denominator is zero or if given a nullptr
*/
double Division::getValue(EquationElement* preceding, EquationElement* proceeding) 
{
    if(preceding == nullptr || proceeding == nullptr)//If it is given nullpointers,
    {
        /*
            There are basically two cases where this might happen:
            1. It is being treated as a NumericValue (operand). In this case, both will be nullpointers
            2. It is the first/last item in the equation. In this case, only one will be nullptr.
        */
        if(preceding == nullptr && preceding == nullptr)//If they are both nullptr,
        {
            throw std::runtime_error("cannot use operator as operand!");
        }
        //If only one is nullptr,
        throw std::runtime_error(getSymbol() + " is missing an operand!");
    }

    double firstOperand;
    double secondOperand;
    try
    {
        firstOperand = preceding->getValue(nullptr, nullptr);
        secondOperand = proceeding->getValue(nullptr, nullptr);
    }catch(std::runtime_error err)
    {
        if(std::strcmp(err.what(), "cannot use operator as operand!") == 0)//If the error is because one of the operands is actually an operator,
        {
            throw std::runtime_error(getSymbol() + " is missing an operand!");
        }
        //Otherwise,
        throw err;//Just pass the error on.
    }
    
    if (secondOperand == 0) 
    {
        //Error handling for division by zero
        throw std::runtime_error("cannot divide by zero!");
    }
    
    return firstOperand / secondOperand;
}

/**
 * Implements the getPriority method to follow the order of operations.
 * Returns Division's priority as 2
*/
int Division::getPriority() 
{
    return 3;
}

/**
 * Implements the getSymbol method to use in stream insertion method.
 * Returns "/".
*/
std::string Division::getSymbol() 
{
    return "/";
}

// Modulo implementation

/**
 * Performs modulo on its given operands.
 * @param firstOperand The operand preceeding the operator.
 * @param secondOperand The operand proceeding the operator.
 * @returns The result of the modulo of the two values.
 * @throws runtime_error If the secondOperand is not positive or it's given a nullptr.
*/
double Modulo::getValue(EquationElement* preceding, EquationElement* proceeding) 
{
    if(preceding == nullptr || proceeding == nullptr)//If it is given nullpointers,
    {
        /*
            There are basically two cases where this might happen:
            1. It is being treated as a NumericValue (operand). In this case, both will be nullpointers
            2. It is the first/last item in the equation. In this case, only one will be nullptr.
        */
        if(preceding == nullptr && preceding == nullptr)//If they are both nullptr,
        {
            throw std::runtime_error("cannot use operator as operand!");
        }
        //If only one is nullptr,
        throw std::runtime_error(getSymbol() + " is missing an operand!");
    }

    double firstOperand;
    double secondOperand;
    try
    {
        firstOperand = preceding->getValue(nullptr, nullptr);
        secondOperand = proceeding->getValue(nullptr, nullptr);
    }catch(std::runtime_error err)
    {
        if(std::strcmp(err.what(), "cannot use operator as operand!") == 0)//If the error is because one of the operands is actually an operator,
        {
            throw std::runtime_error(getSymbol() + " is missing an operand!");
        }
        //Otherwise,
        throw err;//Just pass the error on.
    }
    
    if (secondOperand == 0) 
    {
        //Error handling for modulo by zero
        throw std::runtime_error("cannot modulo by zero!");
    }else if (secondOperand < 0)
    {
        throw std::runtime_error("%'s second operator must not be negative!");
    }
    
    return std::fmod(firstOperand, secondOperand);
}

/**
 * Implements the getPriority method to follow the order of operations.
 * Returns Modulo's priority as 2
*/
int Modulo::getPriority() 
{
    return 3;
}

/**
 * Implements the getSymbol method to use in stream insertion method.
 * Returns "%".
*/
std::string Modulo::getSymbol() 
{
    return "%";
}

// Exponentiation implementation

/**
 * Performs exponentiation on its given operands.
 * @param base The operand preceeding the operator.
 * @param exponent The operand proceeding the operator.
 * @returns The result of the exponentiation of the two values.
 * @throws runtime_error If exponent is negative or it is given a nullptr.
*/
double Exponentiation::getValue(EquationElement* preceding, EquationElement* proceeding) 
{
    if(preceding == nullptr || proceeding == nullptr)//If it is given nullpointers,
    {
        /*
            There are basically two cases where this might happen:
            1. It is being treated as a NumericValue (operand). In this case, both will be nullpointers
            2. It is the first/last item in the equation. In this case, only one will be nullptr.
        */
        if(preceding == nullptr && preceding == nullptr)//If they are both nullptr,
        {
            throw std::runtime_error("cannot use operator as operand!");
        }
        //If only one is nullptr,
        throw std::runtime_error(getSymbol() + " is missing an operand!");
    }

    double base;
    double exponent;
    try
    {
        base = preceding->getValue(nullptr, nullptr);
        exponent = proceeding->getValue(nullptr, nullptr);
    }catch(std::runtime_error err)
    {
        if(std::strcmp(err.what(), "cannot use operator as operand!") == 0)//If the error is because one of the operands is actually an operator,
        {
            throw std::runtime_error(getSymbol() + " is missing an operand!");
        }
        //Otherwise,
        throw err;//Just pass the error on.
    }
    
    return pow(base, exponent);
}

/**
 * Implements the getPriority method to follow the order of operations.
 * Returns Exponentiation's priority as 3
*/
int Exponentiation::getPriority() 
{
    return 4;
}

/**
 * Implements the getSymbol method to use in stream insertion method.
 * Returns "^".
*/
std::string Exponentiation::getSymbol() 
{
    return "^";
}
