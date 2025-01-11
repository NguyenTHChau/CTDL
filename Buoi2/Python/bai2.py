import numpy as np
import time

# Hàm Linear Regression bằng Gradient Descent
def linear_regression_gd(X, y, learning_rate=0.01, epochs=1000):
    w = 0.0
    b = 0.0
    n = len(X)

    for epoch in range(epochs):
        y_pred = w * X + b
        loss = np.mean((y_pred - y) ** 2)  # Tính loss

        # Tính gradient
        dw = (2 / n) * np.dot(X, (y_pred - y))
        db = (2 / n) * np.sum(y_pred - y)

        # Cập nhật tham số
        w -= learning_rate * dw
        b -= learning_rate * db

    return w, b

if __name__ == "__main__":
    n = 10000  # Thay đổi giá trị của n để thử với 10000, 100000, 1000000

    # Khởi tạo dữ liệu ngẫu nhiên
    X = np.random.rand(n) * 100  # Dữ liệu giả lập
    y = 4 + 3 * X + np.random.randn(n)  # Công thức y = 3X + 4 + noise

    # Đo thời gian thực thi
    start_time = time.time()

    w, b = linear_regression_gd(X, y, learning_rate=0.01, epochs=1000)

    end_time = time.time()

    elapsed_ms = (end_time - start_time) * 1000

    print(f"Kết quả: w = {w}, b = {b}")
    print(f"Thời gian thực thi (ms): {elapsed_ms:.2f}")
