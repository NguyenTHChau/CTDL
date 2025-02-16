#include <iostream>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

// Lưu kết quả để tránh trùng lặp
set<string> results;

// Lưu các cặp dấu ngoặc
vector<pair<int, int>> brackets;
string expression;

// Hàm sinh các tổ hợp xóa ngoặc hợp lệ
void generate(int index, vector<bool> &removed) {
    if (index == brackets.size()) {
        string result;
        for (int i = 0; i < expression.size(); i++) {
            bool skip = false;
            for (int j = 0; j < brackets.size(); j++) {
                if ((i == brackets[j].first || i == brackets[j].second) && removed[j]) {
                    skip = true;
                    break;
                }
            }
            if (!skip) result += expression[i];
        }
        if (result != expression) results.insert(result);
        return;
    }

    // Giữ lại cặp ngoặc này
    generate(index + 1, removed);

    // Loại bỏ cặp ngoặc này
    removed[index] = true;
    generate(index + 1, removed);
    removed[index] = false;
}

int main() {
    cin >> expression;

    stack<int> s;
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] == '(') {
            s.push(i);
        } else if (expression[i] == ')') {
            if (!s.empty()) {
                brackets.push_back({s.top(), i});
                s.pop();
            }
        }
    }

    vector<bool> removed(brackets.size(), false);
    generate(0, removed);

    // In kết quả theo thứ tự từ điển
    for (const string &res : results) {
        cout << res << endl;
    }

    return 0;
}
