#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

string decimal_to_binary(int n) {
    stack<int> stack;
    cout << "Chuyen doi so thap phan: " << n << " sang nhi phan." << endl;

    if (n == 0) {
        stack.push(0);
        cout << "Da them phan du '0' vao ngan xep." << endl;
    }

    while (n > 0) {
        int remainder = n % 2;
        stack.push(remainder);
        cout << "Chia " << n << " cho 2, phan du: " << remainder << " → Da them " << remainder << " vao ngan xep." << endl;
        n = n / 2;
        cout << "Thuong moi: " << n << endl;
    }

    string binary = "";
    cout << "Chuyen doi ngan xep thanh so nhi phan:" << endl;
    while (!stack.empty()) {
        binary += to_string(stack.top());
        cout << "Lay " << stack.top() << " tu ngan xep va noi vao ket qua." << endl;
        stack.pop();
    }

    return binary;
}

int main() {
    int number = 13;
    string binary = decimal_to_binary(number);
    cout << "So thap phan " << number << " chuyen sang nhi phan la " << binary << endl;  // Output: 1101
    return 0;
}
