/*
parser.cpp
arithmetic parsing program
Author C.Cooper and Jeff Burns
created 11/28/2023
*/
#include "../Datastructures/List.hpp"
#include <string>
#include <iostream>
#include <stdexcept>
#include "../EquationElements/EquationElement.hpp"
#include "../EquationElements/UnaryOperator.hpp"
#include "../EquationElements/BinaryOperator.hpp"
#include "../EquationElements/NumericValue.hpp"
#include "../EquationElements/Parentheses.hpp"
#include "Parser.hpp"
//This file is located in the Control folder.

static int parseInt(std::string string, int* index)//Parses the int starting at the given index, also moves the index to the end of the int
{
    int start = *index;
    for(; *index < string.length(); (*index)++)
    {
        if(!(std::isdigit(string.at(*index))))
        {
            (*index)--;
            try
            {
                return std::stoi(string.substr(start, (*index)+1));
            }catch(std::out_of_range)
            {
                throw std::runtime_error("input overflow!");
            }
        }
    }
    try
    {
        return std::stoi(string.substr(start, (*index)));
    }catch(std::out_of_range)
    {
        throw std::runtime_error("input overflow!");
    }
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
            /*case '(':
                //Talk to Claire about how to integrate her parentheses parser.
                List<EquationElement> parenthesesList;
                while (i != ')'){
                    parenthesesList.append(i);
                    i++;
                }//remove outer set of parentheses append to parenthesesList
                outListPtr->append(Parentheses(parenthesesList));// pass parenthesesList to parenthesis function
                lastWasOperator = false;
                break;
            case '[':
                while (i != ']'){
                    parenthesesList.append(i);
                    i++;
                }//remove outer set of brackets append to parenthesesList
                outListPtr->append(Parentheses(parenthesesList));// pass parenthesesList to parenthesis functio
                lastWasOperator = false;
                break;
            case '{':
                while (i != '}'){
                    parenthesesList.append(i);
                    i++;
                }//remove outer set of curly braces append to parenthesesList
                outListPtr->append(Parentheses(parenthesesList));// pass parenthesesList to parenthesis functio
                lastWasOperator = false;
                break;*/
            case ')':
            case ']':
            case '}'://If we have a closing parentheses without an openeing one
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