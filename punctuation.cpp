#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    set<string> punctuation = {";", ":", ","};
    string input;
    cout << "Enter line: ";
    getline(cin, input);

    for (char c : input) {
        string s(1, c);
        if (punctuation.count(s)) {
            cout << "Punctuation (1): " << s << endl;
            break;
        }
    }
    return 0;
}
