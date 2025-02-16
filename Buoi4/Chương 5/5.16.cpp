#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Hàm tìm chỉ số của cột nhỏ hơn tiếp theo bên trái (NSL)
vector<int> findNSL(vector<int>& heights, int n) {
    vector<int> nsl(n, -1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (!st.empty()) nsl[i] = st.top();
        st.push(i);
    }
    return nsl;
}

// Hàm tìm chỉ số của cột nhỏ hơn tiếp theo bên phải (NSR)
vector<int> findNSR(vector<int>& heights, int n) {
    vector<int> nsr(n, n);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }
        if (!st.empty()) nsr[i] = st.top();
        st.push(i);
    }
    return nsr;
}

// Hàm tính diện tích lớn nhất của hình chữ nhật
long long findLargestRectangle(vector<int>& heights, int n) {
    vector<int> nsl = findNSL(heights, n);
    vector<int> nsr = findNSR(heights, n);

    long long maxArea = 0;
    for (int i = 0; i < n; i++) {
        long long width = nsr[i] - nsl[i] - 1;
        long long area = heights[i] * width;
        maxArea = max(maxArea, area);
    }
    return maxArea;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<int> heights(N);
        for (int i = 0; i < N; i++) {
            cin >> heights[i];
        }
        cout << findLargestRectangle(heights, N) << endl;
    }
    return 0;
}
