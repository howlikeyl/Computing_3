#include <iostream>

using namespace std;

inline int sum(int a, int b) {
	return a + b;
}

class Money
{
public:
	//constructors
	//Money() { dollars = 0; cents = 0; };
	Money() :dollars(0), cents(0) {} //initializer C11;
	Money(int newDollars, int newCents) :dollars(newDollars), cents(newCents) {}
	Money(int newTotalCents) {
		dollars = newTotalCents / 100;
		cents = newTotalCents % 100;
	}

	//getters and setters
	int getDollars() const { return dollars; }
	int getCents() const { return cents; }
	void setDollars(int iDollars) { dollars = iDollars; };
	void setCents(int iCents) { cents = iCents; }
	//careful for singel digits
	void output() {
		cout << "$" << toCents() / 100.0 << endl;
		/*
		cout << "$" << dollars << ".";
		if (cents < 10)
			cout << "0";
		cout << cents << endl;*/
	}

	//operator
	bool operator!=(const Money& other) {
		return (toCents() != other.toCents());
	}

    // friends - get access to private data members
	friend const Money operator+(const Money& left, const Money& right);
	friend bool operator==(const Money& left, const Money& right);


private:
	int dollars;
	int cents;
	int toCents() const { return dollars * 100 + cents; }

};

const Money operator+(const Money& left, const Money& right);
bool operator==(const Money& left, const Money& right);

ostream& operator<<(ostream& outstream, const Money& m);
istream& operator>>(istream& instream,  Money& m);


int main(int argc, char* argv[])
{
	Money m1(5, 20);
	m1.output();

	Money m2(7, 85);

	Money m3;

	//m3 = addMoney(m1,m2);
	m3 = m1 + m2;

	m3.output();

	// valid, but does it make sense? 
	// avoid by making the return object const
	//(m3 + m1).setCents(27);


	if (m1==m2)
		cout << "equal" << endl;
	else
		cout << "not equal" << endl;

	if (m1 != m2)
		cout << "not equal" << endl;
	else
		cout << "equal" << endl;

	cout << m3 << " " << m2;

	cout << "please enter amount: ";

	cin >> m2;

	cout << " you entered " << m2;
	return 0;
}

const Money operator+(const Money& left, const Money& right)
{
	Money sum(left.toCents() + right.toCents());

	/*
	sum.setDollars(left.getDollars() + right.getDollars());
	sum.setCents(left.getCents() + right.getCents());

	if (sum.getCents() >= 100)
	{
		sum.setDollars(sum.getDollars() + sum.getCents() / 100);
		sum.setCents(sum.getCents() % 100);
	}
	*/

	return sum;
}

bool operator==(const Money& left, const Money& right)
{
	return (left.toCents() == right.toCents());
}

ostream& operator<<(ostream& outstream, const Money& m)
{
	//better: make it a friend also or make toCents public
	outstream << "$" << (m.getDollars() * 100 + m.getCents()) / 100.0;
	return outstream;
}

istream& operator>>(istream& instream,  Money& m)
{
	char c = 'A';
    instream >> c;
	if (c != '$')
		cout << "please enter a dollar sign";

	double d = 0.0;

	instream >> d;

	m.setDollars(static_cast<int>(d));

	m.setCents(static_cast<int>(d*100) % 100);

	return instream;
}