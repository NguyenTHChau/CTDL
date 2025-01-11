def sum_1_to_n(n):
    s = 0  # 1 phép gán
    for i in range(1, n + 1):  # n lần lặp
        s += i  # 1 phép cộng và 1 phép gán mỗi lần lặp
    return s

n = 9
print("Tong 1..n =", sum_1_to_n(n))  # Output: 45
