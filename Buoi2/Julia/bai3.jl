# Giả sử bạn có mô hình và dữ liệu đầu vào
epsilon = 1e-5  # Ngưỡng dừng sớm
params = rand(10)  # Khởi tạo tham số
learning_rate = 0.01

function compute_gradient(params)
    # Hàm tính toán gradient (ví dụ giả định)
    return 2 * params  # Giả sử hàm mất mát là (params - 1)^2
end

for epoch in 1:1000
    gradient = compute_gradient(params)

    # Kiểm tra điều kiện dừng sớm
    total_gradient = sum(gradient.^2)
    if total_gradient < epsilon
        println("Dừng sớm tại epoch $epoch")
        break
    end

    # Cập nhật tham số
    params .-= learning_rate * gradient
end
