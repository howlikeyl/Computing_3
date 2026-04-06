/***********************************************
Author: Senghak heng
Date: 03/28/2025
Purpose: The Code will display the detail of the truct and it owner
Sources of Help: 
w3School: https://www.w3schools.com/cpp/default.asp
geekforgeek: https://www.geeksforgeeks.org
stackoverflow: https://stackoverflow.com/questions
Time Spent: 3hours
on the assignment here>
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
Date: 03/28/2025
Name: Senghak Heng
*/
#include <iostream>
#include <string>
using namespace std;
class Person
{
public:
Person(){
    name = "None";
}
Person(string theName){
    name = theName;
}
Person(const Person& theObject){
    name = theObject.name;
}
string getName()const{
    return name;
}
Person& operator=(const Person& rtSide){
    if (this != &rtSide){
        name = rtSide.name;
    }
    return *this;
}
friend istream& operator >>(istream& inStream, Person& personObject){
    cout << "Enter Your name: ";
    inStream >> personObject.name;
    return inStream;
}
friend ostream& operator <<(ostream& outStream, const Person& pObject){
    outStream << pObject.getName();
    return outStream;
}
private:
string name;
};
class Vehicle{
    public:
    Vehicle(){
        name = "Unknow Manufactory";
        cylinder = 0;
        owner = Person();
    }
    Vehicle(string Name, int Cylinder, Person Owner){
        name = Name;
        cylinder = Cylinder;
        owner = Owner;
    }
    Vehicle(const Vehicle& other){
        name = other.name;
        cylinder = other.cylinder;
        owner = other.owner;
    }
    Vehicle& operator=(Vehicle &other){
        if (this != &other){
            name = other.name;
            cylinder = other.cylinder;
            owner = other.owner;
        }
        return *this;
    }
    void setOwner(Person owner){
        if (owner.getName() == "None"){
            owner = Person("Unknown Owner");
        }
        this->owner = owner;
    }
    string getName()const{
        return name;
    }
    int getCylinder()const{
        return cylinder;
    }
    Person getOwner()const{
        return owner;
    }
    friend ostream &operator<<(ostream &outStream, const Vehicle &other){
        outStream << other.name << ", " << other.cylinder << " Cylinders, belong to: " << other.owner; 
        return outStream;
    }
    private:
    string name;
    int cylinder;
    Person owner;
};
class Truck :public Vehicle{
    public:
    Truck() :Vehicle(){
        load = 0.0;
        tow = 0;
    }
    Truck(string Name, int Cylinder, Person Owner, double Load, int Tow) :Vehicle(Name, Cylinder, Owner){
        load = Load;
        tow = Tow;
    }
    Truck(const Truck &other) :Vehicle(other){
        load = other.load;
        tow = other.tow;
    }
    Truck &operator=(Truck &other){
        Vehicle:operator=(other);
        if (this != &other){
            load = other.load;
            tow = other.tow;
        }
        return *this;
    }
    double getLoad()const{
        return load;
    }
    int getTow()const{
        return tow;
    }
    friend ostream &operator<<(ostream &outStream, const Truck &other){
        outStream << other.getName() << ", " << other.getCylinder() << " cylinders, belong to: " <<  other.getOwner() << ", Load capacity: " << other.load << ", towing capacity: " << other.getTow();
        return outStream;
    }
    private:
    double load;
    int tow;
};
int main(){
    cout << "///////////////// Testing Person Class ////////////////" << endl;
    Person p0;
    cout << "Testing default constructor: the person is: " << p0<< endl;
    Person p1("Sirong Lin");
    cout << "Testing constructor(string): I am: " << p1 << endl;
    Person p2(p1);
    cout << "Testing copy constructor: another me is: " << p2 << endl;
    Person p3;
    cout << "Testing >> overloading: ";
    cin >> p3;
    cout << "You're" << p3;
    p0 = p3;
    cout << "Testing = overloading: Another you is: " << p0.getName() << endl;
    cout << endl;
    cout << "///////////////// Testing Vehicle Class ////////////////" << endl;
    cout << endl;
    Vehicle v0;
    cout << "Testing default constructor: the Vehicle is: " << endl;
    cout << v0 << endl;
    Vehicle v1("Ford Van", 8, p1);
    cout << "Testing constructor(args): for my car: " << endl;
    cout << v1 << endl;
    Vehicle v2(v1);
    cout << "Testing copy constructor: another car is: " << endl;
    cout << v2 << endl;
    Vehicle v3("Ford", 6, Person("James Smith"));
    cout << "Testing = overloading: Your Car is: " << endl;
    cout << v3 << endl;
    Vehicle v4;
    v4 = v3;
    cout << "yourSecondCar is: " << v4 << endl;
    cout << endl;
    cout << "///////////////// Testing Truck Class ////////////////" << endl;
    cout << endl;
    cout << "Testing default constructor: the Truck is: " << endl;
    Truck t0;
    cout << t0 << endl;
    cout << "Testing constructor(args): for a truck: " << endl;
    Person person("Mike Elf");
    Truck t1("Mac", 8, person, 250, 2000);
    cout << t1 << endl;
    cout << "Testing copy constructor: copied truck: " << endl;
    Truck t2(t1);
    cout << t2;
    cout << "Testing = overloading: " << endl;
    Truck t3("Toyota Truck", 8, Person("James Smith"), 200, 5000);
    cout << "Testing = overloading: hisTruck is: " << t3 << endl;
    Truck t4;
    t4 = t3;
    cout << "his same Truck is: " << t4 << endl;
    return 0;
}