#include <iostream>
#include <stack>
#include <sstream>
#include <cctype>
#include <map>

using namespace std;

// Hàm kiểm tra độ ưu tiên của toán tử
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Hàm thực hiện phép toán giữa hai số nguyên
int applyOperation(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b; // Chia lấy phần nguyên
        default: return 0;
    }
}

// Hàm chuyển biểu thức trung tố sang hậu tố
string infixToPostfix(const string &infix) {
    stack<char> operators;
    string postfix;
    stringstream ss(infix);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            // Nếu là số, đưa vào hậu tố
            postfix += token + " ";
        } else if (token == "(") {
            operators.push('(');
        } else if (token == ")") {
            while (!operators.empty() && operators.top() != '(') {
                postfix += operators.top();
                postfix += " ";
                operators.pop();
            }
            operators.pop(); // Bỏ '(' khỏi stack
        } else { // Nếu là toán tử
            while (!operators.empty() && precedence(operators.top()) >= precedence(token[0])) {
                postfix += operators.top();
                postfix += " ";
                operators.pop();
            }
            operators.push(token[0]);
        }
    }

    // Đưa các toán tử còn lại vào hậu tố
    while (!operators.empty()) {
        postfix += operators.top();
        postfix += " ";
        operators.pop();
    }

    return postfix;
}

// Hàm tính toán giá trị biểu thức hậu tố
int evaluatePostfix(const string &postfix) {
    stack<int> values;
    stringstream ss(postfix);
    string token;

    while (ss >> token) {
        if (isdigit(token[0])) {
            values.push(stoi(token)); // Chuyển số sang int
        } else {
            int b = values.top(); values.pop();
            int a = values.top(); values.pop();
            values.push(applyOperation(a, b, token[0]));
        }
    }

    return values.top();
}

int main() {
    int T;
    cin >> T;
    cin.ignore(); // Bỏ ký tự xuống dòng

    while (T--) {
        string infix;
        getline(cin, infix); // Đọc cả dòng biểu thức

        string postfix = infixToPostfix(infix); // Chuyển sang hậu tố
        int result = evaluatePostfix(postfix);  // Tính toán giá trị hậu tố

        cout << result << endl;
    }

    return 0;
}
