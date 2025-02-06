#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Robot {
private:
    vector<int> position;  // [x, y]
    string direction;      // N, E, S, W
    stack<string> history; // Lịch sử các lệnh

public:
    Robot() : position({0, 0}), direction("N") {}

    void move_forward() {
        if (direction == "N") position[1]++;
        else if (direction == "E") position[0]++;
        else if (direction == "S") position[1]--;
        else if (direction == "W") position[0]--;
        history.push("forward");
        display_status("Đang tiến lên");
    }

    void move_backward() {
        if (direction == "N") position[1]--;
        else if (direction == "E") position[0]--;
        else if (direction == "S") position[1]++;
        else if (direction == "W") position[0]++;
        history.push("backward");
        display_status("Đang lùi lại");
    }

    void turn_left() {
        string dirs[] = {"N", "W", "S", "E"};
        int idx = (find(begin(dirs), end(dirs), direction) - begin(dirs) + 1) % 4;
        direction = dirs[idx];
        history.push("left");
        display_status("Đang quay trái");
    }

    void turn_right() {
        string dirs[] = {"N", "E", "S", "W"};
        int idx = (find(begin(dirs), end(dirs), direction) - begin(dirs) + 1) % 4;
        direction = dirs[idx];
        history.push("right");
        display_status("Đang quay phải");
    }

    void undo() {
        if (history.empty()) {
            cout << "Không có lệnh nào để hoàn tác." << endl;
            return;
        }

