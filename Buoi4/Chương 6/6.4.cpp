#include <iostream>
#include <queue>
using namespace std;

typedef unsigned long long ull;

void findSmallestBDN(int N) {
    queue<ull> q;
    q.push(1);

    while (!q.empty()) {
        ull num = q.front();
        q.pop();

        if (num % N == 0) {
            cout << num << endl;
            return;
        }

        q.push(num * 10);      // Thêm số kết thúc bằng 0
        q.push(num * 10 + 1);  // Thêm số kết thúc bằng 1
    }
}

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        findSmallestBDN(N);
    }
    return 0;
}
