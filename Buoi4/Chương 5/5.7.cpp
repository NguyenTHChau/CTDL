#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

// Hàm chuyển đổi biểu thức tiền tố sang trung tố
string prefixToInfix(string exp) {
    stack<string> s;
    int n = exp.size();

    // Duyệt từ phải sang trái
    for (int i = n - 1; i >= 0; i--) {
        char ch = exp[i];

        if (isalnum(ch)) {
            // Nếu là toán hạng, đẩy vào stack
            s.push(string(1, ch));
        } else { // Nếu là toán tử
            if (s.size() < 2) return "INVALID"; // Kiểm tra lỗi

            string op1 = s.top(); s.pop();
            string op2 = s.top(); s.pop();

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
        cout << prefixToInfix(exp) << endl;
    }

    return 0;
}
