/***********************************************
Author: Senghak Heng
Date: 02/09/2025
Purpose: The program will encode and decode the barcode and zipcode. 
Sources of Help:
w3School: https://www.w3schools.com/cpp/default.asp
geekforgeek: https://www.geeksforgeeks.org
stackoverflow: https://stackoverflow.com/questions
Time Spent: 6hours
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
Date: 02/09/2025
Name: Senghak Heng
*/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
// creating ZipCode class
class ZipCode{
    private:
    int zipCode;
    string barCode;
    // Function
    int BarCode_to_Digit(string BarCode);
    string Digit_to_BarCode(int ZipCode);
    public:
    // constructor
    ZipCode(int zipcode);
    ZipCode(string barcode);
    // function getter
    int getZipCode(void);
    string getBarCode(void);
};
int main(int argc, char* argv[]) {
	ZipCode zip(99504),
		zip2("100101010011100001100110001"),
		zip3(12345),
		zip4(67890);
	cout << zip.getZipCode() << "'s bar code is '"
		<< zip.getBarCode() << "'" << endl;
	cout << zip2.getZipCode() << "'s bar code is '"
		<< zip2.getBarCode() << "'" << endl;
	cout << zip3.getZipCode() << "'s bar code is '"
		<< zip3.getBarCode() << "'" << endl;
	cout << zip4.getZipCode() << "'s bar code is '"
		<< zip4.getBarCode() << "'" << endl;
	cout << endl;
	// Test a range of values by first constructing a zip code
	// with an integer, then retrieving the bar code and using
	// that to construct another ZipCode.
	int zip_int = 0;
	for (int i = 0; i < 25; i++)
	{
		// Make an aribrary 5-digit zip code integer, and use it
		// to construct a ZipCode
		int five_digit_zip = (zip_int * zip_int) % 100000;
		ZipCode z1(five_digit_zip);
		// Construct a second ZipCode from the first's bar code
		string z1_barcode = z1.getBarCode();
		ZipCode z2(z1_barcode);
		cout.width(3);
		cout << (i + 1) << ": ";
		cout.width(5);
		cout << z2.getZipCode() << " has code '"
			<< z1_barcode << "'";
		if ((z1_barcode == z2.getBarCode()) &&
			(z1.getZipCode() == z2.getZipCode()) &&
			(z2.getZipCode() == five_digit_zip))
		{
			cout << " [OK]" << endl;
		}
		else
		{
			cout << " [ERR]" << endl;
		}
		// Increment the test value arbitrarily
		zip_int += (233 + zip_int % 7);
	}
	cout << endl;
	// Test some error conditions. This test assumes that
	// ZipCode will simply set its value to a flag that indicates
	// an error, and will not exit the program.
	int BAD_ZIP_COUNT = 2;
	string bad_zips[][2] = {
	{ "100101010011100001100110000", "bad start/end character" },
	{ "100101010011100001100110021", "bad digit" },
	};
	for (int i = 0; i < BAD_ZIP_COUNT; i++)
	{
		cout << "Testing: " << bad_zips[i][1] << " " << bad_zips[i][0] <<
			endl;
		ZipCode test(bad_zips[i][0]);
		cout << endl;
	}
	cout << "Enter a character to quit." << endl;
	char c;
	cin >> c;
	return 0;
}
// function to input integer and return barcode as string
string ZipCode :: Digit_to_BarCode(int ZipCode){
    string barcode;
    int arrays[5];
    string store[5];
    int j = 0;
    // extracting each digit into an arrays
    for (int i = 4; i >= 0; --i ){
        // get the last digit of the number
        arrays[i] = ZipCode % 10;
        // deleting the last digit of the number 
        ZipCode /= 10;
    }
    // loop each value of the arrays starting from index 0 and store the value in arrays store
    for (int i = 0; i < 5; i++){
        switch(arrays[i]){
            case 0: store[i] = "11000"; break;
            case 1: store[i] = "00011"; break;
            case 2: store[i] = "00101"; break;
            case 3: store[i] = "00110"; break;
            case 4: store[i] = "01001"; break;
            case 5: store[i] = "01010"; break;
            case 6: store[i] = "01100"; break;
            case 7: store[i] = "10001"; break;
            case 8: store[i] = "10010"; break;
            case 9: store[i] = "10100"; break;
        }
    }
    // loop through the first 5 elements of the arrays
    for (int i = 0; i < 5; i++){
        // linking all the first 5 element of the arrays into a string barcode
        barcode += store[i];
    } 
    // add 1 to front and back of the barcode
    return barcode = "1" + barcode + "1";  
}
// function input barCode and return integer
int ZipCode :: BarCode_to_Digit(string BarCode){
    int zip = 0;
    int groupSize = 5;
    int multiply[] = {7, 4, 2, 1, 0};
    int temp = 0;
    // loop for extracting the number and increment by 5 each time
    for (int i = 1; i < 26; i += groupSize){
        int sum = 0;
        // code for extracting from a barcode at index i and length of groupSize(5)
        string barCodeGroup = BarCode.substr(i, groupSize);
        for (int j = 0; j < barCodeGroup.length(); j++){
            // object from class sstream
            stringstream convert;
            // inserting the arrays value into convert 
            convert << barCodeGroup[j];
            // extract the value from convert into temp variable int
            convert >> temp;
            // calculate the sum
            sum += multiply[j] * temp;
        }
        if (sum >= 11){
            sum = 0;
        }
            // to shift value to the left
        zip = zip * 10 + sum;
    }
    return zip;
}
// function for input barcode
ZipCode::ZipCode(string barcode) {
    // Check if the string length is 27, first and last characters are '1',
    if (barcode.length() != 27 || barcode[0] != '1' || barcode[barcode.length() - 1] != '1') {
            cout << "Wrong start/end character in the barcode!" << endl;
            return; // Early exit if the barcode is invalid
    }
    // check all characters are either '1' or '0'
    if (barcode.find_first_not_of("01") != string::npos){
        cout << "Wrong barcode! A barcode can only contain '0' and '1'." << endl;
        return;
    }
    barCode = barcode;
    // call function 
    zipCode = BarCode_to_Digit(barcode);
}
// Function for input zipcode
ZipCode::ZipCode(int zipcode){
    // handle invalid input for zipcode
    if (zipcode < 0 || zipcode > 99999){
        cout << "Invalid";
        return;
    }
    zipCode = zipcode;
    // call function
    barCode = Digit_to_BarCode(zipcode);
}
// getter method
int ZipCode::getZipCode(void){
    return zipCode;
}
string ZipCode::getBarCode(void){
    return barCode;
}