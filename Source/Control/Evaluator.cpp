
#include "../Datastructures/List.hpp"
#include "../EquationElements/EquationElement.hpp"
#include "../EquationElements/UnaryOperator.hpp"
#include "../EquationElements/BinaryOperator.hpp"
#include "../EquationElements/NumericValue.hpp"
#include "../EquationElements/Parentheses.hpp"
#include "Evaluator.hpp"
#include <iostream>

static int getHighestPriorityIndex(List<EquationElement>* equation) {
  int maximum = -1;
  int index = -1;
  for (int i = 0; i < equation->length(); i++) {
    int priority = (*equation->get(i)).getPriority();
    if (priority > maximum) {
      maximum = priority;
      index = i;
    }
  }

  // Find the last unary operator, if it exists
  EquationElement* oper = equation->get(index);
  if (oper->getPriority() >= 2 && oper->getPriority() < 5) {
    for (int i = index + 1; i < equation->length(); i++) {
      int priority = (*equation->get(i)).getPriority();
      if (priority != 2) {
        break;
      }
      index += 1;
    }
  }
  
  return index;
}

static void printList(List<EquationElement>* equation) {
  for (int i = 0; i < equation->length(); i++) {
    std::cout << *equation->get(i) << " ";
  }
  std::cout << "\n";
}

int Evaluator::evaluate(List<EquationElement>* equation) {
  while (equation->length() > 0) {
    int index = getHighestPriorityIndex(equation);

    EquationElement* oper = equation->get(index);

    if (oper->getPriority() == 5) {
      equation->set(index, new NumericValue(oper->getValue(nullptr, nullptr)));
    }

    try {
      if (oper->getPriority() == 2) {
        if (index + 1 == equation->length()) {
          throw std::runtime_error("");
        }

        EquationElement* next = equation->get(index + 1);

        equation->set(index, new NumericValue(oper->getValue(nullptr, next)));

        equation->remove(index + 1);

      } else if (oper->getPriority() == 1 || oper->getPriority() > 2) {
        EquationElement* prev = equation->get(index - 1);
        EquationElement* next = equation->get(index + 1);
        equation->set(index, new NumericValue(oper->getValue(prev, next)));
        equation->remove(index + 1);
        equation->remove(index - 1);
      } else {
        return equation->pop()->getValue(0, 0);
      }
    } catch (std::runtime_error &e) {
      throw std::runtime_error(oper->getSymbol() + " is missing an operand!");
      break;
    }
  }
}
