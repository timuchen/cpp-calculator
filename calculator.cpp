#include "calculator.h"

#include <cmath>
#include <QString>

using namespace std;

void Calculator::Set(Number n) {
    init_number_ = n;
};

Number Calculator::GetNumber() const {
    return init_number_;
};

void Calculator::Add(Number n) {
    init_number_ += n;
};

void Calculator::Sub(Number n) {
    init_number_ -= n;
};

void Calculator::Div(Number n) {
    init_number_ /= n;
};

void Calculator::Mul(Number n) {
    init_number_ *= n;
};

void Calculator::Pow(Number n) {
    init_number_ = pow(init_number_, n);
};

void Calculator::Save() {
    memory_ = init_number_;
    has_mem_ = true;
};

void Calculator::Load() {
    init_number_ = memory_;
};

bool Calculator::HasMem() const {
    return has_mem_;
};

QString Calculator::GetNumberRepr() const {
    return QString::number(init_number_);
};
