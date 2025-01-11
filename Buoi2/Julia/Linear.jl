using Random
using Printf

# Hàm Linear Regression bằng Gradient Descent
function linear_regression_gd(X, y, learning_rate=0.01, epochs=1000)
    n = length(y)
    w = 0.0
    b = 0.0

    for epoch in 1:epochs
        loss = 0.0
        dw = 0.0
        db = 0.0

        # Tính y_pred và gradient
        for i in 1:n
            y_pred = w * X[i] + b
            loss += (y_pred - y[i])^2  # Tính loss (Mean Squared Error)
            dw += 2 * X[i] * (y_pred - y[i])
            db += 2 * (y_pred - y[i])
        end

        loss /= n
        dw /= n
        db /= n

        # Cập nhật w và b
        w -= learning_rate * dw
        b -= learning_rate * db

        if epoch % 100 == 0
            @printf "Epoch %d: Loss=%.4f, w=%.4f, b=%.4f\n" epoch loss w b
        end
    end

    return w, b
end

# Tạo dữ liệu ngẫu nhiên
Random.seed!(0)
X = 2 * rand(1000)
y = 4 .+ 3 .* X .+ randn(1000)  # y = 4 + 3 * X + noise

# Bắt đầu đo thời gian
start_time = time()

# Gọi thuật toán Linear Regression
w, b = linear_regression_gd(X, y, learning_rate=0.1, epochs=1000)

# Kết thúc đo thời gian
end_time = time()

# Tính toán thời gian đã trôi qua (tính bằng mili giây)
elapsed_ms = (end_time - start_time) * 1000

# In kết quả
@printf "Kết quả: w=%.4f, b=%.4f\n" w b
@printf "Thời gian thực thi (ms): %.2f ms\n" elapsed_ms
