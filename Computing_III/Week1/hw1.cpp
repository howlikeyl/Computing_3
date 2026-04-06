/***********************************************
Author: Senghak Heng
Date: 01/30/2024
Purpose: The program will ask the user to enter two number than the user have to guess a random number that generate between the two prevoiuse number.
The user will ask for how many time do they want to guess with the maximun allow guesses are 10. if the user cant get the correct number you'll lose.
Finally the program will ask the user if they want to play again.
Sources of Help: StackoverFlow, GeekforGeek, youtube
https://stackoverflow.com/questions/11943525/seeding-a-random-number-generator-c
https://www.geeksforgeeks.org
Time Spent: 3hours
***********************************************/
/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining good order in the classroom, providing an enriching learning experience for students, and as training as a practicing computing professional upon graduation. This practice is manifested in the University’s Academic Integrity policy. Students are expected to strictly avoid academic dishonesty and adhere to the Academic Integrity policy as outlined in the course catalog. Violations will
be dealt with as outlined therein.
All programming assignments in this class are to be done by the student alone. No outside help is permitted except the instructor and
approved tutors.
I certify that the work submitted with this assignment is mine and was generated in a manner consistent with this document, the course academic policy on the course website on Blackboard, and the UMass
Lowell academic code.
Date: 01/30/2024
Name: Senghak Heng
*/
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <cctype> //required for lowercase
using namespace std;
// Function to validate and get a positive minimum number
int getMin() {
    int min;
    do {
        cout << "Enter a positive minimum number: ";
        cin >> min;
    } while (min <= 0);
    return min;
}

// Function to validate and get a maximum number greater than the minimum
int getMax(int min) {
    int max;
    do {
        cout << "Enter a maximum number that is greater than the minimum and less than 1,000: ";
        cin >> max;
    } while (max <= min || max >= 1000);
    return max;
}

// Function to validate and get the number of guesses (between 1 and 10)
int getGuess() {
    int guess;
    do {
        cout << "Enter the number of guesses (allow 10): ";
        cin >> guess;
        if (guess < 0) {
            cout << "Please enter a number from 1 - 10: " << endl;
        }
    } while (guess <= 0 || guess > 10);
    return guess;
}
int main(){
    // data type
    int guess;
    int user_input; 
    bool play_again = true;
    int min, max;
    // canll function Get valid inputs
    min = getMin();
    max = getMax(min);
    guess = getGuess();

    // set max_guess to const to ensure the value will not change
    const int max_guess = guess;
    //do while loop for the game
    do{
        // data type
        int k = 0;
        //user prompt
        cout << "Now i have a number between " << min << " and " << max << ". Can you guess my number? Please enter the number you guess: " << endl;
        //generate random number between the min and max and store value
        srand(static_cast<unsigned>(time(0)));
        int random = rand() % (max - min + 1) + min; 
        // keep track of how many time have the user guess
        for ( int i = 0; i < max_guess; i ++)
        {
            cout << "Enter your guess number: ";
            cin >> user_input;
            k++;
            // // check and give user a hint about the number user guess if they guess correct it will exit the loop 
            if (user_input < random){
                cout << "Too low! Try again." << endl;
            }
            else if (user_input > random){
                cout << "Too high! Try again." << endl;
            }
            else if (user_input == random){
                cout << "Congratulation! You guessed the correct number " << endl;
                break;
            }
            // if the user use all of their guesses and still wrong the program will display this message
            if (k == guess){
                cout << "Sorry! you cant guess anymore. The number is: " << random << endl;
            }
        }
        //asking if they player want to play again
        cout << "Do you want to play again (Y/N)";
        string choice;
        cin >> choice;
        // handling invalid input
        while (tolower(choice[0]) != 'y' && tolower(choice[0]) != 'n'){
            cout << "Invalid choice. Please enter Y (yes) or N (no)";
            cin >> choice;
        }
        // if Y set boolean to true
        if (tolower(choice[0]) == 'y'){
            play_again = true;
        }
        // if N set boolean to false and exit 
        if (tolower(choice[0]) == 'n'){
            play_again = false;
            cout << "Thanks for playing the game" << endl;
        }
    }while(play_again);
    return 0;
}
    