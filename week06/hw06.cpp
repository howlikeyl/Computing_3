/***********************************************
Author: Senghak Heng
Date: 03/05/2025
Purpose: Create a class call dynamicArrays and make it behavior like a vector
Sources of Help: 
w3School: https://www.w3schools.com/cpp/default.asp
geekforgeek: https://www.geeksforgeeks.org
stackoverflow: https://stackoverflow.com/questions
Time Spent: 3hours
***********************************************/
/*
Computing III -- COMP.2010 Honor Statement
The practice of good ethical behavior is essential for maintaining
good order in the classroom, providing an enriching learning
experience for students, and as training as a practicing computing
professional upon graduation. This practice is manifested in the
University’s Academic Integrity policy. Students are expected to
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
Date:03/05/2025
Name: Senghak Heng
*/

#include <iostream>
using namespace std;
class  DynamicStringArray{
    public:
    // default constructor
    DynamicStringArray(){
        dynamicArray = nullptr;
        size = 0;
    }
    // function return size
    int getSize(){
        return size;
    }
    // function to add element
    void addEntry(const string input){
        string* NewDynamicArray = new string [size +1];
        for (int i = 0; i < size; i++){
            NewDynamicArray[i] = dynamicArray[i];
        }
        NewDynamicArray[size] = input;
        size++;
        delete[] dynamicArray;
        dynamicArray = NewDynamicArray;
    }
    // function to delete element
    bool deleteEntry(const string input){
        string* NewDynamicArray = new string[size -1];
        bool found = false;
        int j = 0;
        if (!found){
            return false;
        }
        for (int i = 0; i < size; i++){
            if (dynamicArray[i] == input){
                found = true;
                continue; //skip the element
            }
            NewDynamicArray[j++] = dynamicArray[i];
        }
        delete[] dynamicArray;
        dynamicArray = NewDynamicArray;
        size--;
        return true;
    }
    // function get entry
    string* getEntry(int input){
        if (input >= size){
            return nullptr;
        }
        return &dynamicArray[input];
    }
    // copy constructor
    DynamicStringArray(const DynamicStringArray& other){
        size = other.size;
        dynamicArray = new string[size];
        for (int i = 0; i < size; i++){
            dynamicArray[i] = other.dynamicArray[i];
        }
    }
    // copy assignment operator
    DynamicStringArray& operator=(const DynamicStringArray& other){
        if (this != &other){
            size = other.size;
            delete[] dynamicArray;
            dynamicArray = new string [size];
            for (int i = 0; i < size; i++){
                dynamicArray[i] = other.dynamicArray[i];
            }
        }
        return *this;
    }
    // destructor
    ~DynamicStringArray(){
        delete[] dynamicArray;
    }
    private:
    string* dynamicArray;
    int size;

};
int main (){
DynamicStringArray arr;

    // Add some entries
    arr.addEntry("One");
    arr.addEntry("Two");
    arr.addEntry("Three");

    // Print size and entries
    cout << "Size: " << arr.getSize() << endl;
    for (int i = 0; i < arr.getSize(); ++i) {
        cout << *arr.getEntry(i) << " ";
    }
    cout << endl;

    // Delete an entry
    if (arr.deleteEntry("Three")) {
        cout << "\"Three\" deleted!" << endl;
    } else {
        cout << "\"Three\" not found!" << endl;
    }

    // Print size and entries after deletion
    cout << "Size: " << arr.getSize() << endl;
    for (int i = 0; i < arr.getSize(); ++i) {
        cout << *arr.getEntry(i) << " ";
    }
    cout << endl;

    return 0;
}