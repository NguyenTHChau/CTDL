#include <iostream>
using namespace std;

int main() {
    cout << "Nhap n: ";
    int n;
    cin >> n; // Nhập giá trị n từ người dùng

    int counter = 0; // Khởi tạo biến đếm
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            counter++; // Tăng biến đếm mỗi khi vòng lặp bên trong được thực hiện
        }
    }

    cout << "So buoc thuc hien = " << counter << endl; // In kết quả số lần thực hiện vòng lặp
    return 0;
}
