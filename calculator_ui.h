#pragma once

#include <iostream>

#include "calculator.h"

class CalculatorUI {
public:
    CalculatorUI(Calculator& calc, std::ostream& out, std::ostream& err): 
    calc_{calc}, output_{out}, error_{err} {};
    
    bool Parse(std::istream& input);
    
private:
    bool ReadNumber(std::istream& input, Number& result) const;
    void Help() const;
    
private:
    Calculator calc_;
    std::ostream& output_;
    std::ostream& error_;
};