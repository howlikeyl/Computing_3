/*
Senghak Heng: UnorderMap
Lindsey Yobo: listify function and list
SethaSebastian Yem: for loop
*/

#undef debug

#include <iostream>
#include <string>
#include <list>
#include <unordered_map>
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
	
	// ***** Your group will define/implement the insert function
	// ***** at about line 89 below...
	void insert(const T& data);
	
	// Accessor and mutator functions
    BSTNode<T>* getLeft() const { return _left; }
	BSTNode<T>* getRight() const { return _right; }
	T& getData() const { return _data; }
	void setData(const T& data) { _data = data; }
    
	// Display functions used by operator<<.
	// ***** Your group will define/implement the pre & post display functions
	// ***** at about lines 114 & 127 below...
	void inOrderDisplay(ostream&) const;
	void preOrderDisplay(ostream&) const;
	void postOrderDisplay(ostream&) const;
	void listify(list<T>&) const;
	// The insertion operator below uses in-order display.
	// ***** Change the implementation of this insertion operator
	// ***** in order to switch to pre- or post-order display
	friend ostream& operator<< (ostream& out, const BSTNode<T>& b)
		{ b.inOrderDisplay(out); return out; }
	
private:
	T _data;
    BSTNode<T>* _left;
    BSTNode<T>* _right;
	
	// private "helper" functions
    void addLeft(const T& data) { _left = new BSTNode(data); }
	void addRight(const T& data) { _right = new BSTNode(data); }
};


template<typename T>
BSTNode<T>::BSTNode(BSTNode& b) {
#ifdef debug
	cout << "BSTNode copy constructor called, _data == " << _data << endl;
#endif
	_data = b._data;
	_left = _right = nullptr;
	if (b._left != nullptr) _left = new BSTNode<T>(*b._left);
	if (b._right != nullptr) _right = new BSTNode<T>(*b._right);
}


template<typename T>
BSTNode<T>::~BSTNode() {
#ifdef debug
	cout << "BSTNode destructor called, _data == " << _data << endl;
#endif
    delete _left;
	delete _right;
}


template<typename T>
BSTNode<T>& BSTNode<T>::operator= (BSTNode& b) {
#ifdef debug
	cout << "BSTNode copy assignment operator: ";
#endif
	_data = b._data;
	_left = _right = nullptr;
	if (b._left != nullptr) _left = new BSTNode<T>(*b._left);
    if (b._right != nullptr) _right = new BSTNode<T>(*b._right);
	return *this;
}


template<typename T>
void BSTNode<T>::insert(const T& data) {
	// comment out the next line when you've completed this function!
	// cout << "BSTNode<T>::insert called with data == " << data << endl;
    // implement the insert function here
	/**
	 *  ***** Write me! *****
     * 
	 */
    // comapre if the new data smaller than the old data if it small insert it to the left node if it not insert ot the right node
    if (data < _data){
        // check the new node if the the left node is exist add to the next left if not create a new left node
        if (_left != nullptr){
            _left->insert(data);
        }else{
            _left = new BSTNode<T>(data);
        }
    }
    else if (data > _data){
        if (_right != nullptr){
            _right->insert(data);
        }else{
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


/**
 *  ***** Complete preOrderDisplay and postOrderDisplay below *****
 */
template<typename T>
void BSTNode<T>::preOrderDisplay(ostream& out) const {
	// comment out the next line when you've completed this function!
	// cout << "BSTNode<T>::preOrderDisplay called\n";
    out << _data;
	if (_left != nullptr){
        out << ", ";
        _left->preOrderDisplay(out);
    }
    if (_right != nullptr){
        out << ", ";
        _right->preOrderDisplay(out);
    }
	/**
	 *  ***** Write me! *****
	 */

}

template<typename T>
void BSTNode<T>::postOrderDisplay(ostream& out) const {
	// comment out the next line when you've completed this function!
	// cout << "BSTNode<T>::postOrderDisplay called\n";
	if (_left != nullptr){
        _left->postOrderDisplay(out);
        out << ", ";
    }
    if (_right != nullptr){
        _right->postOrderDisplay(out);
        out << ", ";
    }
    out << _data;

	/**
	 *  ***** Write me! *****
	 */

}
template<typename T>
void BSTNode<T>::listify(list<T>& other) const {
    if (_left != nullptr) {
        _left->listify(other);
    }
    other.push_back(_data);
    if (_right != nullptr) {
        _right->listify(other);
    }
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
	cout << endl;
	list<int> irootlist;
    iroot.listify(irootlist);
    cout << "Creating irootList via iroot.listify" << endl;
    cout << "irootList (forward iterator) == ";
    // forward iterator
    for (auto p = irootlist.begin(); p != irootlist.end(); ++p){
        cout << *p << " ";
    }
    cout <<endl;
    cout << "irootList (Reverse iterator) == ";
    // reverse iterator
    for (auto p = irootlist.rbegin(); p != irootlist.rend(); ++p){
        cout << *p << " ";
    }
    cout << endl;
    cout << "irootList (ranged for loop) == ";
    // range base loop
    for (auto &p: irootlist){
        cout << p << " ";
    }
    cout << endl << endl;
    cout << "Creating srootList via sroot.listify " << endl;
    list<string> srootlist;
    sroot.listify(srootlist);
    cout << "srootList (forward iterator) == ";
    for (auto p = srootlist.begin(); p != srootlist.end(); ++p){
        cout << *p << " ";
    }
    cout <<endl;
    cout << "srootList (Reverse iterator) == ";
    // reverse iterator
    for (auto p = srootlist.rbegin(); p != srootlist.rend(); ++p){
        cout << *p << " ";
    }
    cout << endl;
    cout << "srootList (ranged for loop) == ";
    // range base loop
    for (auto &p: srootlist){
        cout << p << " ";
    }
    cout << endl << endl;
    BSTNode<int> iroot4(1000);
    iroot4.insert(2000);
    iroot4.insert(3000);
    iroot4.insert(4000);
    iroot4.insert(5000);
    list<int> iroot4list;
    iroot4.listify(iroot4list);
    cout << "iroot4 == ";
    for (auto &p: iroot4list){
        cout << p << " ";
    }
    cout << endl << endl;
    cout << "Contents of map<string, list<int>> mi (using ranged for loops):" <<endl;
    unordered_map<string, list<int>> mi;
    mi.insert(make_pair("irootlist", irootlist));
    mi.insert(make_pair("iroot4list", iroot4list));
    for (auto &p: mi){
        cout << p.first << ": ";
        for (auto &x: p.second){
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;
    mi.clear();
    // map index operator
    cout << "Using Map Index operator: " << endl;
    mi["iroot4list"] = iroot4list;
    mi["irootlist"] = irootlist;
    for (auto &p: mi){
        cout << "mi" << "[" << p.first << "]" << ": ";
        for (auto &x: p.second){
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;
    
#ifdef debug	
	BSTNode<int> iroot2(iroot); // use copy constructor
	cout << "\nAfter copy constructor:\n";
	cout << "iroot2 == " << iroot2 << endl;
	
	BSTNode<int> iroot3;
	iroot3 = iroot2; // use copy assignment operator
	cout << "\nAfter copy assignment operator:\n";
	cout << "iroot3 == " << iroot3 << endl << endl;
#endif
	return 0;
}
