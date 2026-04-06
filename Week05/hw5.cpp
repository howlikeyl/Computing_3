/***********************************************
Author: Senghak Heng
Date: 02/23/2025
Purpose: The program will ask the user to input a fraction. The program also does the arithmetic operation (+, -, *, /), annd comaprition
w3School: https://www.w3schools.com/cpp/default.asp
geekforgeek: https://www.geeksforgeeks.org
stackoverflow: https://stackoverflow.com/questions
Time Spent: 7hours
***********************************************/
/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the
University�s Academic Integrity policy. Students are expected to
strictly avoid academic dishonesty and adhere to the Academic
Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
All programming assignments in this class are to be done by the
student alone. No outside help is permitted except the instructor and
approved tutors.
I certify that the work submitted with this assignment is mine and was
generated in a manner consistent with this document, the course
academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
Date: 02/23/2025
Name: Senghak Heng
*/
#include <iostream>
#include <string>
using namespace std;
class Rational{
    public:
    Rational(){  //Defualt construtor
        numerator = 0;
        denominator = 1;
    }
    Rational(int WholeNumber){  //constructor with one argument
        numerator = WholeNumber;
        denominator = 1;
    }
    Rational (int n, int d){  //constrcutor with two argument
        numerator = n;
        denominator = d;
        Normalize(numerator, denominator);
    }
    // Getter method
    int getNumerator(){ 
        return numerator;
    }
    int getDenominator(){
        return denominator;
    }
    bool operator==(const Rational& other){  //Comapring operand
        return (numerator == other.numerator && denominator == other.denominator);
    }
    bool operator!=(const Rational& other) {  //Comapring operand
        return (numerator != other.numerator || denominator != other.denominator);
    }
    bool operator >(const Rational& other){  //Comapring operand
        int fraction1 = numerator * other.denominator;
        int fraction2 = other.numerator * denominator;
        return (fraction1 > fraction2);
    }
    bool operator <(const Rational& other){  //comapring operand
        int fraction1 = numerator * other.denominator;
        int fraction2 = other.numerator * denominator;
        return (fraction1 < fraction2);
    }
    Rational operator+(Rational& other){  //Adding operand
        int NewNumerator = (numerator * other.denominator) + (other.numerator * denominator);
        int NewDenominator = denominator * other.denominator;
        Normalize(NewNumerator, NewDenominator);  //call function to simplyfy
        return Rational (NewNumerator, NewDenominator);
    }
    Rational operator-(Rational& other){  //Substrcting operand
        int NewNumerator = (numerator * other.denominator) - (other.numerator * denominator);
        int NewDenominator = denominator * other.denominator;
        Normalize(NewNumerator, NewDenominator);  //call function to simplyfy
        return Rational(NewNumerator, NewDenominator);
    }
    Rational operator*(Rational& other){  //Multiple operand
        int NewNumerator = numerator * other.numerator;
        int NewDenominator = denominator * other.denominator;
        Normalize(NewNumerator, NewDenominator);  //call function to simplyfy
        return Rational(NewNumerator, NewDenominator);
    }
    Rational operator/(Rational& other){  //division operand
        int NewNumerator = numerator * other.denominator;
        int NewDenominator = denominator * other.numerator;
        Normalize(NewNumerator, NewDenominator);  //call function to simplyfy
        return Rational(NewNumerator, NewDenominator);
    }
    friend ostream& operator<<(ostream& outstream, Rational& r);
    friend istream& operator>>(istream& instream, Rational& r);
    private:
    int numerator;
    int denominator;
    // function find gcd
    int findGCD(int n, int d){
        if (n == 0){
            return d;
        }else
        return findGCD(d % n, n);
    }
    void Normalize(int& n, int& d){ //function to simply or normalize the fraction
        int gcd = findGCD(abs(n), abs(d));  //use absolute value to ensure that the GCD are always positive
        n /= gcd;
        d /= gcd;
        if (n < 0 && d < 0) { //ig both denominator and numerator are negative make them positive
            n = -n;
            d = -d;
        }
        else if (d < 0) {  // if denominator are negative make the numerator negative and denominator positive
            n = -n;
            d = -d;
        }
    }
};
ostream& operator<<(ostream& outstream, Rational& r) { //overlaoding output
    cout << "You enter: ";
    outstream << r.getNumerator() << "/" << r.getDenominator() << endl;
    return outstream;
}
istream& operator>>(istream& instream, Rational& r)  //overloading input
{
    bool valid = true;
    while (valid) { //check for valid input
        char c = 'a';
        cout << "Enter a fraction in form of (a/b): ";
        instream >> r.numerator >> c >> r.denominator;
        if (c != '/') {
            cout << "Invalid please enter a fraction in form of (a/b)";
        }
        else
            valid = false;
        r.Normalize(r.numerator, r.denominator);  //call function
    }
    return instream;
}
int main(){
    Rational r1;
    Rational r2(5);
    Rational r3(1, 2);
    Rational r4(22, -12);
    Rational r5(-5, -2);
    Rational r6(10, -5);
    Rational r8(-1, -2);
    Rational r9(120, 100);
    Rational r7;
    //ostream and istream
    cin >> r7;
    cout << r7;
    //testing for all three cases
    cout << string(5, '-') << "Testing all three constructors" << string(5, '-') << endl;
    cout << r1.getNumerator() << "/" << r1.getDenominator() << endl;
    cout << r2.getNumerator() << "/" << r2.getDenominator() << endl;
    cout << r3.getNumerator() << "/" << r3.getDenominator() << endl;
    //Tesitng the operation
    cout << string(5, '-') << "Testing Arithmetic operation" << string(5, '-') << endl;
    r7 = r3 + r4;
    cout << r7.getNumerator() << "/" << r7.getDenominator() << endl;
    r7 = r5 - r6;
    cout << r7.getNumerator() << "/" << r7.getDenominator() << endl;
    r7 = r6 * r4;
    cout << r7.getNumerator() << "/" << r7.getDenominator() << endl;
    r7 = r5 / r4;
    cout << r7.getNumerator() << "/" << r7.getDenominator() << endl;
    //Comaparing opration
    cout << string(5, '-') << "Comparing" << string(5, '-') << endl;
    if(r3 == r8) {
        cout << r3.getNumerator() << "/" << r3.getDenominator() << " == " << r8.getNumerator() << "/" << r8.getDenominator() << endl;
    }
    if (r3 != r5) {
        cout << r3.getNumerator() << "/" << r3.getDenominator() << " != " << r5.getNumerator() << "/" << r5.getDenominator() << endl;
    }
    if (r6 < r5) {
        cout << r6.getNumerator() << "/" << r6.getDenominator() << " < " << r5.getNumerator() << "/" << r5.getDenominator() << endl;
    }else 
        cout << r6.getNumerator() << "/" << r6.getDenominator() << " > " << r5.getNumerator() << "/" << r5.getDenominator() << endl;
    if (r9 > r4) {
        cout << r9.getNumerator() << "/" << r9.getDenominator() << " > " << r4.getNumerator() << "/" << r4.getDenominator() << endl;
    }else
        cout << r9.getNumerator() << "/" << r9.getDenominator() << " < " << r4.getNumerator() << "/" << r4.getDenominator() << endl;
    return 0;
}