#include <iostream>
using namespace std;
// class Student{
//     private:
//     string name;
//     int marks;
//     public:
//     Student(string n, int m);
//     void displayInfo(void);
// };
// int main(){
//     Student a ("Senghak", 12);
//     a.displayInfo();
//     Student s[2] = {Student("mark", 12), Student("heng", 10)};
//     s[0].displayInfo();
//     s[1].displayInfo();
//     return 0;
// }
// Student::Student(string n, int m){
//     name = n;
//     marks = m;
// }
// void Student :: displayInfo(void){
//     cout << "student: " << name << "    age: " << marks << endl;
// }

// class Product{
//     private:
//     string name;
//     float price;
//     public:
//     Product(string n, float p);
//     void displayProductInfo();
// };
// int main(){
//     Product p[3] = {Product("Laptop", 1500.99), Product("Phone", 799.49), Product("HeadPhones", 199.99)};
//     for (int i = 0; i < 3; i++){
//         p[i].displayProductInfo();
//     }
// }
// Product :: Product (string n, float p){
//     name = n;
//     price = p;
// }
// void Product :: displayProductInfo(){
//     cout << name << "  -  " << price << endl; 
// }

class Book{
    private:
    string title, author;
    int pages;
    public:
    Book(string t, string a, int p){
        title = t;
        author = a;
        pages = p;
    }
    void setDetails(string t, string a, int p){
        title = t;
        author = a;
        pages = p;
    }
    void displayBookInfo(){
        cout << title << " by - " << author << " - Pages: " << pages << endl;
    }
};
int main(){
    Book b[3] = {Book("The Great Gatsby","F. Scott Fitzgerald", 180), Book("To Kill a Mockingbird ", "Harper Lee,", 281), Book("1984", "George Orwell", 328)};
    for (int i = 0; i < 3; i++){
        b[i].displayBookInfo();
    }
    return 0;
}