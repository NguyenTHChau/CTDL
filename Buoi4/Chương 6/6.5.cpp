            #include <iostream>
            #include <queue>
            #include <unordered_set>
            using namespace std;

            int findMinSteps(int S, int T) {
                if (S >= T) return S - T;  // Nếu S lớn hơn hoặc bằng T, chỉ cần trừ đi

                queue<pair<int, int>> q;
                unordered_set<int> visited;  // Đánh dấu số đã xét

                q.push({S, 0});
                visited.insert(S);

                while (!q.empty()) {
                    auto [curr, steps] = q.front();
                    q.pop();

                    if (curr == T) return steps;  // Tìm thấy T

                    // Thao tác (a): Giảm 1
                    if (curr - 1 > 0 && visited.find(curr - 1) == visited.end()) {
                        q.push({curr - 1, steps + 1});
                        visited.insert(curr - 1);
                    }

                    // Thao tác (b): Nhân 2 (giới hạn dưới 2*T để tránh vòng lặp)
                    if (curr * 2 <= 2 * T && visited.find(curr * 2) == visited.end()) {
                        q.push({curr * 2, steps + 1});
                        visited.insert(curr * 2);
                    }
                }

                return -1;  // Trường hợp không xảy ra
            }

            int main() {
                int T, S, T_target;
                cin >> T;
                while (T--) {
                    cin >> S >> T_target;
                    cout << findMinSteps(S, T_target) << endl;
                }
                return 0;
            }
