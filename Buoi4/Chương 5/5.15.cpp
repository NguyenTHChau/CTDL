#include <iostream>
#include <stack>
#include <vector>
using namespace std;

// Hàm tìm phần tử lớn hơn tiếp theo (Next Greater Element)
vector<int> findNextGreater(vector<int>& arr, int n) {
    vector<int> nge(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }
        if (!st.empty()) nge[i] = st.top();
        st.push(arr[i]);
    }
    return nge;
}

// Hàm tìm phần tử nhỏ hơn tiếp theo (Next Smaller Element)
vector<int> findNextSmaller(vector<int>& arr, int n) {
    vector<int> nse(n, -1);
    stack<int> st;

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && st.top() >= arr[i]) {
            st.pop();
        }
        if (!st.empty()) nse[i] = st.top();
        st.push(arr[i]);
    }
    return nse;
}

void solveTestCase(vector<int>& arr, int n) {
    vector<int> nge = findNextGreater(arr, n);
    vector<int> result(n, -1);

    for (int i = 0; i < n; i++) {
        if (nge[i] != -1) {
            // Tìm vị trí của NGE trong mảng
            for (int j = i + 1; j < n; j++) {
                if (arr[j] == nge[i]) {
                    vector<int> nse = findNextSmaller(arr, n);
                    result[i] = nse[j];
                    break;
                }
            }
        }
    }

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        solveTestCase(arr, n);
    }
    return 0;
}
