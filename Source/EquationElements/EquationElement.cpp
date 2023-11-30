/**
 * EquationElement.cpp
 * Purpose: Implement non-pure virtual methods of EquationElement.
 * Author: C. Cooper
 * Date Created: 2023-11-25
*/
#include "EquationElement.hpp"
#include <iostream>
#include <iomanip>
#include <string>

/**
 * Implements the getSymbol method so that we can use it in the stream insertion
 * method. Just returns the empty string. 
*/
std::string EquationElement::getSymbol()
{
    return "";
}

/**
 * Overloads the stream insertion operator. Prints this class's
 * getSymbol() method.
 * @param stream The stream to insert into.
 * @param element The element to insert into the stream.
 * @returns The stream we inserted into.
*/
std::ostream& operator << (std::ostream& stream, EquationElement& element)
{
    stream << element.getSymbol();//Insert the element's symbol into the stream.
    return stream;
}