#include<iostream>
#include<string>
#include<queue>
using namespace std;
// include queue.h or equivalent such as <queue>

//----------------------------------------------
// CS421 HW1 
// Write a generator in C++ for L = {x | x is any combination of a's and b's}.
// Your name: Jake Tremblay
//----------------------------------------------

// Copy the recognizer function here from the other file.

bool recognizer(string s) {
    if (s.empty()) return false;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] != 'a' && s[i] != 'b') return false;
    }

    return true;
}

void generate(string current, char E[], int len, int perm) {
    if (perm == 0) {
        if (recognizer(current)) {
            cout << current << endl;
            
        }
        return;
    }

    for (int i = 0; i < len; i++) {
        string currentPrefix = current + E[i];
        generate(currentPrefix, E, len, perm - 1);
    }

}

// main: It should create each string over E = {a,b,c} systematically
//   (short to long) and pass each string to the recognizer function
//   created in Part a).  Hint: use a queue to generate strings
//   Only those strings for which the recognizer returned TRUE
//   should be displayed. 
//   Keeps on going until the queue overflows but the user can 
//   terminate the program with control-C 
//   after about 20 strings have been displayed.


int main() {
    queue<string> generatedText;
    char E[] = { 'a', 'b', 'c' };
    int len = 3, perm = 1;
    string prefix = "", userInput;
    while (true) {
        // generate a string
        cout << "Enter any key to continue or -1 to exit." << endl;
        getline(cin, userInput);
        if (userInput == "-1") return 0;
        generate(prefix, E, len, perm++);
    }// end of while
    return 0;
}// end of main
