#include <iostream>
#include <queue>
using namespace std;

typedef unsigned long long ull;

void countBDN(ull N) {
    queue<ull> q;
    q.push(1);
    int count = 0;

    while (!q.empty()) {
        ull num = q.front();
        q.pop();

        if (num >= N) break;

        count++;
        q.push(num * 10);  // Thêm số kết thúc bằng 0
        q.push(num * 10 + 1);  // Thêm số kết thúc bằng 1
    }

    cout << count << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        ull N;
        cin >> N;
        countBDN(N);
    }
    return 0;
}
