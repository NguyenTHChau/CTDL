#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

// Hàm tính Linear Regression bằng Gradient Descent
pair<double, double> linear_regression_gd(const vector<double>& X, const vector<double>& y, double learning_rate = 0.01, int epochs = 1000) {
    int n = y.size();
    double w = 0.0;
    double b = 0.0;

    for (int epoch = 0; epoch < epochs; epoch++) {
        double loss = 0.0;
        double dw = 0.0;
        double db = 0.0;

        // Tính y_pred và gradient
        for (int i = 0; i < n; i++) {
            double y_pred = w * X[i] + b;
            loss += pow(y_pred - y[i], 2); // Tính loss (Mean Squared Error)
            dw += 2 * X[i] * (y_pred - y[i]);
            db += 2 * (y_pred - y[i]);
        }

        loss /= n;
        dw /= n;
        db /= n;

        // Cập nhật w và b
        w -= learning_rate * dw;
        b -= learning_rate * db;

        if ((epoch + 1) % 100 == 0) {
            cout << "Epoch " << epoch + 1 << ": Loss=" << loss << ", w=" << w << ", b=" << b << endl;
        }
    }

    return {w, b};
}

int main() {
    srand(time(0));

    // Tạo dữ liệu ngẫu nhiên
    vector<double> X(1000), y(1000);
    for (int i = 0; i < 1000; i++) {
        X[i] = 2 * (rand() / double(RAND_MAX));  // Random value for X
        y[i] = 4 + 3 * X[i] + (rand() / double(RAND_MAX)); // y = 4 + 3 * X + noise
    }

    // Bắt đầu đo thời gian
    clock_t start = clock();

    // Gọi thuật toán Linear Regression
    auto [w, b] = linear_regression_gd(X, y, 0.1, 1000);

    // Kết thúc đo thời gian
    clock_t end = clock();

    // Tính toán thời gian đã trôi qua (tính bằng mili giây)
    double elapsed_ms = (double)(end - start) / CLOCKS_PER_SEC * 1000;

    // In kết quả
    cout << "Kết quả: w=" << w << ", b=" << b << endl;
    cout << "Thời gian thực thi (ms): " << elapsed_ms << " ms" << endl;

    return 0;
}
