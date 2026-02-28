#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

bool isNumber(const string& s) {
    return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}

int main() {
    string input, token;
    cout << "Enter line: ";
    getline(cin, input);

    for(int i=0; i<input.length(); i++) {
        if(!isdigit(input[i])) input[i] = ' ';
    }

    stringstream ss(input);
    while (ss >> token) {
        if (isNumber(token)) {
            cout << "Constant (1): " << token << endl;
            break;
        }
    }
    return 0;
}
