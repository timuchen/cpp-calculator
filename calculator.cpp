#include <iostream>
#include <string>
#include <cmath>
#include "calculator.h"

using namespace std::literals;
using Number = double;

double ReadNumber () {
    double num;
    std::cin >> num;

    if (std::cin.fail()) {
        std::cerr << "Error: Numeric operand expected"s << std::endl;
    }

    return num;
}

double ReadNumber (Number& result, const bool& use_memory) {
    
    if (!use_memory) {
        std::cerr << "Error: Memory is empty" << std::endl;
    }

    return result;
}

void RunCalculatorCycle () {
    bool use_memory = false;
    double number = ReadNumber();
    double number_memory;

    std::string token;

    while(std::cin >> token) {
        if (token == "+"s) {
            number += ReadNumber();
        } else if (token == "-"s) {
            number -= ReadNumber();
        } else if (token == "*"s) {
            number *= ReadNumber();
        } else if (token == "/"s) {
            number /= ReadNumber();
        } else if (token == "**"s) {
            number = std::pow(number, ReadNumber());
        } else if (token == "="s) {
            std::cout << number << std::endl;
        } else if (token == "c"s) {
            number = 0;
        } else if (token == ":"s) {
            number = ReadNumber();
        } else if (token == "q"s) {
            break;
        } else if (token == "s"s) {
            number_memory = number;
            use_memory = true;
        } else if (token == "l"s) {
            number = ReadNumber(number_memory, use_memory);
        } else {
            std::cerr << "Error: Unknown token "s << token << std::endl;
            break;
        }
    }
}