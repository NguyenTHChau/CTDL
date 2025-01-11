#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

// Hàm Linear Regression bằng Gradient Descent
void linear_regression_gd(const vector<double>& X, const vector<double>& y, double& w, double& b, double learning_rate = 0.01, int epochs = 1000) {
    int n = X.size();
    w = 0.0;
    b = 0.0;

    for (int epoch = 0; epoch < epochs; epoch++) {
        // Tính giá trị dự đoán mà không cần lưu trữ loss
        double dw = 0.0;
        double db = 0.0;

        // Tính gradient
        for (int i = 0; i < n; i++) {
            dw += 2 * X[i] * (w * X[i] + b - y[i]);
            db += 2 * (w * X[i] + b - y[i]);
        }

        // Cập nhật tham số
        w -= learning_rate * dw / n;
        b -= learning_rate * db / n;
    }
}

int main() {
    int n = 10000; // Thay đổi giá trị của n để thử với 10000, 100000, 1000000
    vector<double> X(n);
    vector<double> y(n);

    // Khởi tạo dữ liệu ngẫu nhiên
    srand(time(0));
    for (int i = 0; i < n; i++) {
        X[i] = rand() % 100 + 1;  // Dữ liệu giả lập
        y[i] = 4 + 3 * X[i] + (rand() % 10);  // Công thức y = 3X + 4 + noise
    }

    double w, b;

    // Đo thời gian thực thi
    clock_t start = clock();

    linear_regression_gd(X, y, w, b, 0.01, 1000);

    clock_t end = clock();
    double elapsed_ms = (double)(end - start) / CLOCKS_PER_SEC * 1000;

    cout << "Kết quả: w = " << w << ", b = " << b << endl;
    cout << "Thời gian thực thi (ms): " << elapsed_ms << endl;

    return 0;
}
