#include <iostream>
#include <iomanip>
using namespace std;
// Fucntion to get interest
double get_interest_rate(){
    double user_input;
    do{
        cout << "Please enter the annual interest rate as a percentage (e.g., 15 for 15%) (enter 0 to quit): ";
        cin >> user_input;
    }while(user_input < 0);
    return user_input;
}
// Function to get loan amount
int get_loan_amount(){
    int user_input;
    do{
        cout << "Enter the amount you would like to recieve: ";
        cin >> user_input;
    }while(user_input <= 0);
    return user_input;
}
// Function for a mount of period
int get_period(){
    int user_input;
    do{
        cout << "Please enter loan period in months: ";
        cin >> user_input;
    }while (user_input <= 0);
    return user_input;
}
// function calculate face value
double get_FaceValue(double rate, int amount, int month){
    // find monthly interest rate 
    double monthly_rate = (rate / 12) / 100;
    // find discount 
    double discount = monthly_rate * month;
    // find face value
    double face_value = amount / (1 - discount);
    return face_value;
}
// Function to calculate monthly payment
double get_monthlyPayment(double face_value, int month){
    double monthly_payment = face_value / month;
    return monthly_payment;
}
int main(){
    int month, amount;
    double rate, face_value, monthly_payment;
    bool again = true;
    // loop if rate = 0 the program end if not the program will keep asking user for input
    while (again){
    // call function
    rate = get_interest_rate();
    // comparing rate's value with 0
    if (rate == 0){
        again = false;
        cout << "Exiting the program ";
        return 0;
    }
    // call function
    amount = get_loan_amount();
    month = get_period();
    face_value = get_FaceValue(rate, amount, month);
    monthly_payment = get_monthlyPayment(face_value, month);
    // display message and information
    cout << "The total amount of your loan (including interest at " << rate << " per annum) is $ "<< fixed << setprecision(2) << face_value << endl;
    cout << "Your monthly payment for " << month << " months will be: $" << fixed << setprecision(2) << monthly_payment << endl;
    }
    return 0;
}


