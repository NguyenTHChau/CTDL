#include <iostream>
#include <unordered_set>
using namespace std;

// Hàm kiểm tra số có thỏa mãn điều kiện không
bool isValid(int num) {
    unordered_set<int> digits;
    while (num > 0) {
        int d = num % 10;
        if (d > 5 || digits.count(d)) return false; // Chữ số lớn hơn 5 hoặc bị trùng
        digits.insert(d);
        num /= 10;
    }
    return true;
}

int countValidNumbers(int L, int R) {
    int count = 0;
    for (int num = L; num <= R; num++) {
        if (isValid(num)) count++;
    }
    return count;
}

int main() {
    int T, L, R;
    cin >> T;
    while (T--) {
        cin >> L >> R;
        cout << countValidNumbers(L, R) << endl;
    }
    return 0;
}
