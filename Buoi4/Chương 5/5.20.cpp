#include <iostream>
#include <stack>
using namespace std;

string decodeString(string s) {
    stack<int> countStack; // Lưu số lần lặp
    stack<string> strStack; // Lưu các chuỗi con trước '['
    string currStr = ""; // Chuỗi đang xử lý
    int num = 0; // Biến lưu số lần lặp

    for (char c : s) {
        if (isdigit(c)) { // Nếu là số
            num = num * 10 + (c - '0'); 
        } else if (c == '[') { // Nếu gặp '['
            countStack.push(num);
            strStack.push(currStr);
            num = 0;
            currStr = "";
        } else if (c == ']') { // Nếu gặp ']'
            int repeatTimes = countStack.top();
            countStack.pop();
            string prevStr = strStack.top();
            strStack.pop();

            // Lặp lại chuỗi hiện tại repeatTimes lần
            string repeated = "";
            for (int i = 0; i < repeatTimes; i++) {
                repeated += currStr;
            }

            // Ghép với chuỗi trước đó
            currStr = prevStr + repeated;
        } else { // Nếu là chữ cái
            currStr += c;
        }
    }

    return currStr;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << decodeString(s) << endl;
    }
    return 0;
}
