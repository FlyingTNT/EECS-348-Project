/*
Parser.cpp
Purpose: Arithmetic parsing program
Authors: C.Cooper and Jeff Burns
Date Created: 11/28/2023
*/
#include "../Datastructures/List.hpp"
#include <string>
#include <stdexcept>
#include "../EquationElements/EquationElement.hpp"
#include "../EquationElements/UnaryOperator.hpp"
#include "../EquationElements/BinaryOperator.hpp"
#include "../EquationElements/NumericValue.hpp"
#include "../EquationElements/Parentheses.hpp"
#include "Parser.hpp"
//This file is located in the Control folder.

/**
 * Given a string and an index, parses the int in the string at the index. Also moves the index forward to the index
 * of the last digit in the parsed integer.
 * @param string The string containing the integer to be parsed.
 * @param index A pointer to the index the integer starts at.
 * @returns The value of the parsed int.
 * @throws std::runtime_error If the integer to be parsed > 2^31-1 (max value of an int)
 * @author C. Cooper
*/
static int parseInt(std::string string, int* index)
{
    int start = *index;//Saves the index the int starts at (so we can use it in substr)
    for(; *index < string.length(); (*index)++)//For each char in the string, starting at the index,
    {
        if(!(std::isdigit(string.at(*index))))//If the char isn't a digit (means that we are at the index just after the end of the int)
        {
            (*index)--;//Decrement the index (so that it is on the last digit in the int)
            try
            {
                return std::stoi(string.substr(start, (*index)+1 - start));//Use stoi to parse the int
            }catch(std::out_of_range)//If stoi threw an error, that means the int overflowed
            {
                throw std::runtime_error("input overflow!");
            }
        }
    }
    //If we made it to the end of the string without finding a non-digit char,
    try
    {
        return std::stoi(string.substr(start, (*index) - start));//Try to parse the string starting at start and going to the end of the string.
    }catch(std::out_of_range)//If stoi threw an error, that means the int overflowed
    {
        throw std::runtime_error("input overflow!");
    }
}

/**
 * Given a string and an index, parses the parentheses in the string that starts at the index. Also moves the index forward to the index
 * of the matching closing parentheses.
 * @param string The string containing the parentheses to be parsed.
 * @param index A pointer to the index of the opening parentheses.
 * @returns A pointer to a Parentheses object representing the parsed parentheses.
 * @throws std::runtime_error If there is no matching closing parentheses, or if the equation contained in the parentheses throws a parser error when parsed
 *                            (see the parse method).
 * @author C. Cooper
*/
static Parentheses* parseParentheses(std::string string, int* index)
{
    (*index)++;//Increment the index (so that it is at the first item after the opening parentheses.)
    int depth = 1;//How many opening parentheses deep we are. (The number that haven't been closed)
    int start = *index;//Stores the index of the first item after the opening parentheses (for use in substr).
    for(; *index < string.length(); (*index)++)//For each char after the opening parentheses,
    {
        if(string.at(*index) == '(')//If it's an opening parentheses,
        {
            depth++;
            continue;
        }

        if(string.at(*index) == ')')//If it's a closing parentheses,
        {
            if(depth == 1)//If this is the closing parentheses that matches the opening one,
            {
                return new Parentheses(Parser::parse(string.substr(start, (*index) - start)));//Use the parser to parse the equation inside the parentheses
            }//Otherwise,
            depth--;
        }
    }
    //If it didn't find a closing parentheses to match the opeing one,
    throw std::runtime_error("unmatched parentheses!");
}

List<EquationElement>* Parser::parse(std::string input)
{
    List<EquationElement>* outListPtr = new List<EquationElement>;
    bool lastWasOperator = true;//Flag used to tell if +/- should be unary (true) or binary (false)
    for(int i = 0; i < input.length(); i++)//For each char in the input,
    {
        char c = input.at(i);//Gets the character in the input at i

        switch(c)
        {
            case '+':
                if(lastWasOperator)
                {
                    outListPtr->append(new AbsoluteValue());
                }else{
                    outListPtr->append(new Addition());
                }
                lastWasOperator = true;
                break;
            case '-':
                if(lastWasOperator)
                {
                    outListPtr->append(new Negation());
                }else{
                    outListPtr->append(new Subtraction());
                }
                lastWasOperator = true;
                break;
            case '*':
                outListPtr->append(new Multiplication());
                lastWasOperator = true;
                break;
            case '/':
                outListPtr->append(new Division());
                lastWasOperator = true;
                break;
            case '^':
                outListPtr->append(new Exponentiation());
                lastWasOperator = true;
                break;
            case '%':
                outListPtr->append(new Modulo());
                lastWasOperator = true;
                break;
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9'://Parseint will parse the int starting at i and also move i to the end of the int
                outListPtr->append(new NumericValue(parseInt(input, &i)));
                lastWasOperator = false;
                break;
            case '(':
                outListPtr->append(parseParentheses(input, &i));
                lastWasOperator = false;
                break;
            case ')'://If we have a closing parentheses without an openeing one
                throw std::runtime_error("unmatched parentheses!");
            case ' ':
                break;
            default://If it's not a character that we have a defined token for,
                throw std::runtime_error("illegal character: " + std::string(1, c) + "!");
        }
    }
    return outListPtr;
}

int run()
{
    std::cout << Parser::parse("15+127890");
    system("pause");
    return 0;
}