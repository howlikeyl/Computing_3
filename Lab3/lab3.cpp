// Lindsey Yobo: figure out the calculation and testing the program
// Daisy takang: writing main
// Senghak Heng: setter and getter method
#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
class Mass{
    private:
    double massInDram;
    public:
    Mass (){
        massInDram = 0;
    }
    // setter method 
    // function to check and set mass
    void setMassAvoirdupoisPounds(int ADPounds){
        // check invalid input
        while (true) {
            if (cin.fail() || ADPounds <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Enter a number greater than 0 or an integer: ";
                cin >> ADPounds;
            } else {
                break;
            }
        }
        massInDram = ADPounds * 256;
    }
    // function to check and set mass
    void setMassTroyPounds(int TroyPounds){
        // check for invalid input
        while (true) {
            if (cin.fail() || TroyPounds <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Enter a number greater than 0 or an integer: ";
                cin >> TroyPounds;
            } else {
                break;
            }
        }
        massInDram = TroyPounds * 96;
    }
    // function to check and set mass
    void setMassMetricGrams(int MetricGrams){
        // check for invalid input
        while (true) {
            if (cin.fail() || MetricGrams <= 0) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input! Enter a number greater than 0 or an integer: ";
                cin >> MetricGrams;
            } else {
                break;
            }
        }
        massInDram = MetricGrams / 1.7718451953125;
    }
    // getter method
    double getMassAvoirdupoisPounds(){
        return massInDram / 256;
    }
    double getMassMetricGrams(){
        return massInDram * 1.7718451953125;
    }
    double getMassTroyPounds(){
        return massInDram / 96;
    }
};
int main(){
    bool valid;
    int input, input_mass;
    Mass mass;
    do {
        cout << "Please enter 1 to use Avoirdupois pounds, 2 to use Troy pounds, 3 to use grams, or 0:  ";
        // check for invalid input
        while (!(cin >> input)) {
            cin.clear();  // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Ignore invalid input
            cout << "Invalid input! Please enter an integer: ";
        }
        switch(input){
            case 1: valid = true;
            break;
            case 2: valid = true;
            break;
            case 3: valid = true;
            break;
            case 0: cout << "Thanks! for using the mass program" << endl; return -1;
            break;
            default:
            cout << "invalid input" << endl;
            valid = true;
        }
    if (input == 1){
        cout << "Please enter a mass in Avoirdupois pounds: ";
        cin >> input_mass;
        mass.setMassAvoirdupoisPounds(input_mass);
        cout << "Mass in Avoirdupois pounds is: " << fixed << setprecision(0) << mass.getMassAvoirdupoisPounds() << endl;
        cout << "Mass in Troy pounds is: " << fixed << setprecision(5) << mass.getMassTroyPounds() << endl;
        cout << "Mass in gram is: " << fixed << setprecision(3) << mass.getMassMetricGrams() << endl;
    }
    else if (input == 2){
        cout << "Please enter a mass in Troy pounds: ";
        cin >> input_mass;
        mass.setMassTroyPounds(input_mass);
        cout << "Mass in Avoirdupois pounds is: " << fixed << setprecision(3) << mass.getMassAvoirdupoisPounds() << endl;
        cout << "Mass in Troy pounds is: "<< fixed << setprecision(0) << mass.getMassTroyPounds() << endl;
        cout << "Mass in gram is: " << fixed << setprecision(3) << mass.getMassMetricGrams() << endl;
    }
    else if (input == 3){
        cout << "Please enter a mass in grams: ";
        cin >> input_mass;
        mass.setMassMetricGrams(input_mass);
        cout << "Mass in Avoirdupois pounds is: " << fixed << setprecision(8) << mass.getMassAvoirdupoisPounds() << endl;
        cout << "Mass in Troy pounds is: " << fixed << setprecision(8) << mass.getMassTroyPounds() << endl;
        cout << "Mass in gram is: " << fixed << setprecision(0) << mass.getMassMetricGrams() << endl;
    }
    }while(valid);
    return 0;
}