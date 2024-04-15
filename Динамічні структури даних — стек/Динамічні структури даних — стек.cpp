#include <iostream>
#include <stack>
#include <string>
#include <Windows.h>
using namespace std;

bool checkBrackets(const string& str) {
    stack<char> bracketStack;
    const string openingBrackets = "([{";
    const string closingBrackets = ")]}";
    for (size_t i = 0; i < str.size(); ++i) {
        char ch = str[i];
        if (openingBrackets.find(ch) != string::npos) {
            bracketStack.push(ch);
        }
        else if (closingBrackets.find(ch) != string::npos) {
            if (bracketStack.empty()) {
                return false;
            }
            char top = bracketStack.top();
            bracketStack.pop();
            if ((ch == ')' && top != '(') || (ch == ']' && top != '[') || (ch == '}' && top != '{')) {
                return false;
            }
        }
    }
    return bracketStack.empty();
}
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    string input;
    cout << "Введіть рядок з дужками: ";
    getline(cin, input);
    if (checkBrackets(input)) {
        cout << "Дужки в рядку розташовані коректно." << endl;
    }
    else {
        cout << "Дужки в рядку розташовані некоректно." << endl;
    }
    return 0;
}
