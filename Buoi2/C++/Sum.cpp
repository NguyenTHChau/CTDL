#include <iostream>
using namespace std;

int sum_1_to_n(int n) {
    int s = 0;
    for (int i = 1; i <= n; i++) {
        s += i; // Cộng giá trị i vào tổng
    }
    return s;
}

int main() {
    cout << "Nhap n: ";
    int n;
    cin >> n; // Nhập giá trị n
    int result = sum_1_to_n(n); // Gọi hàm tính tổng
    cout << "Tong 1..n = " << result << endl; // In kết quả
    return 0;
}
