function partition!(arr, low, high)
    pivot = arr[high]  # Chọn pivot là phần tử cuối
    i = low - 1        # Vị trí của phần tử nhỏ hơn pivot

    for j in low:(high - 1)
        if arr[j] <= pivot
            i += 1
            arr[i], arr[j] = arr[j], arr[i]  # Đổi chỗ phần tử nhỏ hơn pivot
        end
    end

    # Đưa pivot vào vị trí chính xác
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1
end

function quick_sort!(arr, low, high)
    if low < high  # Điều kiện dừng
        p = partition!(arr, low, high)  # Phân hoạch mảng
        quick_sort!(arr, low, p - 1)    # Sắp xếp phần bên trái
        quick_sort!(arr, p + 1, high)   # Sắp xếp phần bên phải
    end
end

# Chạy chương trình
arr = [5, 2, 9, 1, 5, 6]
quick_sort!(arr, 1, length(arr))  # Chỉ số 1-based trong Julia
println("Ket qua Quick Sort: ", arr)  # Output: [1, 2, 5, 5, 6, 9]
