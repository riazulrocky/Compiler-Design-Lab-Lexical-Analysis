#include <iostream>
#include <string>
#include <vector>
#include <regex>
#include <set>

using namespace std;

bool isKeyword(string str) {
    set<string> keywords = {"int", "float", "double", "char", "if", "else", "while", "for", "return", "void"};
    return keywords.count(str);
}

int main() {
    string input;
    cout << "Enter line: ";
    getline(cin, input);

    vector<string> identifiers;
    regex id_regex("[a-zA-Z][a-zA-Z0-9]*");

    auto words_begin = sregex_iterator(input.begin(), input.end(), id_regex);
    auto words_end = sregex_iterator();

    for (sregex_iterator i = words_begin; i != words_end; ++i) {
        smatch match = *i;
        string token = match.str();

        if (!isKeyword(token)) {
            identifiers.push_back(token);
        }
    }

    if (!identifiers.empty()) {
        cout << "Identifier (" << identifiers.size() << "): ";
        for (int i = 0; i < identifiers.size(); i++) {
            cout << identifiers[i] << (i == identifiers.size() - 1 ? "" : ", ");
        }
        cout << endl;
    } else {
        cout << "No identifiers found." << endl;
    }

    return 0;
}
