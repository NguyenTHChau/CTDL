using Statistics  # Thêm thư viện Statistics

# Hàm tính toán dự đoán y = W.X + b
function predict(X, W, b)
    return X * W .+ b
end

# Hàm tính toán mất mát Mean Squared Error (MSE)
function compute_mse(X, y, W, b)
    predictions = predict(X, W, b)
    return mean((predictions .- y) .^ 2)  # Sử dụng mean từ Statistics
end

# Cập nhật các tham số W và b theo Gradient Descent
function gradient_descent(X, y, W, b, learning_rate, iterations)
    m = length(y)

    for i = 1:iterations
        predictions = predict(X, W, b)
        errors = predictions .- y

        # Tính gradient
        W_grad = (2/m) * X' * errors
        b_grad = (2/m) * sum(errors)

        # Cập nhật W và b
        W .-= learning_rate * W_grad
        b -= learning_rate * b_grad

        # In ra MSE sau mỗi 100 lần lặp
        if i % 100 == 0
            println("MSE at iteration $i: ", compute_mse(X, y, W, b))
        end
    end
end

# Dữ liệu mẫu: X (2 đặc trưng), y (kết quả)
X = [1 2; 2 3; 3 4; 4 5]
y = [5, 7, 9, 11]

W = zeros(size(X, 2))  # Khởi tạo trọng số W
b = 0.0  # Khởi tạo bias b

learning_rate = 0.01
iterations = 1000

gradient_descent(X, y, W, b, learning_rate, iterations)

println("Trọng số W: ", W)
println("Bias b: ", b)
