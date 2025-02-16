#include <iostream>
#include <string>

using namespace std;

int minSwapsToBalance(string s) {
    int open = 0, close = 0;

    for (char ch : s) {
        if (ch == '(') {
            open++;
        } else {
            if (open > 0) {
                open--;
            } else {
                close++;
            }
        }
    }
    return (open + close) / 2;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        cout << minSwapsToBalance(S) << endl;
    }
    return 0;
}
