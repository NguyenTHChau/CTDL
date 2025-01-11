# Hàm Merge
function merge!(arr, left, mid, right)
    n1 = mid - left + 1
    n2 = right - mid

    L = arr[left:mid]
    R = arr[mid+1:right]

    i, j, k = 1, 1, left
    while i <= n1 && j <= n2
        if L[i] <= R[j]
            arr[k] = L[i]
            i += 1
        else
            arr[k] = R[j]
            j += 1
        end
        k += 1
    end

    while i <= n1
        arr[k] = L[i]
        i += 1
        k += 1
    end

    while j <= n2
        arr[k] = R[j]
        j += 1
        k += 1
    end
end

# Hàm Merge Sort
function mergeSort!(arr, left, right)
    if left < right
        mid = div(left + right, 2)
        mergeSort!(arr, left, mid)
        mergeSort!(arr, mid + 1, right)
        merge!(arr, left, mid, right)
    end
end

# Main program
arr = [5, 2, 9, 1, 5, 6]

# Bắt đầu đo thời gian
start_time = time()

# Gọi thuật toán Merge Sort
mergeSort!(arr, 1, length(arr))

# Kết thúc đo thời gian
end_time = time()

# Tính toán thời gian đã trôi qua (tính bằng giây)
duration = (end_time - start_time) * 1000  # miligiây

# In kết quả
println("Kết quả Merge Sort: ", arr)
println("Thời gian thực thi (ms) = $duration")
