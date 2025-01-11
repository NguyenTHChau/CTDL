    #include <iostream>
    using namespace std;

    int sum_1_to_n(int n) {
        int s = 0;
        for(int i = 1; i <= n; i++) {
            s += i;  // Cộng i vào s thay vì cộng 1
        }
        return s;
    }

    int main() {
        int n = 5;
        cout << "Tong 1..n = " << sum_1_to_n(n) << endl;  // Thêm dấu " để đóng chuỗi
        return 0;
    }
