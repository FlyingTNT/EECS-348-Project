/**
 * ElementListTest.cpp
 * Purpose: An driver class that tests the functionality of EquationElements in Lists.
 * Author: C. Cooper
 * Date Created: 2023-11-28
*/

#include "../Datastructures/List.hpp"
#include "../EquationElements/EquationElement.hpp"
#include "../EquationElements/UnaryOperator.hpp"
#include "../EquationElements/BinaryOperator.hpp"
#include "../EquationElements/NumericValue.hpp"
#include "../EquationElements/Parentheses.hpp"
#include <iostream>

int runListTest()//You can change to main if you Like
{
    List<EquationElement> outer;
    outer.append(new NumericValue(1));
    outer.append(new Addition());
    outer.append(new NumericValue(2));
    outer.append(new Exponentiation());
    outer.append(new NumericValue(5));
    List<EquationElement> inner;
    inner.append(new Negation());
    inner.append(new NumericValue(7));
    inner.append(new Modulo());
    inner.append(new NumericValue(2));
    outer.append(new Parentheses(&inner));
    std::cout << outer;

    system("pause");
}