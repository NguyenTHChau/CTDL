#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Point {
    int x, y, steps;
};

int bfs(vector<vector<char>> &grid, int N, int a, int b, int c, int d) {
    queue<Point> q;
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    q.push({a, b, 0});
    visited[a][b] = true;

    while (!q.empty()) {
        Point curr = q.front();
        q.pop();

        // Nếu đã đến điểm đích
        if (curr.x == c && curr.y == d) return curr.steps;

        // Kiểm tra tất cả các ô có thể di chuyển cùng hàng
        for (int i = curr.y - 1; i >= 0 && grid[curr.x][i] != 'X'; i--) {
            if (!visited[curr.x][i]) {
                visited[curr.x][i] = true;
                q.push({curr.x, i, curr.steps + 1});
            }
        }
        for (int i = curr.y + 1; i < N && grid[curr.x][i] != 'X'; i++) {
            if (!visited[curr.x][i]) {
                visited[curr.x][i] = true;
                q.push({curr.x, i, curr.steps + 1});
            }
        }

        // Kiểm tra tất cả các ô có thể di chuyển cùng cột
        for (int i = curr.x - 1; i >= 0 && grid[i][curr.y] != 'X'; i--) {
            if (!visited[i][curr.y]) {
                visited[i][curr.y] = true;
                q.push({i, curr.y, curr.steps + 1});
            }
        }
        for (int i = curr.x + 1; i < N && grid[i][curr.y] != 'X'; i++) {
            if (!visited[i][curr.y]) {
                visited[i][curr.y] = true;
                q.push({i, curr.y, curr.steps + 1});
            }
        }
    }

    return -1; // Không tìm thấy đường đi (nếu có thể xảy ra)
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;
        vector<vector<char>> grid(N, vector<char>(N));

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                cin >> grid[i][j];
            }
        }

        int a, b, c, d;
        cin >> a >> b >> c >> d;

        cout << bfs(grid, N, a, b, c, d) << endl;
    }

    return 0;
}
