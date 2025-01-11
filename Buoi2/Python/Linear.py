import numpy as np
import time

# Hàm Linear Regression bằng Gradient Descent
def linear_regression_gd(X, y, learning_rate=0.01, epochs=1000):
    n = len(y)
    w = 0.0
    b = 0.0

    for epoch in range(epochs):
        y_pred = w * X + b
        loss = np.mean((y_pred - y) ** 2)  # Tính loss (mean squared error)

        # Tính gradient
        dw = (2 / n) * np.dot(X, (y_pred - y))
        db = (2 / n) * np.sum(y_pred - y)

        # Cập nhật tham số w và b
        w -= learning_rate * dw
        b -= learning_rate * db

        # In thông tin mỗi 100 vòng lặp
        if (epoch + 1) % 100 == 0:
            print(f'Epoch {epoch + 1}: Loss={loss:.4f}, w={w:.4f}, b={b:.4f}')

    return w, b

if __name__ == "__main__":
    # Tạo dữ liệu ngẫu nhiên
    np.random.seed(0)
    X = 2 * np.random.rand(1000)  # Dữ liệu đầu vào
    y = 4 + 3 * X + np.random.randn(1000)  # Mô phỏng y = 4 + 3X + noise

    # Bắt đầu đo thời gian
    start = time.time()

    # Gọi thuật toán Linear Regression
    w, b = linear_regression_gd(X, y, learning_rate=0.1, epochs=1000)

    # Kết thúc đo thời gian
    end = time.time()

    # Tính toán thời gian đã trôi qua (tính bằng mili giây)
    elapsed_ms = (end - start) * 1000

    # In kết quả
    print(f'Kết quả: w={w:.4f}, b={b:.4f}')
    print(f'Thời gian thực thi (ms): {elapsed_ms:.2f} ms')
