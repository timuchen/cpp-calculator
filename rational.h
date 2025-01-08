#pragma once

#include <iostream>
#include <numeric>
#include <cstdlib>

class Rational {

public:
    Rational() = default;

    Rational(int numerator, int denominator)
        : numerator_(numerator)
        , denominator_(denominator) {
        if (denominator_ == 0) {
            std::abort();
        }

        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }

        Reduction();
    }

    Rational(int numerator): numerator_(numerator) {
        numerator_ = numerator;
        denominator_ = 1;
    };

    Rational Inv() const {
        return Rational {denominator_, numerator_};;
    }

    int GetNumerator() const {
        return numerator_;
    }

    int GetDenominator() const {
        return denominator_;
    }

    friend std::istream& operator>> (std::istream& is, Rational& r);
    friend std::ostream& operator<< (std::ostream& os, const Rational& r);

    Rational& operator+ () {
        Rational result{*this};

        return result;
    }

    Rational& operator- () {
        numerator_ = (-numerator_);
        denominator_ = abs(denominator_);
        Reduction();

        return *this;
    }

    Rational& operator= (const Rational& r) = default;

    Rational& operator+= (const Rational& n) {
        numerator_ = numerator_ * n.denominator_ + denominator_ * n.numerator_;
        denominator_ = denominator_ * n.denominator_;
        Reduction();

        return *this;
    }

    Rational& operator-= (Rational n) {
        numerator_ = numerator_ * n.denominator_ - denominator_ * n.numerator_;
        denominator_ = denominator_ * n.denominator_;
        Reduction();

        return *this;
    }

    Rational& operator*= (Rational n) {
        numerator_ *= n.numerator_;
        denominator_ *= n.denominator_;
        Reduction();

        return *this;
    }

    Rational& operator/= (Rational n) {
        numerator_ *= n.denominator_;
        denominator_ *= n.numerator_;
        Reduction();

        return *this;
    }

    explicit operator double () {
        return numerator_ * 1.0 / denominator_;
    }

    Rational operator* (const Rational& rhs) const {
        Rational result(*this);
        result *= rhs;
        return result;
    }

    Rational operator/ (const Rational& rhs) const {
        Rational result(*this);
        result /= rhs;
        return result;
    }

    Rational operator+ (const Rational& rhs) const {
        Rational result(*this);
        result += rhs;
        return result;
    }

    Rational operator- (const Rational& rhs) const {
        Rational result(*this);
        result -= rhs;
        return result;
    }

private:
    void Reduction() {
        if (denominator_ < 0) {
            numerator_ = -numerator_;
            denominator_ = -denominator_;
        }

        const int divisor = std::gcd(numerator_, denominator_);
        numerator_ /= divisor;
        denominator_ /= divisor;
    }

    int numerator_ = 0;
    int denominator_ = 1;
};

inline std::istream& operator>> (std::istream& is, Rational& num){
    int first, second;
    char div;

    if (!(is >> first)) {
        is.setstate(std::ios::failbit);
    }

    num = {first, 1};

    if (!(is >> std::ws >> div)) { is.setstate(std::ios::failbit); }

    if (div != '/') {
        return is;
    }

    if (!(is >> second) || (second == 0)) { is.setstate(std::ios::failbit); } else {
        num = {first, second};
    }

    return is;
}

inline std::ostream& operator<< (std::ostream& os, Rational& num) {
    if (os.fail() || num.GetDenominator() == 1) {
        os.clear();
        os << num.GetNumerator();
        return os;
    }

    os << num.GetNumerator() << " / " << num.GetDenominator();
    return os;
}

inline auto operator<=> (const Rational& lhs, const Rational& rhs) {
    unsigned long left_operand = static_cast<unsigned long>(lhs.GetNumerator()) * static_cast<unsigned long>(rhs.GetDenominator());
    unsigned long right_operand = static_cast<unsigned long>(lhs.GetDenominator()) * static_cast<unsigned long>(rhs.GetNumerator());

    return left_operand <=> right_operand;
}

inline bool operator== (const Rational& lhs, const Rational& rhs) {
    unsigned long left_operand = static_cast<unsigned long>(lhs.GetNumerator()) * static_cast<unsigned long>(rhs.GetDenominator());
    unsigned long right_operand = static_cast<unsigned long>(lhs.GetDenominator()) * static_cast<unsigned long>(rhs.GetNumerator());

    return left_operand == right_operand;
}
