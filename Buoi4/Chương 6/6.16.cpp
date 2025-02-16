#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
    int x, y, step;
};

int bfs(vector<vector<int>> &A, int M, int N) {
    vector<vector<bool>> visited(M, vector<bool>(N, false));
    queue<Node> q;

    q.push({0, 0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        Node curr = q.front();
        q.pop();

        int x = curr.x, y = curr.y, step = curr.step;

        // Nếu đến đích
        if (x == M - 1 && y == N - 1) return step;

        int jump = A[x][y];

        // Nhảy sang phải
        if (y + jump < N && !visited[x][y + jump]) {
            q.push({x, y + jump, step + 1});
            visited[x][y + jump] = true;
        }

        // Nhảy xuống dưới
        if (x + jump < M && !visited[x + jump][y]) {
            q.push({x + jump, y, step + 1});
            visited[x + jump][y] = true;
        }
    }

    return -1; // Không tìm thấy đường đi
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int M, N;
        cin >> M >> N;
        vector<vector<int>> A(M, vector<int>(N));

        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                cin >> A[i][j];

        cout << bfs(A, M, N) << endl;
    }
    return 0;
}
