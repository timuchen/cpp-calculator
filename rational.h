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
        Rational other{denominator_, numerator_};

        return other;
    }

    int GetNumerator() const {
        return numerator_;
    }

    int GetDenominator() const {
        return denominator_;
    }

    friend std::istream& operator>>(std::istream& is, Rational& r);
    friend std::ostream& operator<<(std::ostream& os, const Rational& r);

    Rational& operator+() {
        Rational other{*this};

        return other;
    }

    Rational& operator-() {
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

    explicit operator double() {
        return numerator_ * 1.0 / denominator_;
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

inline std::istream& operator>>(std::istream& is, Rational& num){
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

inline std::ostream& operator<<(std::ostream& os, Rational& num) {
    if (os.fail() || num.GetDenominator() == 1) {
        os.clear();
        os << num.GetNumerator();
        return os;
    }
    os << num.GetNumerator() << " / " << num.GetDenominator();
    return os;
}

inline auto operator<=>(const Rational& l, const Rational& r) {
    unsigned long a = static_cast<unsigned long>(l.GetNumerator()) * static_cast<unsigned long>(r.GetDenominator());
    unsigned long b = static_cast<unsigned long>(l.GetDenominator()) * static_cast<unsigned long>(r.GetNumerator());

    return a <=> b;
}

inline bool operator==(const Rational& l, const Rational& r) {
    unsigned long a = static_cast<unsigned long>(l.GetNumerator()) * static_cast<unsigned long>(r.GetDenominator());
    unsigned long b = static_cast<unsigned long>(l.GetDenominator()) * static_cast<unsigned long>(r.GetNumerator());

    return a == b;
}

inline Rational operator*(const Rational& l, const Rational& r) {
    int a = l.GetNumerator() * r.GetDenominator();
    int b = l.GetDenominator() * r.GetNumerator();

    return Rational{a, b};
}

inline Rational operator/(const Rational& l, const Rational& r) {
    int a = l.GetNumerator() / r.GetDenominator();
    int b = l.GetDenominator() / r.GetNumerator();

    return Rational{a, b};
}

inline Rational operator+(const Rational& l, const Rational& r) {
    int a = l.GetNumerator() * r.GetDenominator() + l.GetDenominator() * r.GetNumerator();
    int b = l.GetDenominator() * r.GetDenominator();

    return Rational{a, b};
}

inline Rational operator-(const Rational& l, const Rational& r) {
    int a = l.GetNumerator() * r.GetDenominator() - l.GetDenominator() * r.GetNumerator();
    int b = l.GetDenominator() * r.GetDenominator();

    return Rational{a, b};
}
