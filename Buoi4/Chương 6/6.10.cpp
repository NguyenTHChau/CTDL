#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Cell {
    int x, y, days;
};

int bfs(vector<vector<int>> &grid, int R, int C) {
    queue<Cell> q;
    int total_seeds = 0, sprouted_seeds = 0, days = 0;

    // Đưa tất cả cây non (2) vào hàng đợi
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (grid[i][j] == 2) {
                q.push({i, j, 0});
            }
            if (grid[i][j] == 1) {
                total_seeds++;  // Đếm tổng số hạt mầm
            }
        }
    }

    // BFS để lan truyền dinh dưỡng
    int dx[] = {-1, 1, 0, 0}; // Trái, phải, trên, dưới
    int dy[] = {0, 0, -1, 1};

    while (!q.empty()) {
        Cell curr = q.front();
        q.pop();
        days = curr.days;

        for (int k = 0; k < 4; k++) {
            int nx = curr.x + dx[k];
            int ny = curr.y + dy[k];

            // Kiểm tra hợp lệ
            if (nx >= 0 && nx < R && ny >= 0 && ny < C && grid[nx][ny] == 1) {
                grid[nx][ny] = 2; // Biến thành cây non
                q.push({nx, ny, curr.days + 1});
                sprouted_seeds++; // Đếm số hạt đã nảy mầm
            }
        }
    }

    // Nếu vẫn còn hạt mầm chưa nảy -> -1
    return (sprouted_seeds == total_seeds) ? days : -1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int R, C;
        cin >> R >> C;
        vector<vector<int>> grid(R, vector<int>(C));

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                cin >> grid[i][j];
            }
        }

        cout << bfs(grid, R, C) << endl;
    }

    return 0;
}
