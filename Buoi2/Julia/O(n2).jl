n = parse(Int, readline(stdin, "Nhap n: "))  # Nhập giá trị n từ người dùng

counter = 0  # Khởi tạo biến đếm
for i in 1:n
    for j in 1:n
        counter += 1  # Tăng biến đếm mỗi khi vòng lặp bên trong được thực hiện
    end
end

println("So buoc thuc hien = ", counter)  # In kết quả số lần thực hiện vòng lặp
