import numpy as np
import time

# Hàm tính khoảng cách Euclidean
def euclidean_distance(a, b):
    return np.sqrt(np.sum((a - b) ** 2))

# Hàm K-Means
def k_means(data, k, T):
    n, d = data.shape
    centroids = data[np.random.choice(n, k, replace=False)]
    labels = np.zeros(n)

    for _ in range(T):
        changed = False
        # Gán cụm cho mỗi điểm dữ liệu
        for i in range(n):
            distances = [euclidean_distance(data[i], centroid) for centroid in centroids]
            label = np.argmin(distances)
            if labels[i] != label:
                labels[i] = label
                changed = True

        # Cập nhật centroids
        new_centroids = np.array([data[labels == i].mean(axis=0) for i in range(k)])
        centroids = new_centroids

        if not changed:
            break

    return labels

if __name__ == '__main__':
    np.random.seed(0)
    n, k, d, T = 1000, 3, 2, 50

    # Tạo dữ liệu ngẫu nhiên
    data = np.random.rand(n, d) * 10  # Dữ liệu giả lập cho d = 2

    # Đo thời gian thực thi
    start = time.time()

    labels = k_means(data, k, T)

    end = time.time()

    elapsed_ms = (end - start) * 1000
    print(f"Thời gian thực thi (ms): {elapsed_ms:.2f}")
