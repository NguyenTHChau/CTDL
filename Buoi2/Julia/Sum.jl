function sum_1_to_n(n)
    s = 0
    for i in 1:n
        s += i  # Cộng giá trị i vào tổng
    end
    return s
end

# Nhập giá trị từ người dùng
println("Nhap n: ")
n = parse(Int, readline())  # Đọc giá trị n từ bàn phím
result = sum_1_to_n(n)  # Gọi hàm tính tổng
println("Tong 1..n = ", result)  # In kết quả
