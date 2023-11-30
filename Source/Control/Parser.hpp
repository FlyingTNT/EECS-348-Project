#ifndef PARSER_H
#define PARSER_H
#include "../Datastructures/List.hpp"
#include "../EquationElements/EquationElement.hpp"
#include <string>

class Parser
{
    public:
    static List<EquationElement>* parse(std::string);
};

#endif