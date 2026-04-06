#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;
int main (){
    ofstream outfile;
    ifstream infile;
    outfile.open("input.txt");
    if (outfile.fail()){
        cout << "could not open the file";
        exit(1);
    }
    outfile.close();
    infile.open("input.txt");
    if (infile.fail())
    {
    cout << "could not open file for reading - exiting" << endl;
    exit(1);
    }


    return 0;
}
