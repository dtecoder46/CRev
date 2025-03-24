#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    /*
    Algorithm
    1. Declare all possible keywords in an array ✅
    2. Declare a string variable to house all the compiled C++ code ✅
    3. Read the .cipp file ✅
    4. If a file line contains the first keyword, add the matching C++ syntax to a string ✅
    5. Analyze the same line for every keyword ✅
    6. Repeat the process for each line ✅
    7. Write the compiled C++ code to a C++ file
    8. Run the C++ file
    */

    string keywords[5] = {"include", "using", "cout", "cin", "elif"};

    string code;

    string cppcode;

    ifstream cipp("main.cipp");

    while(getline(cipp, code)) {

        // cout << "\"" + code.substr(0,5) + "\"\n";

        if (code.substr(0,7) == keywords[0]) { // condition searches for any keywords in the cipp code
            cppcode += "#" + code + "\n"; // complied to matching c++ syntax
        }

        else if (code.substr(0,5) == keywords[1]) {
            cppcode += code.insert(5, " namespace") + "\n";
        }

        else if (code.substr(0,12) == "int main() {"){
            cppcode += code + "\n";
        }

        else if (code.substr(0, 8) == "} // end") {
            cppcode += code + "\n";
        }

        else if (code.substr(0,4) == keywords[2]) {
            cppcode += "\t" + code.insert(5, "<< ") + "\n";
        }

        else if (code.substr(0,3) == keywords[3]) {
            cppcode += "\t" + code.insert(4, ">> ") + "\n";
        }

        else if (code.substr(0,4) == keywords[4]) {
            cppcode += "\t" + code.insert(2, "se ") + "\n";
        }

        else {
            cppcode += "\t" + code + "\n";
        }
    }

    ofstream cpp("compiled.cpp");

    cpp << cppcode;
}