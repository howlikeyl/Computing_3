/***********************************************
Author: Senghak Heng
Date: 04/18/2025
Purpose: the program ask the user to enter the capcity and element of the arrays it catch an exception if their an error
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
Date: 04/18/2025
Name: Senghak Heng
*/
#include <iostream>
#include <string>

using namespace std;

void testPFArrayD(void);

//Objects of this class are partially filled arrays of doubles.
class OutOfRange{
    public:
        OutOfRange(int index, string err){
            Index = index;
            Err = err;
        } 
        int index()const { return Index; }
        string err()const { return Err; }
    private:
        int Index;
        string Err;
};
class PFArrayD
{
public:
    PFArrayD(){
        capacity = 50;
        a = new double [capacity];
        used = 0;
    }
    //Initializes with a capacity of 50.
    
    PFArrayD(int capacityValue){
        this->capacity = capacityValue;
        this->a = new double [capacity];
        this->used = 0;
    }
    
    PFArrayD(const PFArrayD& pfaObject){
        capacity = pfaObject.capacity;
    }
    void addElement(double element){
        if (!full()){
            a[used] = element;
            used++;
        }else{
            throw OutOfRange(used, "arrays is full");
        }
    }
    //Precondition: The array is not full.
    //Postcondition: The element has been added.
    
    bool full( ) const { return (capacity == used); }
    //Returns true if the array is full, false otherwise.
    
    int getCapacity( ) const { return capacity; }
    
    int getNumberUsed( ) const { return used; }
    
    void emptyArray( ){ used = 0; }
    //Empties the array.
    
    double& operator[](int index){
        if (index < 0 || index >= used) {
            throw OutOfRange(index, "Index out of bounds.");
        }
        return a[index];
    }
    //Read and change access to elements 0 through numberUsed - 1.
    PFArrayD& operator =(const PFArrayD& rightSide){
        if (this !=  &rightSide){
            delete[] a;
            capacity = rightSide.capacity;
            used = rightSide.used;
            a = new double[capacity];
            for (int i = 0; i < used; i++){
                a[i] = rightSide.a[i];
            }
        }
        return *this;
    }
    
    ~PFArrayD( ){
        delete[] a;
    }
private:
    double *a; //for an array of doubles.
    int capacity; //for the size of the array.
    int used; //for the number of array positions currently in use.
    
};
void testException() {
    PFArrayD arr(1);
    try {
        cout << arr[2] << endl;
    } catch (OutOfRange e) {
        cout << "Exception caught! " << e.err() << " Index: " << e.index() << endl;
    }
    try {
        arr.addElement(2);
        arr.addElement(3);
    } catch (OutOfRange e) {
        cout << "Exception caught! " << e.err() << " Index: " << e.index() << endl;
    }
}
int main(int argc, char *argv[])
{
     cout << "This program tests the class PFArrayD.\n";
     
     char ans;
     do
     {
         testPFArrayD( );
         cout << "Test again? (y/n) ";
         cin >> ans;
     }while ((ans == 'y') || (ans == 'Y'));
    testException();
    return 0;
}

void testPFArrayD( )
{
    int cap;
    cout << "Enter capacity of this super array: ";
    cin >> cap;
    PFArrayD temp(cap);
    
    cout << "Enter up to " << cap << " nonnegative numbers.\n";
    cout << "Place a negative number at the end.\n";
    
    double next;
    cin >> next;
    while ((next >= 0) && (!temp.full( )))
    {
        temp.addElement(next);
        cin >> next;
    }
    
    cout << "You entered the following "
    << temp.getNumberUsed( ) << " numbers:\n";
    int index;
    int count = temp.getNumberUsed( );
    for (index = 0; index < count; index++)
        cout << temp[index] << " ";
    cout << endl;
    cout << "(plus a sentinel value.)\n";
}