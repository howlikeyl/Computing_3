// Group5: Senghak Heng, Daisy takang, Lindsey Yobo
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
// function to get user input
void getInput(int &pounds, double &ounces){
    bool check_pounds = true;
    bool check_ounces = true;
    // check for invalid input
    do{
        cout << "Please enter the number of pounds: ";
        cin >> pounds;
        if (pounds < 0 || cin.fail()){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
            cout << "That's not a number >= 0! Please try again..." << endl;
        }else 
        check_pounds = false;
    }while (check_pounds);
    // check for invalid input
    do{
        cout << "Please enter the number of ounces: ";
        cin >> ounces;
        if (ounces <= 0 || cin.fail() || ounces >= 16 ){
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // Discard invalid input
            cout << "That's not a number >= 0, and < 16! Please try again..." << endl;
        }else 
        check_ounces = false;
    }while (check_ounces);
}
// Function for conversion and calculation
void convertWeight(const int pounds, const double ounces, int& kilograms, double& grams){
    // combine ounce and pounds, 16 ounces in 1 pound
    double total_pounds = pounds + (ounces /16);
    // convert pound to kilograms
    double total_kilograms;
    total_kilograms = total_pounds * 0.45359237;
    // split kilogram and grams
    grams = (total_kilograms - floor(total_kilograms)) * 1000;
    kilograms = floor(total_kilograms);
}
// Function to displayResult
void displayResult(const int pounds, const double ounces, const int& kilograms, const double& grams){
    cout << pounds << " pounds and " << fixed << setprecision (8) << ounces << " ounces convert to " << kilograms << " kilograms and " << fixed << setprecision(8) << grams << " grams" << endl;
}
int main(){
    double o, g;
    int p, k;
    // call Function
    getInput(p, o);
    convertWeight(p, o, k, g);
    displayResult(p, o, k, g);
    return 0;
}