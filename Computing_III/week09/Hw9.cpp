/***********************************************
Author: Senghak Heng
Date: 04/06/2025
Purpose: the program will ask the user to play a guessig number game with a computer
w3School: https://www.w3schools.com/cpp/default.asp
geekforgeek: https://www.geeksforgeeks.org
stackoverflow: https://stackoverflow.com/questions
Time Spent: 1hours
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
Date: 04/06/2025
Name: Senghak Heng
*/
#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>
using namespace std;
class Player{
public:
    virtual int getGuess(){
        return 0;
    }
    virtual void checkGuess(int a, int b){
        a = 0;
        b = 0;
    }
};
class HumanPlayer : public Player {
public:
    int getGuess() override {
        int num;
        cout << "Enter a Number: ";
        cin >> num;
        return num;
    }
};
class ComputerPlayer: public Player{
public:
    ComputerPlayer(){
        srand(time(0));
        guess = rand() % 101;
    }
    int getGuess() override {
        return guess;
    }
    void checkGuess(int Guess, int Ran) override{
        srand(time(0));
        if (Guess < Ran){
            guess = Guess + rand() % (101 - Guess);

        }
        else if (Guess > Ran){
            guess = Guess - rand() % (Guess + 1);
        }
    }
    private:
    int guess;
};
bool checkForWin(int guess, int answer)
{
    if (answer == guess)
    {
        cout << "You're right! You win!" << endl;
        return true;
    }
    else if (answer < guess)
        cout << "Your guess is too high." << endl;
    else
        cout << "Your guess is too low." << endl;
    return false;
}
// The play function takes as input two Player objects.
void play(Player &player1, Player &player2) {
    srand(time(0));
    int answer = 0, guess = 0;
    answer = rand() % 100;
    bool win = false;
    while (!win)
    {
        cout << "Player 1's turn to guess." << endl;
        guess = player1.getGuess();
        win = checkForWin(guess, answer);
        if (win) return;
            cout << "Player 2's turn to guess. ";
            player2.checkGuess(guess, answer);
            guess = player2.getGuess();
            cout << "Computer Guess: " << guess << endl;
            win = checkForWin(guess, answer);
    }
}
int main(){
    HumanPlayer p1;
    ComputerPlayer p2;
    play(p1, p2);
    return 0;
}