#include <iostream>
#include <vector>
#include <stack>
#include <unordered_set>
#include <map>
#include <utility>
#include <algorithm>

using namespace std;

// Hàm lấy các vị trí lân cận (trên, dưới, trái, phải)
vector<pair<int, int>> get_neighbors(const vector<vector<int>>& grid, pair<int, int> position) {
    int x = position.first, y = position.second;
    vector<pair<int, int>> neighbors;
    vector<pair<int, int>> directions = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };  // Trên, Dưới, Trái, Phải

    for (auto& dir : directions) {
        int nx = x + dir.first, ny = y + dir.second;
        if (nx >= 0 && nx < grid.size() && ny >= 0 && ny < grid[0].size()) {
            if (grid[nx][ny] != 1) {  // 1 là chướng ngại vật
                neighbors.push_back({nx, ny});
            }
        }
    }
    return neighbors;
}

// Hàm DFS tìm đường đi từ start đến goal
vector<pair<int, int>> dfs(const vector<vector<int>>& grid, pair<int, int> start, pair<int, int> goal) {
    stack<pair<int, int>> s;
    s.push(start);
    unordered_set<string> visited;
    map<pair<int, int>, pair<int, int>> parent;

    while (!s.empty()) {
        pair<int, int> current = s.top();
        s.pop();

        if (current == goal) {
            break;
        }

        if (visited.find(to_string(current.first) + "," + to_string(current.second)) != visited.end()) {
            continue;
        }

        visited.insert(to_string(current.first) + "," + to_string(current.second));

        // Lấy các vị trí lân cận
        vector<pair<int, int>> neighbors = get_neighbors(grid, current);
        for (auto& neighbor : neighbors) {
            if (visited.find(to_string(neighbor.first) + "," + to_string(neighbor.second)) == visited.end()) {
                s.push(neighbor);
                parent[neighbor] = current;
            }
        }
    }

    // Kiểm tra đường đi
    vector<pair<int, int>> path;
    if (parent.find(goal) == parent.end() && start != goal) {
        cout << "Khong tim thay duong didi." << endl;
        return path;
    }

    // Xây dựng đường đi từ goal về start
    pair<int, int> current = goal;
    while (current != start) {
        path.push_back(current);
        current = parent[current];
    }
    path.push_back(start);
    reverse(path.begin(), path.end());

    return path;
}

int main() {
    vector<vector<int>> grid = {
        {0, 0, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 1, 0},
        {0, 1, 1, 1, 0},
        {0, 0, 0, 0, 0}
    };

    pair<int, int> start = {0, 0};
    pair<int, int> goal = {4, 4};
    vector<pair<int, int>> path = dfs(grid, start, goal);

    if (!path.empty()) {
        cout << "Duong di tim duocduoc:" << endl;
        for (auto& p : path) {
            // Sửa lỗi tại đây để in dấu phẩy và ngoặc đơn đúng cách
            cout << "(" << p.first << ", " << p.second << ") ";
        }
        cout << endl;
    } else {
        cout << "Khong tim thay duong didi." << endl;
    }

    return 0;
}
