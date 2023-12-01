#include <iostream>
#include <stack>
#include <list>

class Parentheses {
public:
    // Method to tokenize the input expression and return a list of objects
    static std::list<char> tokenizeExpression(const std::string& expression) {
        std::list<char> tokenList;

        for (char ch : expression) {
            if (!isInvalidCharacter(ch)) {
                tokenList.push_back(ch);
            }
        }

        return tokenList;
    }

    // Method to check if parentheses in the expression are correctly matched
    static bool areParenthesesMatched(const std::string& expression) {
        std::stack<char> parenthesesStack;

        // Tokenize the expression and get a list of parentheses tokens
        std::list<char> tokenList = tokenizeExpression(expression);

        // Loop through each token in the list
        for (char token : tokenList) {
            if (isOpenParenthesis(token)) {
                parenthesesStack.push(token);
            } else if (isCloseParenthesis(token)) {
                if (parenthesesStack.empty() || !areMatchingPair(parenthesesStack.top(), token)) {
                    return false;  // Unmatched closing parenthesis
                }
                parenthesesStack.pop();
            }
        }

        return parenthesesStack.empty();  // All parentheses are matched if the stack is empty
    }

private:
    static bool isOpenParenthesis(char ch) {
        return ch == '(' || ch == '{' || ch == '[';
    }

    static bool isCloseParenthesis(char ch) {
        return ch == ')' || ch == '}' || ch == ']';
    }

    static bool areMatchingPair(char open, char close) {
        return (open == '(' && close == ')') ||
               (open == '{' && close == '}') ||
               (open == '[' && close == ']');
    }

    static bool isInvalidCharacter(char ch) {
        return ch == '{' || ch == ']' || ch == '[' || ch == '}';
    }
};

int runPParser() {
    // Test the parentheses parser with tokenization
    std::string expression = "({[5 + 2] * 3} - 1)";

    // Tokenize the expression and print the list of tokens
    std::list<char> tokenList = Parentheses::tokenizeExpression(expression);
    std::cout << "Token List: ";
    for (char token : tokenList) {
        std::cout << token << " ";
    }
    std::cout << std::endl;

    // Check if the parentheses are correctly matched
    std::cout << "Expression: " << (Parentheses::areParenthesesMatched(expression) ? "Valid" : "Invalid") << std::endl;

    return 0;
}
