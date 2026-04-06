// class Money{
//     public: 
//     Money();
//     Money(int dollars, int cents);
//     Money(int dollars);
//     Money(double amount);
//     int getCents(void)const;
//     int getDollars(void)const;
//     friend const Money operator+(const Money& amt1, const Money& amt2);
//     private:
//     int dollars;
//     int cents;
// };
//     const Money operator+(const Money& amt1, const Money& amt2);
//     Money baseAmount(120,40);
//     Money fullAmount(120);
#include <iostream>
using namespace std;
class Rectangle{
    public:
    Rectangle(): width(1), length(1){}
    Rectangle(int w, int l): width(w), length(l){}
    int getWidth(void)const;{ return width;}
    void setWidth(int w){ width = w; }
    int getLength(void)const;{ return length;}
    void setLength(int l){ length = l;}
    private:
    int width;
    int length;
};
int main(){
    Rectangle r1, r2;
    cout << "Please enter values for a rectangle: ";
    cin >> r1;
    cout << "r1 is: " << r1 << endl;
    if (r1 !=r2)
    cout << "Note equal" << endl;
    else
    cout << "equal" << endl;
    return 0;
}