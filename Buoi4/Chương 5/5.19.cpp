#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void stockSpan(vector<int>& prices, int n) {
    vector<int> span(n, 1);
    stack<int> st;

    for (int i = 0; i < n; i++) {
        // Loại bỏ các phần tử nhỏ hơn hoặc bằng giá hiện tại
        while (!st.empty() && prices[st.top()] <= prices[i]) {
            st.pop();
        }

        // Nếu stack rỗng, nhịp chứng khoán = i+1 (tất cả ngày trước nó đều nhỏ hơn)
        if (st.empty()) {
            span[i] = i + 1;
        } else {
            span[i] = i - st.top();
        }

        // Đưa chỉ mục của ngày hiện tại vào stack
        st.push(i);
    }

    // In kết quả
    for (int i = 0; i < n; i++) {
        cout << span[i] << " ";
    }
    cout << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> prices(n);
        for (int i = 0; i < n; i++) {
            cin >> prices[i];
        }
        stockSpan(prices, n);
    }
    return 0;
}
