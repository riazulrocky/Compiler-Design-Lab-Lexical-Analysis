#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    string input;
    cout << "Enter line: ";
    getline(cin, input);

    vector<char> foundParenthesis;

    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];
        if (ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch == '[' || ch == ']') {
            foundParenthesis.push_back(ch);
        }
    }

    if (!foundParenthesis.empty()) {
        cout << "Parenthesis (" << foundParenthesis.size() << "): ";
        for (int i = 0; i < foundParenthesis.size(); i++) {
            cout << foundParenthesis[i] << (i == foundParenthesis.size() - 1 ? "" : ", ");
        }
        cout << endl;
    } else {
        cout << "No parenthesis found." << endl;
    }

    return 0;
}
