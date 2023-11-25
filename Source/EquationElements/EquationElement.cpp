#include "EquationElement.hpp"
#include <iostream>
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
    stream << element.getSymbol();
    return stream;
}