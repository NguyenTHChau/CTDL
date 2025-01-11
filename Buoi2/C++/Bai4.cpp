#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

// Hàm tính toán dự đoán y = W.X + b
double predict(const std::vector<double>& X, const std::vector<double>& W, double b) {
    double result = 0.0;
    for (size_t i = 0; i < X.size(); ++i) {
        result += W[i] * X[i];
    }
    return result + b;
}

// Hàm tính toán mất mát Mean Squared Error (MSE)
double computeMSE(const std::vector<std::vector<double>>& X, const std::vector<double>& y, const std::vector<double>& W, double b) {
    double mse = 0.0;
    size_t n = X.size();
    for (size_t i = 0; i < n; ++i) {
        double prediction = predict(X[i], W, b);
        mse += (prediction - y[i]) * (prediction - y[i]);
    }
    return mse / n;
}

// Cập nhật các tham số W và b theo Gradient Descent
void gradientDescent(std::vector<std::vector<double>>& X, std::vector<double>& y, std::vector<double>& W, double& b, double learning_rate, int iterations) {
    size_t n = X.size();
    size_t d = X[0].size();

    for (int iter = 0; iter < iterations; ++iter) {
        std::vector<double> W_grad(d, 0.0);
        double b_grad = 0.0;

        // Tính gradient
        for (size_t i = 0; i < n; ++i) {
            double prediction = predict(X[i], W, b);
            double error = prediction - y[i];

            for (size_t j = 0; j < d; ++j) {
                W_grad[j] += error * X[i][j];
            }
            b_grad += error;
        }

        // Cập nhật W và b
        for (size_t j = 0; j < d; ++j) {
            W[j] -= learning_rate * W_grad[j] / n;
        }
        b -= learning_rate * b_grad / n;

        // In ra MSE sau mỗi lần cập nhật
        if (iter % 100 == 0) {
            std::cout << "MSE at iteration " << iter << ": " << computeMSE(X, y, W, b) << std::endl;
        }
    }
}

int main() {
    // Dữ liệu mẫu: X (2 đặc trưng), y (kết quả)
    std::vector<std::vector<double>> X = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    std::vector<double> y = {5, 7, 9, 11};

    std::vector<double> W = {0.0, 0.0};  // Khởi tạo trọng số W
    double b = 0.0;  // Khởi tạo b

    double learning_rate = 0.01;
    int iterations = 1000;

    gradientDescent(X, y, W, b, learning_rate, iterations);

    // Kết quả
    std::cout << "Trọng số W: ";
    for (auto w : W) std::cout << w << " ";
    std::cout << "\nBias b: " << b << std::endl;

    return 0;
}
