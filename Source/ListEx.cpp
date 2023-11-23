/**
 * ListEx.cpp
 * Purpose: An driver class that deomstrates functionality of the List class.
 * Author: C. Cooper
 * Date Created: 2023-11-22
*/

#include "Datastructures/List.hpp"
#include "EquationElements/EquationElement.hpp"
#include <iostream>

/**
 * Examples of how you can use the List class.
*/
int run()//Could change this to main to run standalone
{
    List<int> list;//Creates a new List of ints

    std::cout << "Append 0\n";
    list.append(0);
    std::cout << list << "\n";

    std::cout << "Append 2\n";
    list.append(2);
    std::cout << list << "\n";

    std::cout << "Insert 1 at index 1\n";
    list.insert(1, 1);
    std::cout << list << "\n";

    std::cout << "Set the value at index 0 to 7\n";
    list.set(0, 7);
    std::cout << list << "\n";

    std::cout << "Get the value at index 0\n";
    std::cout << list.get(0) << "\n";

    std::cout << "Get the length of the list\n";
    std::cout << list.length() << "\n";

    std::cout << "Remove the item at index 0\n";
    list.remove(0);
    std::cout << list << "\n";

    std::cout << "Pop from the list\n";
    list.pop();
    std::cout << list << "\n";

    List<EquationElement> equationElementList;

    system("pause");

    return 0;
}