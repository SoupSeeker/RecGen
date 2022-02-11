#include<iostream>
#include<string>
using namespace std;

//-------------------------------------------------------
// CS421 HW1 
// Write a recognizer in C++ for L = {x | x is any coombination of a's and b's}.
// Your name: Jake Tremblay
//-------------------------------------------------------

//  The recognizer function should return TRUE or FALSE 
//  checking each character
//  to make sure it is a or b.
bool recognizer(string s) {
    if (s.empty()) return false;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != 'a' && s[i] != 'b') return false;
    }

    return true;
}
// end of recognizer

//main: Given a string (from E) cined from the user, pass it to
//      the recognizer function.
//      Cout "YES IN L" or "NO NOT IN L" depending on what was returned.
int main() {
    string current;

    while (getline(cin, current)) {
        if (recognizer(current)) {
            cout << "YES IN L" << endl;
        }
        else {
            cout << "NO NOT IN L" << endl;
        }
    }
    // feel free to put it in a loop 
    return 0;
}// end of main
