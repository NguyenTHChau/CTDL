#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

void dfs(const unordered_map<string, vector<string>>& graph, const string& start) {
    stack<string> stack;
    set<string> visited;

    stack.push(start);

    while (!stack.empty()) {
        string vertex = stack.top();
        stack.pop();

        if (visited.find(vertex) == visited.end()) {
            cout << vertex << " ";
            visited.insert(vertex);

            // Thêm các nút kề vào ngăn xếp (đảo ngược để duyệt theo thứ tự)
            auto neighbors = graph.at(vertex);
            reverse(neighbors.begin(), neighbors.end());
            for (const auto& neighbor : neighbors) {
                stack.push(neighbor);
            }
            cout << "Da them cac nut ke cua '" << vertex << "' vao ngan xep: ";
            for (const auto& n : neighbors) {
                cout << n << " ";
            }
            cout << endl;
        }
    }
    cout << endl;
}

int main() {
    unordered_map<string, vector<string>> graph = {
        {"A", {"B", "C"}},
        {"B", {"D", "E"}},
        {"C", {"F"}},
        {"D", {}},
        {"E", {"F"}},
        {"F", {}}
    };

    cout << "DFS tu nut A:" << endl;
    dfs(graph, "A");  // Output: A C F B E D

    return 0;
}
