/*
Author: Senghak Heng
Date: 03/26/2025
Purpose: The program will read the input from the file and caculate the avg
Sources of Help: <Please list any sources that you used
for help: tutors, web sites, lab assistants etc.>
Time Spent: 4hours
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
Date: 03/24/2025
Name: Senghak Heng
*/
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <sstream>
#include <iomanip>
#include <vector>
using namespace std;
int main(){
    ofstream outFile("MovieRating.txt"); // Open file for writing
    if (!outFile) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return 1;
    }
    // Writing data to the file
    outFile << "7\nHappy Feet\n";
    outFile << "4\nHappy Feet\n";
    outFile << "5\nPirates of the Caribbean\n";
    outFile << "3\nHappy Feet\n";
    outFile << "4\nPirates of the Caribbean\n";
    outFile << "4\nFlags of Our Fathers\n";
    outFile << "5\nGigli\n";
    outFile << "1\n";
    outFile.close();
    // reading file
    vector<string> movie;
    vector<double> integer;
    double number;
    ifstream infile;
    infile.open("MovieRating.txt");
    if(infile.is_open()){
        string word;
        while (getline(infile, word)){
            //convert string to integer and store in vector
            stringstream convert;
            convert << word;
            if (convert >> number){
                integer.push_back(number);
            }
            else{
                movie.push_back(word);
            }
        }
        infile.close();
    }
    else{
        cout << "File error" << endl;
    }
    // use multimap to store the same keyValue pair
    multimap<vector<string>, vector<double>myMap;
    myMap.insert({movie, integer});
    map<string, pair<double, double>> review;
    // iterate through loop
    for(auto &p: myMap){
        string word = p.first;
        double num = p.second;
        // insert the word to key
        review[word].first += 1; //iincrement the amount of review
        review[word].second += num; // adding rating
    }
    // print the result
    for (auto &p: review){
        double review = p.second.first;
        double avg = p.second.second/review;
        cout << p.first << ": " << review << " reviews, average of " << setprecision(2) << avg << "/5" << endl; 
    }
    return 0;
}