/**
 * Evaluator.cpp
 * Purpose: A class that drives the main logic for evaluating an expression
 * Author: Aryan Kevat
 * Date Created: 2023-11-29
*/

#ifndef EVALUATOR_H
#define EVALUATOR_H
#include "../Datastructures/List.hpp"
#include "../EquationElements/EquationElement.hpp"

/**
 * Contains lonely function to evaluate a list of EquationElement
*/
class Evaluator
{
    public:
    static float evaluate(List<EquationElement>*);
};

#endif
