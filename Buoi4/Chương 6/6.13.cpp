#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void generateLuckyNumbers(int N) {
    queue<string> q;
    vector<string> result;

    // Khởi tạo queue với các số có 1 chữ số
    q.push("6");
    q.push("8");

    while (!q.empty()) {
        string num = q.front();
        q.pop();

        // Nếu số vượt quá N chữ số thì dừng lại
        if (num.length() > N) break;

        result.push_back(num);

        // Thêm số mới bằng cách thêm "6" hoặc "8" vào cuối
        q.push(num + "6");
        q.push(num + "8");
    }

    // In kết quả
    cout << result.size() << endl;
    for (string num : result) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        generateLuckyNumbers(N);
    }
    return 0;
}
