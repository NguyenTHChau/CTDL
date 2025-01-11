using Random

# Hàm tính khoảng cách Euclidean giữa hai điểm
function euclidean_distance(a, b)
    return sqrt(sum((a[i] - b[i])^2 for i in 1:length(a)))
end

# Hàm K-Means Clustering
function k_means(data, k, T)
    n = length(data)
    d = length(data[1])

    # Khởi tạo centroids ngẫu nhiên
    centroids = data[rand(1:n, k)]

    labels = zeros(Int, n)  # Khởi tạo nhãn cho các điểm dữ liệu

    for _ in 1:T
        changed = false

        # Gán cụm cho mỗi điểm dữ liệu
        for i in 1:n
            min_dist = euclidean_distance(data[i], centroids[1, :])
            label = 1
            for j in 2:k
                dist = euclidean_distance(data[i], centroids[j, :])
                if dist < min_dist
                    min_dist = dist
                    label = j
                end
            end
            if labels[i] != label
                labels[i] = label
                changed = true
            end
        end

        # Cập nhật centroids
        new_centroids = zeros(Float64, k, d)
        counts = zeros(Int, k)

        for i in 1:n
            for j in 1:d
                new_centroids[labels[i], j] += data[i, j]
            end
            counts[labels[i]] += 1
        end

        for j in 1:k
            if counts[j] != 0
                for i in 1:d
                    new_centroids[j, i] /= counts[j]
                end
            end
        end

        centroids = new_centroids

        if !changed
            break
        end
    end

    return labels
end

# Ví dụ dữ liệu: 6 khách hàng với 2 đặc trưng
data = [
    5.0 2.0; 2.0 9.0; 9.0 1.0;
    1.0 5.0; 5.0 6.0; 6.0 3.0
]
k = 2  # Số cụm
T = 100  # Số vòng lặp tối đa

# Gọi thuật toán K-Means
labels = k_means(data, k, T)

# In kết quả
for i in 1:length(labels)
    println("Dữ liệu $i thuộc cụm $(labels[i])")
end
