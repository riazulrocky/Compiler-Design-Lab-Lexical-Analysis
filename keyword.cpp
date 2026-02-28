#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    string keywords[] = {"int", "float", "if", "else", "while", "for", "return", "char"};
    string s;
    cout << "Enter keyword: ";
    cin >> s;

    bool found = false;
    for (string k : keywords) {
        if (s == k) { found = true; break; }
    }

    if (found) cout << "Keyword (1): " << s << endl;
    else cout << "Not a keyword." << endl;
    return 0;
}
