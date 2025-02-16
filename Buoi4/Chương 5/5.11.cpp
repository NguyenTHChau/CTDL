#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Hàm tính giá trị biểu thức hậu tố
int evaluatePostfix(string exp) {
    stack<int> s;

    for (char ch : exp) {
        if (isdigit(ch)) {
            // Nếu là số, đẩy vào stack
            s.push(ch - '0');
        } else {
            // Nếu là toán tử, lấy 2 toán hạng từ stack
            if (s.size() < 2) return -1; // Kiểm tra lỗi

            int b = s.top(); s.pop();
            int a = s.top(); s.pop();
            int result = 0;

            // Thực hiện phép toán
            switch (ch) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': 
                    if (b == 0) return -1; // Tránh chia cho 0
                    result = a / b;
                    break;
                default: return -1; // Toán tử không hợp lệ
            }

            // Đẩy kết quả vào stack
            s.push(result);
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
        cout << evaluatePostfix(exp) << endl;
    }

    return 0;
}
