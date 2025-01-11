# Hàm Merge để hợp nhất hai nửa đã được sắp xếp
function merge!(arr, left, mid, right)
    n1 = mid - left + 1
    n2 = right - mid
    L = arr[left:left + n1 - 1]  # Tạo mảng con L
    R = arr[mid + 1:mid + 1 + n2 - 1]  # Tạo mảng con R

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

    # Sao chép phần còn lại của L, nếu có
    while i <= n1
        arr[k] = L[i]
        i += 1
        k += 1
    end

    # Sao chép phần còn lại của R, nếu có
    while j <= n2
        arr[k] = R[j]
        j += 1
        k += 1
    end
end

# Hàm Merge Sort đệ quy
function merge_sort!(arr, left, right)
    if left < right
        mid = div(left + right, 2)  # Tính chỉ số giữa
        merge_sort!(arr, left, mid)  # Sắp xếp nửa bên trái
        merge_sort!(arr, mid + 1, right)  # Sắp xếp nửa bên phải
        merge!(arr, left, mid, right)  # Trộn hai nửa đã sắp xếp
    end
end

arr = [5, 2, 9, 1, 5, 6]
merge_sort!(arr, 1, length(arr))
println("Kết quả Merge Sort: ", arr)
