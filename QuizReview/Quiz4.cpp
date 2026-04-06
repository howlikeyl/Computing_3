#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    int pages;
public:
    // Parameterized constructor
    Book(string t, int p) : title(t), pages(p) {
        cout << "Book created: " << title << endl;
    }

    // Destructor
    ~Book() {
        cout << "Book destroyed: " << title << endl;
    }

    // Method to display book info
    void displayInfo() const {
        cout << "Title: " << title << ", Pages: " << pages << endl;
    }
};

int main() {
    Book book1("C++ Programming", 350);
    book1.displayInfo();
    return 0;
}
