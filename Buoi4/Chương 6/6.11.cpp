#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int x, y, z, steps;
};

int BFS(vector<vector<vector<char>>> &grid, int A, int B, int C, Node start, Node end) {
    queue<Node> q;
    q.push(start);
    vector<vector<vector<bool>>> visited(A, vector<vector<bool>>(B, vector<bool>(C, false)));
    visited[start.x][start.y][start.z] = true;

    // 6 hướng đi: lên, xuống, trái, phải, trước, sau
    int dx[] = {1, -1, 0, 0, 0, 0};
    int dy[] = {0, 0, 1, -1, 0, 0};
    int dz[] = {0, 0, 0, 0, 1, -1};

    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        // Nếu tìm thấy điểm kết thúc
        if (curr.x == end.x && curr.y == end.y && curr.z == end.z) {
            return curr.steps;
        }

        // Kiểm tra 6 hướng di chuyển
        for (int i = 0; i < 6; i++) {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];
            int nz = curr.z + dz[i];

            if (nx >= 0 && nx < A && ny >= 0 && ny < B && nz >= 0 && nz < C 
                && !visited[nx][ny][nz] && grid[nx][ny][nz] != '#') {
                visited[nx][ny][nz] = true;
                q.push({nx, ny, nz, curr.steps + 1});
            }
        }
    }

    return -1; // Không tìm thấy đường đi
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int A, B, C;
        cin >> A >> B >> C;

        vector<vector<vector<char>>> grid(A, vector<vector<char>>(B, vector<char>(C)));
        Node start, end;

        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                for (int k = 0; k < C; k++) {
                    cin >> grid[i][j][k];
                    if (grid[i][j][k] == 'S') start = {i, j, k, 0};
                    if (grid[i][j][k] == 'E') end = {i, j, k, 0};
                }
            }
        }

        cout << BFS(grid, A, B, C, start, end) << endl;
    }

    return 0;
}
