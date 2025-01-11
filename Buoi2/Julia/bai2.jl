using Statistics  # Thêm dòng này để sử dụng hàm mean

# Hàm Linear Regression bằng Gradient Descent
function linear_regression_gd(X, y, learning_rate, epochs)
    w = 0.0
    b = 0.0
    n = length(X)

    for epoch in 1:epochs
        y_pred = w * X .+ b  # Sử dụng .+ để thực hiện phép cộng phần tử
        loss = mean((y_pred .- y) .^ 2)  # Tính loss

        # Tính gradient
        dw = (2 / n) * sum(X .* (y_pred .- y))  # Tính gradient dw
        db = (2 / n) * sum(y_pred .- y)  # Tính gradient db

        # Cập nhật tham số
        w -= learning_rate * dw
        b -= learning_rate * db

        # In loss mỗi 100 vòng
        if epoch % 100 == 0
            println("Epoch $epoch: Loss = $loss")
        end
    end

    return w, b
end

# Khởi tạo dữ liệu ngẫu nhiên
n = 10000  # Thay đổi giá trị của n để thử với 10000, 100000, 1000000
X = rand(n) * 100  # Dữ liệu giả lập
y = 4 .+ 3 .* X .+ randn(n)  # Công thức y = 3X + 4 + noise

# Đo thời gian thực thi
start_time = time()  # Hoặc sử dụng Dates.now() nếu bạn cần độ chính xác cao hơn

w, b = linear_regression_gd(X, y, 0.01, 1000)

end_time = time()  # Hoặc sử dụng Dates.now()

elapsed_ms = (end_time - start_time) * 1000

println("Kết quả: w = $w, b = $b")
println("Thời gian thực thi (ms): $elapsed_ms")
