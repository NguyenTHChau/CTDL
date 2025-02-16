#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Hàm trả về độ ưu tiên của toán tử
int precedence(char op) {
    if (op == '^') return 3; // Lũy thừa có độ ưu tiên cao nhất
    if (op == '*' || op == '/') return 2; // Nhân, chia
    if (op == '+' || op == '-') return 1; // Cộng, trừ
    return 0;
}

// Hàm chuyển đổi biểu thức trung tố sang hậu tố
string infixToPostfix(string exp) {
    stack<char> s;
    string postfix = "";

    for (char ch : exp) {
        if (isalnum(ch)) {
            postfix += ch; // Nếu là toán hạng, thêm vào kết quả
        } else if (ch == '(') {
            s.push(ch);
        } else if (ch == ')') {
            // Lấy toán tử ra khỏi stack cho đến khi gặp dấu '('
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Bỏ dấu '('
        } else { // Là toán tử
            while (!s.empty() && precedence(s.top()) >= precedence(ch) && ch != '^') {
                postfix += s.top();
                s.pop();
            }
            s.push(ch);
        }
    }

    // Lấy toán tử còn lại trong stack ra
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Loại bỏ ký tự xuống dòng

    while (T--) {
        string exp;
        cin >> exp;
        cout << infixToPostfix(exp) << endl;
    }

    return 0;
}
