#include <iostream>
#include <iomanip>
#include <regex>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    ifstream inFile;
    
    inFile.open("a2_input.txt");
    if (!inFile) {
        cout << "Unable to open file";
        return 0;
    }

    cout << "Starting C++ Program Type to Check RegEx\n" << endl;

    regex re("^$(*)*(\\d{0,2}(,\\d{3})*|0).\\d\\d");

    string line;
    while (getline(inFile, line)){
        if(regex_match(line, re)){
            cout << line << endl;
        }
    }

    inFile.close();
    return 0;
}