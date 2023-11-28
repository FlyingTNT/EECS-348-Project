/**
 * Parentheses.cpp
 * Purpose: Implement the class defined in Parentheses.hpp
 * Author: C. Cooper
 * Date Created: 2023-11-28
*/
#include "Parentheses.hpp"
#include "../Datastructures/List.hpp"
#include <string>

class Evaluator{public:static int evaluate(List<EquationElement>*){return -1;}};//Forward declare Evaluator because it isn't made yet.

/**
 * Creates a Parentheses object that contains the given List of EquationElements.
 * @param contents The List of elements contained by this parentheses.
*/
Parentheses::Parentheses(List<EquationElement>* contents)
{
    this->contents = contents;//Sets contents to the given list.
}

/**
 * Gets the value of the equation contained within this parentheses.
 * @param preceding The EquationElement preceding this element in the equation. Ignored.
 * @param proceeding The EquationElement proceeding this element in the equation. Ignored.
 * @returns The value of the equation contained in this parentheses.
*/
int Parentheses::getValue(EquationElement* preceding, EquationElement* proceeding)
{
    return Evaluator::evaluate(contents);//Uses the Evaluator class to calculate the value.
}

/**
 * Returns a string representation of this element. Outputs the the symbols of each item in its
 * contents, in parentheses.
 * Ex: (1+1*7)
 * @returns A string representation of this element
*/
std::string Parentheses::getSymbol()
{
    std::string out = "(";//Starts the output with an opening parentheses
    for(int i = 0; i < contents->length(); i++)//For each item in the contents,
    {
        out += contents->get(i)->getSymbol();//Adds that item's symbol to the output
    }
    return out + ")";//Caps the output with a closing parentheses and returns it.
}

/**
 * Gets the priority of this element.
 * For Parentheses, this is 4.
 * @returns The priority of this element (4).
*/
int Parentheses::getPriority()
{
    return 4;
}