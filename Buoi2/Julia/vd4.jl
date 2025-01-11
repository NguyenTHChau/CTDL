function merge!(arr, left, mid, right)
    # Tạo các mảng tạm
    n1 = mid - left + 1
    n2 = right - mid
    L = arr[left:mid]
    R = arr[mid + 1:right]

    # Gộp hai mảng tạm lại vào arr[left..right]
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

function merge_sort!(arr, left, right)
    if left < right
        mid = left + div(right - left, 2)

        # Sắp xếp đệ quy từng nửa
        merge_sort!(arr, left, mid)
        merge_sort!(arr, mid + 1, right)

        # Trộn hai nửa đã sắp xếp
        merge!(arr, left, mid, right)
    end
end

# Chạy chương trình
arr = [5, 2, 9, 1, 5, 6]
merge_sort!(arr, 1, length(arr))  # Chỉ số 1-based của Julia
println("Ket qua Merge Sort: ", arr)  # Output: [1, 2, 5, 5, 6, 9]
