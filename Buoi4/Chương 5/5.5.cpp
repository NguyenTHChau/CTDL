#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Hàm chuẩn hóa biểu thức bằng cách loại bỏ dấu ngoặc dư thừa
string normalize(string expr) {
    stack<int> s;
    string result;

    for (char ch : expr) {
        if (islower(ch)) { // Nếu là toán hạng
            result += ch;
        } else if (ch == '(') {
            s.push(result.length()); // Lưu vị trí bắt đầu của nhóm
        } else if (ch == ')') {
            if (!s.empty()) {
                int start = s.top();
                s.pop();
                // Nếu toàn bộ phần trong ngoặc chỉ chứa một toán hạng, thì bỏ ngoặc
                if (start == result.length() - 1) {
                    result.erase(start, 1);
                }
            }
        }
    }
    return result;
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Bỏ ký tự xuống dòng sau khi nhập số bộ test

    while (T--) {
        string P1, P2;
        getline(cin, P1);
        getline(cin, P2);

        // So sánh hai biểu thức sau khi chuẩn hóa
        cout << (normalize(P1) == normalize(P2) ? "YES" : "NO") << endl;
    }

    return 0;
}
