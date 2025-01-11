def sum_1_to_n(n):
    s = 0
    for i in range(1, n + 1):
        s += i  # Cộng giá trị i vào tổng
    return s

# Nhập giá trị từ người dùng
n = int(input("Nhap n: "))
result = sum_1_to_n(n)  # Gọi hàm tính tổng
print(f"Tong 1..n = {result}")  # In kết quả
