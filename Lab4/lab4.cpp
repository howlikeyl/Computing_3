/*
Senghak Heng (debugging)
Daisy Takang, SethaSebastian Yem(focusing on class)
Lindsey Yobo (writing int main)
*/

#include <iostream>
#include <string>

using namespace std;
// ***** Add your Date class definition and driver program at the end of
// this file (at about line 115). *****

// The Month class provided below is a "helper" class for your Date class.
// Note that although both classes are defined in this single compilation
// unit (file), we are not nesting the Month class in the Date class or
// vice versa.

class Month {
	friend class Date;
	
	friend ostream& operator<< (ostream&, const Month);
	
    private:
        enum EMonth { Jan=1, Feb, Mar, Apr, May, Jun,
					  Jul, Aug, Sep, Oct, Nov, Dec };
        
        // default constructor
        Month() : _month(Jan) {}
        
        // value constructor
        Month(const int im) : _month( static_cast<EMonth>(im) ) {}
        
        // mutator functions
        void setMonth(const string m) { _month = StringToEMonth(m); }
		void setMonth(const int im) { _month = static_cast<EMonth>(im); }
		
		// Private helper member functions
        EMonth StringToEMonth(const string) const;
        int MonthToInt() const { return static_cast<int>(_month); }
		string MonthToString() const;
		string MonthToString2() const;

		// Private data member
	    EMonth _month;
};

// Definitions of helper member functions for class Month

Month::EMonth Month::StringToEMonth(const string m) const {
	if (m == "Jan") return Jan;
	else if (m == "Feb") return Feb;
	else if (m == "Mar") return Mar;
	else if (m == "Apr") return Apr;
	else if (m == "May") return May;
	else if (m == "Jun") return Jun;
	else if (m == "Jul") return Jul;
	else if (m == "Aug") return Aug;
	else if (m == "Sep") return Sep;
	else if (m == "Oct") return Oct;
	else if (m == "Nov") return Nov;
	else if (m == "Dec") return Dec;
	else {
		cerr << "Month::StringToMonth: Invalid input month \"" << m << "\"\n";
		exit(1);
	}
}

string Month::MonthToString() const {
	switch (_month) {
		case Jan: return "Jan";
		case Feb: return "Feb";
		case Mar: return "Mar";
		case Apr: return "Apr";
		case May: return "May";
		case Jun: return "Jun";
		case Jul: return "Jul";
		case Aug: return "Aug";
		case Sep: return "Sep";
		case Oct: return "Oct";
		case Nov: return "Nov";
		case Dec: return "Dec";
		default:
			cerr << "MonthToString: invalid input month \'" << _month
				 << "\'\n";
			exit(1);
	}
}

string Month::MonthToString2() const {
	switch (_month) {
		case Jan: return "January";
		case Feb: return "February";
		case Mar: return "March";
		case Apr: return "April";
		case May: return "May";
		case Jun: return "June";
		case Jul: return "July";
		case Aug: return "August";
		case Sep: return "September";
		case Oct: return "October";
		case Nov: return "November";
		case Dec: return "December";
		default:
			cerr << "MonthToString: invalid input month \'" << _month << "\'\n";
			exit(1);
	}
}

// Definition of friend function operator<<

ostream& operator<< (ostream& out, const Month m) {
	out << m.MonthToString2();
	return out;
}


// ***** Add your Date class definition and driver program below. *****
class Date{
    public:
    Date(){
        month.setMonth(1);  //default constructor
        day = 1;
        year = 2022;
    }
    Date(int m, int d, int y){  //constructor with two argument with int
        day = d;
		month = m;
		year = y;
    }
	Date(string m, int d, int y){	//constructor with two argument with int and string
		day = d;
		month.setMonth(m);
		year = y;
	}
	void setMonth(int m){  //setter method
		month.setMonth(m);
	}
	void outputDateAsInt(ostream& out){  //ouput function as int
		out << month.MonthToInt() << "/" << day << "/" << "/" << year << endl;
	}
	void outputDateAsString(ostream& out){  //output function as string 
		out << month.MonthToString() << " " << day << " " << " " << year << endl;
	}
	Date operator++(){  //urany operator ++
		year++;
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Date& date);  //operator insertion
    private:
	//data type
    Month month;
    int day;
    int year;
};
ostream& operator<<(ostream& out, const Date& d) {
    out << d.month << " " << d.day << ", " << d.year << endl;
    return out;
}
int main(){
	Date d1;
	Date d2(5,26,2022);
	Date d3("May", 30, 2022);
	cout << "With the following declarations: " << endl << "Date d1, d2(5, 26, 2022), d3(May, 30, 2022)" << endl << "...and using operator<< :" << endl;
	cout << "D1: " << d1;
	cout << "D2: "<< d2;
	cout << "D3: "<< d3;
	cout << "After d3.setMonth(4): " << endl;
	d3.setMonth(4);
	cout << "D3: "<< d3;
	cout << "With the following declaration: "<< endl << "Date d4(12, 31, 2022): " << endl;
	Date d4(12, 31, 2022);
	d4.outputDateAsInt(cout);
	d4.outputDateAsString(cout);
	cout << "D4++ = " << ++d4;
}