/***********************************************
Author: Senghak Heng
Date: 05/02/2025
Purpose: The program will rotate the coordinate x and y four times (clockwise), it also move the coordinate.
Sources of Help: slid from class
Time Spent: 1hour
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
Date: 05/02/2025
Name: Senghak heng
*/
#include <iostream>
#include <iomanip>
using namespace std;
// create class name point
class Point {
    private: 
    double x, y;
    public:
    // setter and getter method
    void setX(double newX){
        x = newX;
    }
    void setY(double newY){
        y = newY;
    }
    double getX(){
        return x;
    }
    double getY(){
        return y;
    }
    // function to move the point
    void move_point(double moveX, double moveY){
        x += moveX;
        y += moveY;
    }
    // funtion to rotate the number clockwise
    void rotate_clockwise(double rotateX, double rotateY){
        double temp;
        temp = -rotateY;
        x = temp;
        y = rotateX;
    }
};
int main (){
    Point coordinate;
    // set coordinate to (1, 2)
    coordinate.setX(1);
    coordinate.setY(2);
    // display origin
    cout << "Origin:" << setw (5) << "(" << coordinate.getX() << ", " << coordinate.getY() << ")" << endl;
    // loop to rotate it clockwise 4 time
    for (int i = 1; i < 5; i++){
    coordinate.rotate_clockwise(coordinate.getX(), coordinate.getY());
    cout << "Rotate:" << i << setw (4) << "(" << coordinate.getX() << ", " << coordinate.getY() << ")" << endl;
    }
    cout << endl;
    // set x and y coordinate to (3, 4) and move (1,1)
    coordinate.setX(3);
    coordinate.setY(4);
    cout << "Origin:" << setw (5) << "(" << coordinate.getX() << ", " << coordinate.getY() << ")" << endl;
    coordinate.move_point(1, 1);
    cout <<  "Move to:" << setw (4)<< "(" << coordinate.getX() << ", " << coordinate.getY() << ")" << endl;
    cout << endl;
    // set x and y to (5, -4) then move it (5, -4)
    coordinate.setX(5);
    coordinate.setY(-4);
    cout << "Origin:" << setw (5) << "(" << coordinate.getX() << ", " << coordinate.getY() << ")" << endl;
    coordinate.move_point(-5, 4);
    cout <<  "Move to:" << setw (4)<< "(" << coordinate.getX() << ", " << coordinate.getY() << ")" << endl;
    return 0;
}
