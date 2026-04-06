#include <iostream>
#include <vector>
#include <string>
using namespace std;
// class Student{
//     private:
//     string* name;
//     int* age;
//     vector<string>* subject;
//     public:
//     Student(){
//         name = new string("");
//         age = new int(0);
//         subject = new vector<string>();
//     }
//     Student(string n,int a,vector<string> s){
//         name = new string(n);
//         age = new int(a);
//         subject = new vector<string>(s);
//     }
//     Student(const Student& other){
//         name = new string(*other.name);
//         age = new int(*other.age);
//         subject = new vector<string>(*other.subject);
//     }
//     ~Student(){
//         delete name;
//         delete age;
//         delete subject;
//         cout << "Destructo Called" << endl;
//     }
//     void printStudentDetails() const{
//         cout << "name; " << *name << "age: " << *age << "Subject: ";
//         for (int i = 0; i < subject->size(); i++){
//             cout << subject->at(i) << " ";
//         }
//     }
//     // void setName(const string* names){
//     //     *name = names;
//     // }
//     // void addSuject(const string& subjects){
//     //     subject->push_back(subjects);
//     // }
// };
// int main(){
//     vector<string> s = {"Horror", "THriller"};
//     Student s1("John", 20, s);
//     s1.printStudentDetails();
// }
class Book{
    private:
    string* title;
    string* author;
    int* publicationyear;
    vector<string>* genre;
    public:
    Book(){
        title = new string("");
        author = new string("");
        publicationyear = new int(0);
        genre = new vector<string>();
    }
    Book(string t, string a, int p, vector<string> g){
        title = new string(t);
        author = new string(a);
        publicationyear = new int(p);
        genre = new vector<string>(g);
    }
    Book(const Book& other){
        title = new string(*other.title);
        author = new string(*other.author);
        publicationyear = new int(*other.publicationyear);
        genre = new vector<string>(*other.genre);
    }
    ~Book(){
        delete title;
        delete author;
        delete publicationyear;
        delete genre;
    }
    void printBookDetails() const{
        cout << "Title: " << *title << ", Author: " << *author << ", Publication: " << *publicationyear << ", Genre: ";
        for (int i = 0; i < genre->size(); i++){
            cout << genre->at(i) << ", ";
        }
        cout << endl;
    }
};
int main(){
    vector<string> g = {"Horror", "Thriller"};
    Book b1("Harry Potter", "J.K. Rowling", 2000, g);
    b1.printBookDetails();
    Book b2 = b1;
    b2.printBookDetails();
}