#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool hasRedundantParentheses(const string &exp) {
    stack<char> s;

    for (char ch : exp) {
        if (ch == ')') {
            char top = s.top();
            s.pop();
            bool hasOperator = false;

            while (top != '(') {
                if (top == '+' || top == '-' || top == '*' || top == '/') {
                    hasOperator = true;
                }
                top = s.top();
                s.pop();
            }

            if (!hasOperator) {
                return true; // Dấu ngoặc dư thừa
            }
        } else {
            s.push(ch);
        }
    }

    return false; // Không có dấu ngoặc dư thừa
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Bỏ qua ký tự xuống dòng sau khi nhập số bộ test

    while (T--) {
        string expression;
        getline(cin, expression);
        cout << (hasRedundantParentheses(expression) ? "YES" : "NO") << endl;
    }

    return 0;
}
