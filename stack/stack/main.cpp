#include <iostream>
#include <stack>
#include <string>

using namespace std;


bool checkParentheses(const string& a) {
    stack<char> s;

    for (char c : a) {
        if (c == '(' || c == '[' || c == '{') {
            s.push(c);
        }
        else if (c == ')' || c == ']' || c == '}') {
            if (s.empty()) return false;

            char top = s.top();
            s.pop();

            if ((c == ')' && top != '(') ||
                (c == ']' && top != '[') ||
                (c == '}' && top != '{')) {
                return false;
            }
        }
    }

    return s.empty();
}

int main() {
    string a;
    getline(cin, a);
    if (checkParentheses(a)) {
        cout << 1;
    }
    else {
        cout << 0;
    }

    return 0;
}
