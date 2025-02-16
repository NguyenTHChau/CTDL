    #include <bits/stdc++.h>
    using namespace std;

    typedef vector<int> State; // Kiểu dữ liệu cho trạng thái bảng
    typedef pair<State, int> Node; // Cặp (trạng thái, số bước)

    State rotate_left(State state) {
        swap(state[0], state[3]); // a1 <-> b1
        swap(state[1], state[3]); // a2 <-> b1
        swap(state[1], state[4]); // a2 <-> b2
        return state;
    }

    State rotate_right(State state) {
        swap(state[1], state[4]); // a2 <-> b2
        swap(state[2], state[4]); // a3 <-> b2
        swap(state[2], state[5]); // a3 <-> b3
        return state;
    }

    int bfs(State start, State goal) {
        queue<Node> q;
        unordered_set<string> visited;

        auto state_to_string = [](const State &s) {
            string res;
            for (int num : s) res += to_string(num);
            return res;
        };

        q.push({start, 0});
        visited.insert(state_to_string(start));

        while (!q.empty()) {
            auto [current, steps] = q.front();
            q.pop();

            if (current == goal) return steps;

            State left = rotate_left(current);
            State right = rotate_right(current);

            if (visited.find(state_to_string(left)) == visited.end()) {
                q.push({left, steps + 1});
                visited.insert(state_to_string(left));
            }
            if (visited.find(state_to_string(right)) == visited.end()) {
                q.push({right, steps + 1});
                visited.insert(state_to_string(right));
            }
        }

        return -1; // Không thể xảy ra
    }

    int main() {
        int T;
        cin >> T;
        while (T--) {
            State start(6), goal(6);
            for (int &num : start) cin >> num;
            for (int &num : goal) cin >> num;
            cout << bfs(start, goal) << endl;
        }
        return 0;
    }
