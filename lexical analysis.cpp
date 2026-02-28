#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <regex>
#include <sstream>

using namespace std;

// Define sets for classification
set<string> keywords = {"int", "float", "double", "char", "if", "else", "while", "for", "return"};
set<string> arithmetic_ops = {"+", "-", "*", "/", "="};
set<string> logical_ops = {">", ">=", "<", "<=", "==", "!="};
set<string> punctuation = {";", ":", ","};
set<string> parentheses = {"(", ")", "{", "}", "[", "]"};

bool isNumber(const string& s) {
    return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}

bool isIdentifier(const string& s) {
    if (s.empty() || isdigit(s[0])) return false;
    for (char c : s) {
        if (!isalnum(c)) return false;
    }
    return true;
}

void analyze(string input) {
    // Add spaces around single-character tokens to make splitting easier
    string spaced = "";
    for (int i = 0; i < input.length(); i++) {
        string ch(1, input[i]);
        string next_ch = (i + 1 < input.length()) ? string(1, input[i+1]) : "";
        string op2 = ch + next_ch;

        if (logical_ops.count(op2)) { // Handle 2-char operators like >=
            spaced += " " + op2 + " ";
            i++;
        } else if (arithmetic_ops.count(ch) || punctuation.count(ch) ||
                   parentheses.count(ch) || logical_ops.count(ch)) {
            spaced += " " + ch + " ";
        } else {
            spaced += ch;
        }
    }

    stringstream ss(spaced);
    string token;

    // Categorized storage for output formatting
    vector<string> k_list, i_list, a_list, c_list, p_list;

    while (ss >> token) {
        if (keywords.count(token)) k_list.push_back(token);
        else if (arithmetic_ops.count(token)) a_list.push_back(token);
        else if (punctuation.count(token)) p_list.push_back(token);
        else if (isNumber(token)) c_list.push_back(token);
        else if (isIdentifier(token)) i_list.push_back(token);
    }

    // Display Results
    if(!k_list.empty()) cout << "Keyword (" << k_list.size() << "): " << k_list[0] << endl;
    if(!i_list.empty()) {
        cout << "Identifier (" << i_list.size() << "): ";
        for(int i=0; i<i_list.size(); i++) cout << i_list[i] << (i==i_list.size()-1 ? "" : ", ");
        cout << endl;
    }
    if(!a_list.empty()) {
        cout << "Arithmetic Operator (" << a_list.size() << "): ";
        for(int i=0; i<a_list.size(); i++) cout << a_list[i] << (i==a_list.size()-1 ? "" : ", ");
        cout << endl;
    }
    if(!c_list.empty()) cout << "Constant (" << c_list.size() << "): " << c_list[0] << endl;
    if(!p_list.empty()) cout << "Punctuation (1): " << p_list[0] << endl;
}

int main() {
    string input;
    cout << "Enter line: ";
    getline(cin, input);
    analyze(input);
    return 0;
}
