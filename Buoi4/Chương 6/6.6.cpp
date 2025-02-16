#include <iostream>
#include <queue>
#include <unordered_set>
#include <cmath>
using namespace std;

// Hàm tìm số bước ít nhất để biến N về 1
int minSteps(int N) {
    queue<pair<int, int>> q;
    unordered_set<int> visited; // Đánh dấu số đã xét

    q.push({N, 0});
    visited.insert(N);

    while (!q.empty()) {
        auto [curr, steps] = q.front();
        q.pop();

        if (curr == 1) return steps;  // Nếu đã đến 1, trả về số bước

        // Thao tác (a): Giảm N đi 1
        if (visited.find(curr - 1) == visited.end()) {
            q.push({curr - 1, steps + 1});
            visited.insert(curr - 1);
        }

        // Thao tác (b): Lấy max(u, v) nếu u * v = curr
        for (int i = 2; i * i <= curr; ++i) {
            if (curr % i == 0) { // Tìm u, v
                int u = i;
                int v = curr / i;
                int maxUV = max(u, v);
                if (visited.find(maxUV) == visited.end()) {
                    q.push({maxUV, steps + 1});
                    visited.insert(maxUV);
                }
            }
        }
    }

    return -1;  // Trường hợp không xảy ra
}

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        cout << minSteps(N) << endl;
    }
    return 0;
}
