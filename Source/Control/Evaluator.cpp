/**
 * Evaluator.cpp
 * Purpose: Implement the class defined in Evaluator.hpp
 * Author: Aryan Kevat
 * Date Created: 2023-11-29
*/

#include "Evaluator.hpp"
#include "../Datastructures/List.hpp"
#include "../EquationElements/EquationElement.hpp"
#include "../EquationElements/NumericValue.hpp"

/**
 * Finds the index of the next operation to perform
 * @param equation the list of elements representing the current equation
 * @returns the highest priority index or the next unary operator
*/
static int getHighestPriorityIndex(List<EquationElement>* equation) {
  // initialize maximum and index
  int maximum = -1;
  int index = -1;
  // iterate over each element in the equation
  for (int i = 0; i < equation->length(); i++) {
    // retrieve priority of the current element
    int priority = equation->get(i)->getPriority();
    // update maximum and index if the current priority is greater
    if (priority > maximum) {
      maximum = priority;
      index = i;
    }
  }

  // find the last unary operator, if it exists
  // check if the current priority is of UnaryOperator or higher and under parentheses
  if (maximum >= 2 && maximum < 5) {
    // iterate over each element in the current equation starting after the maximum's index
    for (int i = index + 1; i < equation->length(); i++) {
      // break if the next element's priority isn't of UnaryOperator
      if (equation->get(i)->getPriority() != 2) {
        break;
      }
      // Otherwise, increments index
      index += 1;
    }
  }
  
  return index;
}

/**
 * Finds the index of the next operation to perform
 * @param equation the list of elements representing the current equation
 * @returns the value of the given expression equation
 * @throws runtime error if an operator is missing an operand
*/
float Evaluator::evaluate(List<EquationElement>* equation) {
  while (equation->length() > 0) {
    // get index of highest priority element
    int index = getHighestPriorityIndex(equation);
    // get corresponding operator at index
    EquationElement* oper = equation->get(index);
    int priority = oper->getPriority();

    // if the operator is parens, recurse into evaluate() with getValue call
    if (priority == 5) {
      equation->set(index, new NumericValue(oper->getValue(nullptr, nullptr)));
    }

    try {
      // check if priority is of NumericValue
      // essentially means the evaluation is finished
      if (priority == 0) {
        // return value of current numeric element
        return equation->pop()->getValue(0, 0);
      // check if priority is of UnaryOperator
      } else if (priority == 2) {
        // throw if no element is after it
        if (index + 1 == equation->length()) {
          throw std::runtime_error(oper->getSymbol() + " is missing an operand!");
        }

        // get next element
        EquationElement* next = equation->get(index + 1);

        // set element at current index to numeric value of evaluated unary operation
        equation->set(index, new NumericValue(oper->getValue(nullptr, next)));

        // remove the following element
        equation->remove(index + 1);
      // Remaining elements must be of BinaryOperator
      } else {
        // throw if the element has nothing before or after it
        if (index == 0 || index + 1 == equation->length()) {
          throw std::runtime_error(oper->getSymbol() + " is missing an operand!");
        }

        // get operators before and after the current element
        EquationElement* prev = equation->get(index - 1);
        EquationElement* next = equation->get(index + 1);
        // set element at current index to numeric value of evaluated binary operation
        equation->set(index, new NumericValue(oper->getValue(prev, next)));
        // remove previous and next elements
        equation->remove(index + 1);
        equation->remove(index - 1);
      }
    } catch (std::runtime_error &e) {
      // throw missing operand message
      throw std::runtime_error(oper->getSymbol() + " is missing an operand!");
    }
  }
}
