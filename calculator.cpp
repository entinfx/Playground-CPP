//
//  calculator.cpp
//  cpp_playground
//
//  Created by Constantine Shatalov on 10/26/18.
//  Copyright © 2018 Hexocat. All rights reserved.
//

#include "vector"
#include "calculator.hpp"

// !!!: Doesn't check for correctness of input string
// TODO: Operation priority is not preserved
// TODO: Rewrite to object oriented

#pragma mark - MOVE DECLARATIONS TO HEADER
int bracketDistance(int openBracketIndex, std::string input);
bool isOperation(char symbol);

double calculate(std::string input) {
    double accumulator = 0.0;
    char pendingOperation = '\0';
    std::string operandCollector;

    for (int i = 0; i < input.size(); i++) {
        char currentSymbol = input[i];
        int distance = 0;
        std::string bracketsContent;
        
        if (isdigit(currentSymbol) || currentSymbol == '.') {
            // If next symbol is a digit - collect current.
            // Otherwise, execute operation and reset the collector.
            operandCollector += currentSymbol;
            if (!isdigit(input[i + 1]) && input[i + 1] != '.') {
                switch (pendingOperation) {
                    case '*':
                        accumulator *= std::stod(operandCollector);
                        pendingOperation = '\0';
                        break;
                    case '/':
                        accumulator /= std::stod(operandCollector);
                        pendingOperation = '\0';
                        break;
                    case '+':
                        accumulator += std::stod(operandCollector);
                        pendingOperation = '\0';
                        break;
                    case '-':
                        accumulator -= std::stod(operandCollector);
                        pendingOperation = '\0';
                        break;
                    case '\0':
                        accumulator = std::stod(operandCollector);
                        break;
                    default:
                        // ???: Should ignore unsupported operations, but probably unsafe
                        break;
                }
                
                operandCollector = ""; // reset operand collector
            }
        } else if (isOperation(currentSymbol)) {
            pendingOperation = currentSymbol;
        } else if (currentSymbol == '(') {
            distance = bracketDistance(i, input);
            bracketsContent = input.substr(i + 1, distance);
            
            switch (pendingOperation) {
                case '*':
                    accumulator *= calculate(bracketsContent);
                    break;
                case '/':
                    accumulator /= calculate(bracketsContent);
                    break;
                case '+':
                    accumulator += calculate(bracketsContent);
                    break;
                case '-':
                    accumulator -= calculate(bracketsContent);
                    break;
                default:
                    // ???: Don't understand why anymore but seems to work
                    accumulator = calculate(bracketsContent);
            }

            i += ++distance;
        }
        
        std::cout << std::endl;
    }
    
    return accumulator;
}

int bracketDistance(int openBracketIndex, std::string input) {
    int bracketCounter = 1;
    int closingBracketIndex = 0;
    
    for (int i = ++openBracketIndex; i < input.size(); i++) {
        if (input[i] == '(') {
            bracketCounter++;
        } else if (input[i] == ')') {
            bracketCounter--;
        }
        
        if (bracketCounter == 0) {
            closingBracketIndex = i;
            break;
        }
    }
    
    return (closingBracketIndex - openBracketIndex);
}

bool isOperation(char symbol) {
    if (symbol == '*' || symbol == '/' || symbol == '+' || symbol == '-') {
        return true;
    } else {
        return false;
    }
}
