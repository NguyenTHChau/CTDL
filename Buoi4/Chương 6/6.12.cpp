#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> result;

// Hàm sinh số lộc phát
void generateLuckyNumbers(string current, int maxLength) {
    if (current.length() > maxLength) return;

    // Lưu số vào danh sách
    result.push_back(current);

    // Gọi đệ quy để tạo số lớn hơn
    generateLuckyNumbers(current + "6", maxLength);
    generateLuckyNumbers(current + "8", maxLength);
}

int main() {
    int T, N;
    cin >> T;

    while (T--) {
        cin >> N;
        result.clear();

        // Sinh số lộc phát từ 1 -> N chữ số
        generateLuckyNumbers("6", N);
        generateLuckyNumbers("8", N);

        // Sắp xếp giảm dần
        sort(result.rbegin(), result.rend());

        // In kết quả
        for (string num : result) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
