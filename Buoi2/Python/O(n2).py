n = int(input("Nhap n: "))  # Nhập giá trị n từ người dùng

counter = 0  # Khởi tạo biến đếm
for i in range(n):
    for j in range(n):
        counter += 1  # Tăng biến đếm mỗi khi vòng lặp bên trong được thực hiện

print(f"So buoc thuc hien = {counter}")  # In kết quả số lần thực hiện vòng lặp
