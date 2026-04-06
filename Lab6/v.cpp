#undef debug

#include <iostream>
#include <string>

using namespace std;

template<typename T>
class BSTNode {

public:
    // Constructors, etc.
    BSTNode() : _data(0), _left(nullptr), _right(nullptr) {} // default constructor
    BSTNode(T data) : _left(nullptr), _right(nullptr) { _data = data; } // value constructor
    BSTNode(BSTNode&); // copy constructor
    ~BSTNode(); // destructor
    BSTNode& operator= (BSTNode&); // copy assignment operator

    void insert(const T& data);

    // Accessor and mutator functions
    BSTNode<T>* getLeft() const { return _left; }
    BSTNode<T>* getRight() const { return _right; }
    T& getData() const { return _data; }
    void setData(const T& data) { _data = data; }

    // Display functions used by operator<<.
    void inOrderDisplay(ostream&) const;
    void preOrderDisplay(ostream&) const;
    void postOrderDisplay(ostream&) const;

    // Display all three methods at once
    friend ostream& operator<< (ostream& out, const BSTNode<T>& b)
    {
        out << "In-Order == ";
        b.inOrderDisplay(out);
        out << "\nPre-Order == ";
        b.preOrderDisplay(out);
        out << "\nPost-Order == ";
        b.postOrderDisplay(out);
        return out;
    }

private:
    T _data;
    BSTNode<T>* _left;
    BSTNode<T>* _right;

    // private helper functions
    void addLeft(const T& data) { _left = new BSTNode(data); }
    void addRight(const T& data) { _right = new BSTNode(data); }
};

template<typename T>
BSTNode<T>::BSTNode(BSTNode& b) {
    _data = b._data;
    _left = _right = nullptr;
    if (b._left != nullptr) _left = new BSTNode<T>(*b._left);
    if (b._right != nullptr) _right = new BSTNode<T>(*b._right);
}

template<typename T>
BSTNode<T>::~BSTNode() {
    delete _left;
    delete _right;
}

template<typename T>
BSTNode<T>& BSTNode<T>::operator= (BSTNode& b) {
    _data = b._data;
    _left = _right = nullptr;
    if (b._left != nullptr) _left = new BSTNode<T>(*b._left);
    if (b._right != nullptr) _right = new BSTNode<T>(*b._right);
    return *this;
}

template<typename T>
void BSTNode<T>::insert(const T& data) {
    if (data < _data){
        if (_left != nullptr){
            _left->insert(data);
        } else {
            _left = new BSTNode<T>(data);
        }
    }
    else if (data > _data){
        if (_right != nullptr){
            _right->insert(data);
        } else {
            _right = new BSTNode<T>(data);
        }
    }
}

template<typename T>
void BSTNode<T>::inOrderDisplay(ostream& out) const {
    if (_left != nullptr) {
        _left->inOrderDisplay(out);
        out << ", ";
    }
    out << _data;
    if (_right != nullptr) {
        out << ", ";
        _right->inOrderDisplay(out);
    }
}

template<typename T>
void BSTNode<T>::preOrderDisplay(ostream& out) const {
    out << _data;
    if (_left != nullptr){
        out << ", ";
        _left->preOrderDisplay(out);
    }
    if (_right != nullptr){
        out << ", ";
        _right->preOrderDisplay(out);
    }
}

template<typename T>
void BSTNode<T>::postOrderDisplay(ostream& out) const {
    if (_left != nullptr){
        _left->postOrderDisplay(out);
        out << ", ";
    }
    if (_right != nullptr){
        _right->postOrderDisplay(out);
        out << ", ";
    }
    out << _data;
}

int main(void) {
    BSTNode<int> iroot(100);
    iroot.insert(10);
    iroot.insert(20);
    iroot.insert(200);
    iroot.insert(300);
    cout << "iroot == " << iroot << endl;

    BSTNode<string> sroot("Sunday");
    sroot.insert("Monday");
    sroot.insert("Tuesday");
    sroot.insert("Wednesday");
    sroot.insert("Thursday");
    sroot.insert("Friday");
    sroot.insert("Saturday");
    cout << "sroot == " << sroot << endl;

    return 0;
}
