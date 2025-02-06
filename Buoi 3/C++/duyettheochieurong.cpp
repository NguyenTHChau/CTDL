#include <iostream>
#include <queue>
#include <unordered_set>
#include <vector>
#include <unordered_map>
using namespace std;

void bfs(const unordered_map<char, vector<char>>& graph, char start) {
    queue<char> q;  // Queue để lưu trữ các phần tử
    unordered_set<char> visited;  // Set để theo dõi các phần tử đã thăm

    q.push(start);  // Đưa phần tử khởi đầu vào hàng đợi

    while (!q.empty()) {
        char vertex = q.front();
        q.pop();

        if (visited.find(vertex) == visited.end()) {  // Nếu chưa thăm
            cout << vertex << " ";
            visited.insert(vertex);  // Đánh dấu là đã thăm

            // Thêm các nút kề chưa được thăm vào cuối hàng đợi
            cout << "Da them cac nut ke cua '" << vertex << "' vao hang doi: ";
            for (const auto& neighbor : graph.at(vertex)) {
                if (visited.find(neighbor) == visited.end()) {
                    q.push(neighbor);
                    cout << neighbor << " ";
                }
            }
            cout << endl;
        }
    }
    cout << endl;
}

int main() {
    // Định nghĩa đồ thị dưới dạng danh sách kề
    unordered_map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'D', 'E'}},
        {'C', {'F'}},
        {'D', {}},
        {'E', {'F'}},
        {'F', {}}
    };

    cout << "BFS tu nut A:" << endl;
    bfs(graph, 'A');  // Output: A B C D E F

    return 0;
}
