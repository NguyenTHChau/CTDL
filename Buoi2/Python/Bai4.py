import numpy as np

# Hàm tính toán dự đoán y = W.X + b
def predict(X, W, b):
    return np.dot(X, W) + b

# Hàm tính toán mất mát Mean Squared Error (MSE)
def compute_mse(X, y, W, b):
    predictions = predict(X, W, b)
    return np.mean((predictions - y) ** 2)

# Cập nhật các tham số W và b theo Gradient Descent
def gradient_descent(X, y, W, b, learning_rate, iterations):
    m = len(y)

    for _ in range(iterations):
        predictions = predict(X, W, b)
        errors = predictions - y

        # Tính gradient
        W_grad = (2/m) * np.dot(X.T, errors)
        b_grad = (2/m) * np.sum(errors)

        # Cập nhật W và b
        W -= learning_rate * W_grad
        b -= learning_rate * b_grad

        # In ra MSE sau mỗi 100 lần lặp
        if _ % 100 == 0:
            print(f"MSE at iteration {_}: {compute_mse(X, y, W, b)}")

# Dữ liệu mẫu: X (2 đặc trưng), y (kết quả)
X = np.array([[1, 2], [2, 3], [3, 4], [4, 5]])
y = np.array([5, 7, 9, 11])

W = np.zeros(X.shape[1])  # Khởi tạo trọng số W
b = 0  # Khởi tạo bias b

learning_rate = 0.01
iterations = 1000

gradient_descent(X, y, W, b, learning_rate, iterations)

print(f"Trọng số W: {W}")
print(f"Bias b: {b}")
