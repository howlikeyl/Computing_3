/*
Senghak Heng and Daisy Takang: overloading operator
Lindsey Yobo and SethaSebastian Yem: main function and mutator
*/
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
class ComplexNumber {

public:
    ComplexNumber() {
        real = 0;
        imag = 0;
    }
    ComplexNumber(double r, double m) {
        real = r;
        imag = m;
    }
    void setReal(double r) {
        real = r;
    }
    void setImag(double m) {
        imag = m;
    }
    int getReal() {
        return real;
    }
    int getImag() {
        return imag;
    }
    ComplexNumber operator+(const ComplexNumber& other) {
        double r = real + other.real;
        double i = imag + other.imag;
        return ComplexNumber(r, i);
    }
    ComplexNumber operator-(const ComplexNumber& other) {
        double r = real - other.real;
        double i = imag - other.imag;
        return ComplexNumber(r, i);
    }
    ComplexNumber operator*(const ComplexNumber& other) {
        double r1 = real * other.real;
        double i1 = real * other.imag;
        double i2 = imag * other.real;
        double r2 = imag * other.imag;
        double r3 = r1 - r2;
        double i3 = i1 + i2;
        return ComplexNumber(r3, i3);
    }
    ComplexNumber operator/(const ComplexNumber& other) {
        double denominator = pow(other.real, 2) + pow(other.imag, 2);
        double r1 = (real * other.real + imag * other.imag) / denominator;
        double i1 = (imag * other.real - real * other.imag) / denominator;
        return ComplexNumber(r1, i1);
    }
    ComplexNumber operator!() {
        return ComplexNumber(real, -imag);
    }
    friend ostream& operator<<(ostream& out, const ComplexNumber& other);

private:
    double real;
    double imag;
};
int main() {
    ComplexNumber c1;
    ComplexNumber c2(1, 2);
    ComplexNumber c3(3, 4);
    ComplexNumber c4;
    ComplexNumber c5;
    ComplexNumber c6;
    cout << endl;
    cout << "Value of c1 (default constructor):" << endl;
    cout << "c1.Re() == 0, c1.Im() == 0" << endl;
    cout << "Value of c2 (value constructor):" << endl;
    cout << "c2.Re() == 1, c2.Im() == 2" << endl;
    cout << endl;
    c4 = c2 + c3;
    cout << "c2 + c3 " << "(" << c2 << " + " << c3 << ") == " << c4 << endl;
    c4 = c2 - c3;
    cout << "c2 - c3 " << "(" << c2 << " - " << c3 << ") == " << c4 << endl;
    c4 = c2 * c3;
    cout << "c2 * c3 " << "(" << c2 << " * " << c3 << ") == " << c4 << endl;
    c5 = c2 / c3;
    cout << "c2 / c3 " << "(" << c2 << " / " << c3 << ") == " << c5 << endl;
    c6 = c5 + c4;
    cout << "(c2 / c3) + (c2 * c3) == " << c6 << endl;
    cout << "c2 is currently 1+2i; !c2 (complex conjugate of c2) == " << !c2 << endl;
    vector<ComplexNumber> vec;
    for (int n = 0; n < 10; ++n) {
        vec.push_back(ComplexNumber(n, 2 * n));
    }

    cout << "\nVector output using indexed for-loop:" << endl;
    for (int i = 0; i < vec.size(); ++i) {
        cout << vec[i] << endl;
    }

    cout << "\nVector output using an iterator in for-loop:" << endl;
    for (auto it = vec.begin(); it != vec.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}
ostream& operator<<(ostream& out, const ComplexNumber& other) {
    out << other.real << "+" << other.imag << "i";
    return out;
}