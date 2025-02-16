#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Hàm chuyển đổi biểu thức hậu tố sang trung tố
string postfixToInfix(string exp) {
    stack<string> s;
    int n = exp.size();

    // Duyệt từ trái sang phải
    for (int i = 0; i < n; i++) {
        char ch = exp[i];

        if (isalnum(ch)) {
            // Nếu là toán hạng, đẩy vào stack
            s.push(string(1, ch));
        } else { // Nếu là toán tử
            if (s.size() < 2) return "INVALID"; // Kiểm tra lỗi

            string op2 = s.top(); s.pop();
            string op1 = s.top(); s.pop();

            // Tạo biểu thức trung tố có dấu ngoặc
            string newExp = "(" + op1 + ch + op2 + ")";
            s.push(newExp);
        }
    }

    return s.top();
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Bỏ ký tự xuống dòng

    while (T--) {
        string exp;
        cin >> exp;
        cout << postfixToInfix(exp) << endl;
    }

    return 0;
}
