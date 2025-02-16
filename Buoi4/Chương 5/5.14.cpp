#include <iostream>
#include <stack>
using namespace std;

void findMinimumNumber(string S) {
    stack<int> st;
    string result = "";
    int num = 1;

    for (int i = 0; i <= S.length(); i++) {
        st.push(num++);

        if (i == S.length() || S[i] == 'I') {
            while (!st.empty()) {
                result += to_string(st.top());
                st.pop();
            }
        }
    }

    cout << result << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        findMinimumNumber(S);
    }
    return 0;
}
