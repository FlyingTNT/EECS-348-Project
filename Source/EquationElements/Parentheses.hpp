/**
 * Parentheses.hpp
 * Purpose: Represent a parentheses in an equation.
 * Author: C. Cooper
 * Date Created: 2023-11-28
*/
#ifndef PARENTHESES_H
#define PARENTHESES_H

#include "EquationElement.hpp"
#include "../Datastructures/List.hpp"
#include <string>

/**
 * A class that represents parentheses in an equation.
*/
class Parentheses : public EquationElement
{
    private:
    List<EquationElement>* contents;//The elements within the parentheses.

    public:
    Parentheses(List<EquationElement>* contents);
    ~Parentheses();

    float getValue(EquationElement* preceding, EquationElement* proceeding) override;
    std::string getSymbol() override;
    int getPriority() override;
};

#endif
