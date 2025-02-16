#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

// Hàm kiểm tra hai từ có khác nhau đúng 1 ký tự không
bool isAdjacent(const string &a, const string &b) {
    int diff = 0;
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) diff++;
        if (diff > 1) return false;
    }
    return diff == 1;
}

// BFS để tìm đường đi ngắn nhất từ s đến t
int shortestPath(string s, string t, vector<string> &S) {
    unordered_set<string> words(S.begin(), S.end()); // Tạo tập từ vựng
    if (words.find(t) == words.end()) return -1; // Nếu t không trong tập từ

    queue<pair<string, int>> q;
    q.push({s, 1}); // Bắt đầu từ s với độ dài đường đi = 1
    words.erase(s);

    while (!q.empty()) {
        auto [current, steps] = q.front();
        q.pop();

        if (current == t) return steps; // Nếu tìm thấy t, trả về số bước

        // Kiểm tra tất cả từ trong tập hợp xem có thể di chuyển được không
        vector<string> toRemove;
        for (const string &word : words) {
            if (isAdjacent(current, word)) {
                q.push({word, steps + 1});
                toRemove.push_back(word);
            }
        }
        // Xóa các từ đã được duyệt khỏi tập từ
        for (const string &word : toRemove) {
            words.erase(word);
        }
    }
    return -1; // Không tìm thấy đường đi
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        string s, t;
        cin >> n >> s >> t;

        vector<string> S(n);
        for (int i = 0; i < n; i++) {
            cin >> S[i];
        }

        cout << shortestPath(s, t, S) << endl;
    }
    return 0;
}
