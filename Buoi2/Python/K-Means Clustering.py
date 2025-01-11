import random
import math

# Hàm tính khoảng cách Euclidean giữa hai điểm
def euclidean_distance(a, b):
    return math.sqrt(sum((x - y) ** 2 for x, y in zip(a, b)))

# Hàm K-Means Clustering
def k_means(data, k, T):
    n = len(data)
    d = len(data[0])

    # Khởi tạo centroids ngẫu nhiên
    centroids = random.sample(data, k)

    labels = [0] * n  # Khởi tạo nhãn cho các điểm dữ liệu

    for _ in range(T):
        changed = False

        # Gán cụm cho mỗi điểm dữ liệu
        for i in range(n):
            min_dist = euclidean_distance(data[i], centroids[0])
            label = 0
            for j in range(1, k):
                dist = euclidean_distance(data[i], centroids[j])
                if dist < min_dist:
                    min_dist = dist
                    label = j
            if labels[i] != label:
                labels[i] = label
                changed = True

        # Cập nhật centroids
        new_centroids = [[0] * d for _ in range(k)]
        counts = [0] * k

        for i in range(n):
            for j in range(d):
                new_centroids[labels[i]][j] += data[i][j]
            counts[labels[i]] += 1

        for j in range(k):
            if counts[j] != 0:
                for i in range(d):
                    new_centroids[j][i] /= counts[j]

        centroids = new_centroids

        if not changed:
            break

    return labels


# Ví dụ dữ liệu: 6 khách hàng với 2 đặc trưng
data = [
    [5.0, 2.0], [2.0, 9.0], [9.0, 1.0],
    [1.0, 5.0], [5.0, 6.0], [6.0, 3.0]
]
k = 2  # Số cụm
T = 100  # Số vòng lặp tối đa

# Gọi thuật toán K-Means
labels = k_means(data, k, T)

# In kết quả
for i, label in enumerate(labels):
    print(f"Dữ liệu {i + 1} thuộc cụm {label}")
