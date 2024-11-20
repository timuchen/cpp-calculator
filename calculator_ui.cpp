using namespace std;
using namespace std::literals;

bool CalculatorUI::Parse(istream& input) {
    Number operand;
    if (ReadNumber(input, operand)) {
        calc_.Set(operand);
    }

    calc_.Set(operand);

    string token;
    while(input >> token) {
        Number right;
        if (token == "+"s) {
            if (!ReadNumber(input, right)) {
                break;
            }
            calc_.Add(right);
        } else if (token == "-"s) {
            if (!ReadNumber(input, right)) {
                break;
            }
            calc_.Sub(right);
        } else if (token == "*"s) {
            if (!ReadNumber(input, right)) {
                break;
            }
            calc_.Mul(right);
        } else if (token == "/"s) {
            if (!ReadNumber(input, right)) {
                break;
            }
            calc_.Div(right);
        } else if (token == "**"s) {
            if (!ReadNumber(input, right)) {
                break;
            }
            calc_.Pow(right);
        } else if (token == "s"s) {
            calc_.Save();
        } else if (token == "l"s) {
            if (!calc_.HasMem()) {
                error_ << "Error: Memory is empty"s << endl;
                break;
            }
            calc_.Load();
        } else if (token == "="s) {
            output_ << calc_.GetNumberRepr() << endl;
        } else if (token == "c"s) {
            calc_.Set(0);
        } else if (token == "n"s) {
            calc_.Set(- calc_.GetNumber());
        } else if (token == "h"s) {
            Help();
        } else if (token == ":"s) {
            if (!ReadNumber(input, right)) {
                break;
            }
            calc_.Set(right);
        } else if (token == "q"s) {
            return false;
        } else {
            error_ << "Error: Unknown token '"s << token << "'"s << std::endl; 
            return false;
        }
    }

    return false;
}

bool CalculatorUI::ReadNumber(istream& input, Number& result) const {
    if (!(input >> result)) {
        error_ << "Error: Numeric operand expected"s << endl;
        return false;
    }
    return true;
}

void CalculatorUI::Help() const {
    auto help_text = "Commands:\n"s
               "= - show current number\n"s
               "+ - * / ** <number> - perform operation over current number\n"s
               "s - save to memory\n"s
               "l - load from memory\n"s
               "c - clear\n"s
               "n - negate number\n"s
               ": <number> - set current number\n"s
               "h - show help\n"
               "q - exit"s;

    output_ << help_text << endl;
}