#include<iostream>
#include<string>
#include<queue>
using namespace std;

//----------------------------------------------
// CS421 HW1 
// Write a generator in C++ for L = {x | x is any combination of a's and b's}.
// Your name: Jake Tremblay
//----------------------------------------------

// Copy the recognizer function here from the other file.

bool recognizer(string s) {
    if (s.empty()) return false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] != 'a' && s[i] != 'b') return false;   //using demorgans here  a or b -> !a and !b
    }
    return true;
}

//generate() will recursively create a string using the elements of E
// each iteration of generate will produce all strings of size remLen
// that can be created from E, remLen increases at the users discresion

void generate(string current, char E[], int alphaSize, int remLen, queue<string> &gen) {
    if (remLen == 0) {              //base case is remLen is zero
        if (recognizer(current)) {  //once remLen is 0, check the current string with recognizer
            cout << current << endl;
            gen.push(current);      //only strings that pass validity check make it into queue
        }
        return;
    }

    for (int i = 0; i < alphaSize; i++) {   //for each element of E, build the prefix with E[i]
        string currentPrefix = current + E[i];
        generate(currentPrefix, E, alphaSize, remLen - 1, gen); //decrease the remLen because we used E[i], need to build with E[i+1] next
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
    char E[] = {'a', 'b', 'c'};
    int alphaSize = sizeof(E) / sizeof(E[0]), remLen = 1;
    string prefix = "", userInput;

    while (true) {
        cout << "Enter any key to continue or \"exit\" to exit." << endl;
        getline(cin, userInput);
        if (userInput == "exit") return 0;
        /*
        * Generate function takes following parameters:
        *-string prefix (string)
        *-alphabet E (char [])
        *-size of E (int)
        *-remaining length generated string (int)
        *-address of the queue (queue<string> &)
        */
        generate(prefix, E, alphaSize, remLen++, generatedText);
    }// end of while
    return 0;
}// end of main
