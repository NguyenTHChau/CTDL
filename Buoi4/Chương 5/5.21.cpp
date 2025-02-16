#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int maxValidParentheses(string P) {
    int n = P.length();
    vector<int> dp(n, 0);
    stack<int> st;
    int totalLength = 0;

    for (int i = 0; i < n; i++) {
        if (P[i] == '(') {
            st.push(i);
        } else {
            if (!st.empty()) {
                int openIndex = st.top();
                st.pop();
                dp[i] = i - openIndex + 1;
                if (openIndex > 0) {
                    dp[i] += dp[openIndex - 1];
                }
                totalLength += dp[i];
            }
        }
    }

    return totalLength;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string P;
        cin >> P;
        cout << maxValidParentheses(P) << endl;
    }
    return 0;
}
