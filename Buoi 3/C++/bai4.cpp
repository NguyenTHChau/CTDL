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
        string last_command = history.top();
        history.pop();
        cout << "Hoàn tác lệnh: " << last_command << endl;

        if (last_command == "forward") move_backward();
        else if (last_command == "backward") move_forward();
        else if (last_command == "left") turn_right();
        else if (last_command == "right") turn_left();
    }

    void display_status(string action = "") {
        if (!action.empty()) cout << action << ". ";
        cout << "Vị trí: [" << position[0] << ", " << position[1] << "], Hướng: " << direction << endl;
    }
};

// Minh họa
int main() {
    Robot robot;
    robot.move_forward();
    robot.turn_right();
    robot.move_forward();
    robot.turn_left();
    robot.move_backward();
    robot.display_status();

    cout << "\nThực hiện Undo:" << endl;
    robot.undo();
    robot.undo();
    robot.display_status();

    return 0;
}
