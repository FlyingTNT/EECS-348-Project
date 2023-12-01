/**
 * Driver.cpp
 * Purpose: Main file for the calculator. Handles user input and system output.
 * Author: C. Cooper
 * Date Created: 2023-11-25
*/
#include "../Datastructures/List.hpp"
#include "../EquationElements/EquationElement.hpp"
#include "Parser.hpp"
#include "Evaluator.hpp"
#include <string>
#include <iostream>
#include <iomanip>

/**
 * The system's main method.
 * Repeatedly gets user input, evaluates it, and gives the user the output.
*/
int main()
{
    std::string userIn;//Variable to hold the user's input.

    std::cout << std::fixed << std::setprecision(3);//Make cout not use scientific notation

    std::cout << "Please enter any equation, or \"exit\" to quit:\n";//Introduce the user to the mechanics of the system

    while(true)//Repeatedly gets and evaluates user input. Broken when the user inputs "exit"
    {
        std::cout << "Input: ";//Prompt the user for input
        std::getline(std::cin, userIn);//Store the user's input in userIn
        if(userIn.compare("exit") == 0)//If the input was "exit",
        {
            break;//Stop the loop (and by extension, the program)
        }

        if(userIn.compare("") == 0)//If the user didn't give input
        {
            continue;//Retry
        }

        List<EquationElement>* equation = nullptr;
        try//The parse and evaluate methods will throw any errors they encounter.
        {
            equation = Parser::parse(userIn);//Parse and store the user input.
            std::cout << "Parsed " << userIn << " to " << *equation << "\n";//Print the parsed list (DEBUG ONLY, DELETE IN FINAL VERSION)
            if(equation->length() == 0)//If the user only gave spaces,
            {
                continue;//Retry
            }
            
            /*
                Evaluates the equation and stores the result and then prints the result. This can't be done in one line
                because if it was, we'd still print userIn = even if there was an error.
            */
            float value = Evaluator::evaluate(equation);//Evaluates the equation
            delete equation;//Remove equation from the heap (we don't need it anymore)
            if(static_cast<int>(value) == value)//If the value is an int (so that we don't use decimal places after the int)
            {
                std::cout << userIn << " = " << static_cast<int>(value) << "\n\n";//Prints the evaluated value
            }else{
                std::cout << userIn << " = " << value << "\n\n";//Prints the evaluated value
            }
        }catch(std::runtime_error err)//Catch any error the parse or evaluate threw
        {
            if(!(equation == nullptr))
            {
                delete equation;//Remove equation from the heap (if there's an error in evaluate, it won't be deleted in the try).
            }
            std::cout << "Error: " << err.what() << "\n\n";//Print "Error: " {the error message}.
        }
    }

    return 0;
}