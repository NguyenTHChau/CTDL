using Random
using Statistics
using Printf

# Hàm tính khoảng cách Euclidean
function euclidean_distance(a, b)
    return sqrt(sum((a .- b).^2))
end

# Hàm K-Means
function k_means(data, k, T)
    n, d = size(data)
    centroids = data[rand(1:n, k), :]
    labels = zeros(Int, n)

    for _ in 1:T
        changed = false
        # Gán cụm cho mỗi điểm dữ liệu
        for i in 1:n
            distances = [euclidean_distance(data[i, :], centroids[j, :]) for j in 1:k]
            label = argmin(distances)
            if labels[i] != label
                labels[i] = label
                changed = true
            end
        end

        # Cập nhật centroids
        for j in 1:k
            centroids[j, :] = mean(data[labels .== j, :], dims=1)
        end

        if !changed
            break
        end
    end

    return labels
end

# Tạo dữ liệu ngẫu nhiên
Random.seed!(0)
n, k, d, T = 1000, 3, 2, 50
data = rand(n, d) * 10  # Dữ liệu giả lập cho d = 2

# Đo thời gian thực thi
start_time = time()

labels = k_means(data, k, T)

end_time = time()

elapsed_ms = (end_time - start_time) * 1000
@printf "Thời gian thực thi (ms): %.2f\n" elapsed_ms
