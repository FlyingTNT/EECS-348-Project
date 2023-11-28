/**
 * BinaryOperator.cpp
 * Purpose: Implement binary operator subclass methods.
 * Author: Vivian Lara
 * Date Created: 2023-11-27
*/

#include "BinaryOperator.hpp"

//Addition implementation

/**
 * Performs addition on its given operands.
 * @param firstOperand The operand preceeding the operator.
 * @param secondOperand The operand proceeding the operator.
 * @returns The result of the addition of the two values.
*/
int Addition::getValue(EquationElement& preceding, EquationElement& proceeding) {
    int firstOperand = preceding.getValue();
    int secondOperand = proceeding.getValue();
    return firstOperand + secondOperand;
}

/**
 * Implements the getPriority method to follow the order of operations.
 * Returns Addition's priority as 1
*/
int Addition::getPriority() {
    return 1;
}

/**
 * Implements the getSymbol method to use in stream insertion method.
 * Returns "+".
*/
std::string Addition::getSymbol() {
    return "+";
}

//Subtraction implementation

/**
 * Performs subtraction on its given operands.
 * @param firstOperand The operand preceeding the operator.
 * @param secondOperand The operand proceeding the operator.
 * @returns The result of the subtraction of the two values.
*/
int Subtraction::getValue(EquationElement& preceding, EquationElement& proceeding) {
    int firstOperand = preceding.getValue();
    int secondOperand = proceeding.getValue();
    
    return firstOperand - secondOperand;
}

/**
 * Implements the getPriority method to follow the order of operations.
 * Returns Subtraction's priority as 1
*/
int Subtraction::getPriority() {
    return 1;
}

/**
 * Implements the getSymbol method to use in stream insertion method.
 * Returns "-".
*/
std::string Subtraction::getSymbol() {
    return "-";
}

// Multiplication implementation

/**
 * Performs multiplication on its given operands.
 * @param firstOperand The operand preceeding the operator.
 * @param secondOperand The operand proceeding the operator.
 * @returns The result of the multiplication of the two values.
*/
int Multiplication::getValue(EquationElement& preceding, EquationElement& proceeding) {
    int firstOperand = preceding.getValue();
    int secondOperand = proceeding.getValue();
    
    return firstOperand * secondOperand;
}

/**
 * Implements the getPriority method to follow the order of operations.
 * Returns Multiplication's priority as 2
*/
int Multiplication::getPriority() {
    return 2;
}

/**
 * Implements the getSymbol method to use in stream insertion method.
 * Returns "*".
*/
std::string Multiplication::getSymbol() {
    return "*";
}

// Division implementation

/**
 * Performs division on its given operands.
 * @param firstOperand The operand preceeding the operator (numerator).
 * @param secondOperand The operand proceeding the operator (denominator).
 * @returns The result of the division of the two values.
 * @throws runtime_error If the denominator is zero
*/
int Division::getValue(EquationElement& preceding, EquationElement& proceeding) {
    int firstOperand = preceding.getValue();
    int secondOperand = proceeding.getValue();
    
    if (secondOperand == 0) {
        //Error handling for division by zero
        throw std::runtime_error("Division by zero error");
    }
    
    return firstOperand / secondOperand;
}

/**
 * Implements the getPriority method to follow the order of operations.
 * Returns Division's priority as 2
*/
int Division::getPriority() {
    return 2;
}

/**
 * Implements the getSymbol method to use in stream insertion method.
 * Returns "/".
*/
std::string Division::getSymbol() {
    return "/";
}

// Modulo implementation

/**
 * Performs modulo on its given operands.
 * @param firstOperand The operand preceeding the operator.
 * @param secondOperand The operand proceeding the operator.
 * @returns The result of the modulo of the two values.
 * @throws runtime_error If the secondOperand is zero.
*/
int Modulo::getValue(EquationElement& preceding, EquationElement& proceeding) {
    int firstOperand = preceding.getValue();
    int secondOperand = proceeding.getValue();
    
    if (secondOperand == 0) {
        //Error handling for modulo by zero
        throw std::runtime_error("Modulo by zero error");
    }
    
    return firstOperand % secondOperand;
}

/**
 * Implements the getPriority method to follow the order of operations.
 * Returns Modulo's priority as 2
*/
int Modulo::getPriority() {
    return 2;
}

/**
 * Implements the getSymbol method to use in stream insertion method.
 * Returns "%".
*/
std::string Modulo::getSymbol() {
    return "%";
}

// Exponentiation implementation

/**
 * Performs exponentiation on its given operands.
 * @param base The operand preceeding the operator.
 * @param exponent The operand proceeding the operator.
 * @returns The result of the exponentiation of the two values.
 * @throws runtime_error If exponent is negative.
*/
int Exponentiation::getValue(EquationElement& preceding, EquationElement& proceeding) {
    int base = preceding.getValue();
    int exponent = proceeding.getValue();
    
    if (exponent < 0) {
        //Error handling for negative exponent
        throw std::runtime_error("Negative exponent error");
    }
    
    int result = 1;
    //for the range of the exponent, multiply the base by itself
    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }
    
    return result;
}

/**
 * Implements the getPriority method to follow the order of operations.
 * Returns Exponentiation's priority as 3
*/
int Exponentiation::getPriority() {
    return 3;
}

/**
 * Implements the getSymbol method to use in stream insertion method.
 * Returns "^".
*/
std::string Exponentiation::getSymbol() {
    return "^";
}
