#include <iostream>
#include <unordered_map>
#include <stack>
#include <vector>
using namespace std;

void solve(vector<int>& A, int n) {
    unordered_map<int, int> freq;
    vector<int> ans(n, -1);
    stack<int> st;

    // Bước 1: Đếm số lần xuất hiện của từng phần tử
    for (int num : A) {
        freq[num]++;
    }

    // Bước 2: Duyệt mảng từ phải sang trái
    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && freq[A[st.top()]] <= freq[A[i]]) {
            st.pop();
        }

        // Nếu stack không rỗng thì phần tử gần nhất có tần suất cao hơn là phần tử ở st.top()
        if (!st.empty()) {
            ans[i] = A[st.top()];
        }

        // Đưa chỉ mục của phần tử hiện tại vào stack
        st.push(i);
    }

    // In kết quả
    for (int num : ans) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> A(n);
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        solve(A, n);
    }
    return 0;
}
