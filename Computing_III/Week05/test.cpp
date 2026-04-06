#include <iostream>
#include <sstream>
#include <cmath>
using namespace std;

class Rational {
private:
    int numerator, denominator;

    // Helper function to compute GCD using Euclidean algorithm
    int gcd(int a, int b) {
        return b == 0 ? abs(a) : gcd(b, a % b);
    }

    // Normalize the fraction (make denominator positive and simplify)
    void normalize() {
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        int divisor = gcd(numerator, denominator);
        numerator /= divisor;
        denominator /= divisor;
    }

public:
    // Default constructor (0/1)
    Rational() : numerator(0), denominator(1) {}

    // Constructor with single integer (wholeNumber/1)
    Rational(int wholeNumber) : numerator(wholeNumber), denominator(1) {}

    // Constructor with two integers
    Rational(int num, int denom) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            cerr << "Error: Denominator cannot be zero." << endl;
            exit(1);
        }
        normalize();
    }

    // Overload == operator
    bool operator==(const Rational &rhs) const {
        return numerator == rhs.numerator && denominator == rhs.denominator;
    }

    // Overload < operator
    bool operator<(const Rational &rhs) const {
        return numerator * rhs.denominator < rhs.numerator * denominator;
    }

    // Overload <= operator
    bool operator<=(const Rational &rhs) const {
        return *this < rhs || *this == rhs;
    }

    // Overload > operator
    bool operator>(const Rational &rhs) const {
        return !(*this <= rhs);
    }

    // Overload >= operator
    bool operator>=(const Rational &rhs) const {
        return !(*this < rhs);
    }

    // Overload + operator
    Rational operator+(const Rational &rhs) const {
        return Rational(numerator * rhs.denominator + rhs.numerator * denominator, denominator * rhs.denominator);
    }

    // Overload - operator
    Rational operator-(const Rational &rhs) const {
        return Rational(numerator * rhs.denominator - rhs.numerator * denominator, denominator * rhs.denominator);
    }

    // Overload * operator
    Rational operator*(const Rational &rhs) const {
        return Rational(numerator * rhs.numerator, denominator * rhs.denominator);
    }

    // Overload / operator
    Rational operator/(const Rational &rhs) const {
        if (rhs.numerator == 0) {
            cerr << "Error: Division by zero." << endl;
            exit(1);
        }
        return Rational(numerator * rhs.denominator, denominator * rhs.numerator);
    }

    // Overload >> operator (input)
    friend istream &operator>>(istream &in, Rational &r) {
        char slash;
        in >> r.numerator >> slash >> r.denominator;
        if (r.denominator == 0) {
            cerr << "Error: Denominator cannot be zero." << endl;
            exit(1);
        }
        r.normalize();
        return in;
    }

    // Overload << operator (output)
    friend ostream &operator<<(ostream &out, const Rational &r) {
        out << r.numerator << "/" << r.denominator;
        return out;
    }
};

// Test program
int main() {
    Rational r1, r2(3), r3(4, -8);

    cout << "Default constructor: " << r1 << endl;
    cout << "Single integer constructor: " << r2 << endl;
    cout << "Two integers constructor (normalized): " << r3 << endl;

    Rational a(1, 2), b(3, 4);
    cout << "a = " << a << ", b = " << b << endl;
    cout << "a + b = " << (a + b) << endl;
    cout << "a - b = " << (a - b) << endl;
    cout << "a * b = " << (a * b) << endl;
    cout << "a / b = " << (a / b) << endl;

    cout << "Comparison: " << endl;
    cout << "a == b: " << (a == b) << endl;
    cout << "a < b: " << (a < b) << endl;
    cout << "a <= b: " << (a <= b) << endl;
    cout << "a > b: " << (a > b) << endl;
    cout << "a >= b: " << (a >= b) << endl;

    // Input test
    Rational inputR;
    cout << "Enter a rational number in the form a/b: ";
    cin >> inputR;
    cout << "You entered: " << inputR << endl;
    
    return 0;
}

