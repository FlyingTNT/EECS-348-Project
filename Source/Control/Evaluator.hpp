#ifndef EVALUATOR_H
#define EVALUATOR_H
#include "../Datastructures/List.hpp"
#include "../EquationElements/EquationElement.hpp"
#include <string>

class Evaluator
{
    public:
    static int evaluate(List<EquationElement>*);
};

#endif
