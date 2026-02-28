#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int main() {
    set<string> arithmetic_ops = {"+", "-", "*", "/", "="};
    string input;
    vector<string> a_list;
    cout << "Enter line: ";
    getline(cin, input);

    for (char c : input) {
        string s(1, c);
        if (arithmetic_ops.count(s)) a_list.push_back(s);
    }

    if(!a_list.empty()) {
        cout << "Arithmetic Operator (" << a_list.size() << "): ";
        for(int i=0; i<a_list.size(); i++) cout << a_list[i] << (i==a_list.size()-1 ? "" : ", ");
        cout << endl;
    }
    return 0;
}
