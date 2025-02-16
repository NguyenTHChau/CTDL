#include <iostream>
#include <queue>
#include <vector>
#include <unordered_set>
using namespace std;

const int MAX = 10000;
vector<bool> isPrime(MAX, true);

// Sàng Eratosthenes để tìm số nguyên tố 4 chữ số
void sieve() {
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i < MAX; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j < MAX; j += i) {
                isPrime[j] = false;
            }
        }
    }
}

// BFS tìm số bước biến đổi ít nhất từ S -> T
int bfs(int S, int T) {
    queue<pair<int, int>> q;
    unordered_set<int> visited;

    q.push({S, 0});
    visited.insert(S);

    while (!q.empty()) {
        int num = q.front().first;
        int step = q.front().second;
        q.pop();

        // Nếu tìm thấy số đích
        if (num == T) return step;

        string numStr = to_string(num);
        // Duyệt qua từng chữ số để tạo số mới
        for (int i = 0; i < 4; i++) {
            char original = numStr[i];
            for (char c = '0'; c <= '9'; c++) {
                if (c != original) {
                    numStr[i] = c;
                    int newNum = stoi(numStr);
                    if (newNum >= 1000 && isPrime[newNum] && visited.find(newNum) == visited.end()) {
                        q.push({newNum, step + 1});
                        visited.insert(newNum);
                    }
                }
            }
            numStr[i] = original;
        }
    }
    return -1; // Không tìm thấy đường đi
}

int main() {
    sieve();
    int T;
    cin >> T;
    while (T--) {
        int S, T;
        cin >> S >> T;
        cout << bfs(S, T) << endl;
    }
    return 0;
}
