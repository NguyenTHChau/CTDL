#include <iostream>
#include <vector>
#include <cmath>

// Khai báo epsilon và các tham số
double epsilon = 1e-5;
std::vector<double> gradient;
std::vector<double> params;

// Hàm tính toán gradient (giả định)
std::vector<double> computeGradient(const std::vector<double>& params) {
    std::vector<double> grad(params.size());
    for (size_t i = 0; i < params.size(); ++i) {
        grad[i] = 2 * params[i];  // Giả sử hàm mất mát là (params - 1)^2
    }
    return grad;
}

// Hàm tính tổng bình phương gradient
double computeGradientNorm(const std::vector<double>& gradient) {
    double norm = 0.0;
    for (size_t i = 0; i < gradient.size(); ++i) {
        norm += gradient[i] * gradient[i];
    }
    return norm;
}

// Cập nhật tham số
void updateParameters() {
    // Tính toán gradient
    gradient = computeGradient(params);

    // Kiểm tra điều kiện dừng sớm
    double totalGradient = computeGradientNorm(gradient);
    if (totalGradient < epsilon) {
        std::cout << "Dừng sớm\n";
        return;
    }

    // Cập nhật tham số (gradient descent)
    for (size_t i = 0; i < params.size(); ++i) {
        params[i] -= 0.01 * gradient[i];
    }
}

int main() {
    // Khởi tạo tham số ngẫu nhiên
    params.resize(10, 1.0);  // Ví dụ: khởi tạo với 10 tham số có giá trị 1.0

    // Huấn luyện với dừng sớm
    for (int epoch = 0; epoch < 1000; ++epoch) {
        updateParameters();
    }

    return 0;
}
