# Hàm Insertion Sort
function insertion_sort(arr)
    n = length(arr)
    for i in 2:n
        key = arr[i]  # Lấy phần tử cần chèn
        j = i - 1  # Tìm vị trí chèn đúng

        # Di chuyển các phần tử lớn hơn key sang phải
        while j >= 1 && arr[j] > key
            arr[j + 1] = arr[j]
            j -= 1
        end
        arr[j + 1] = key  # Chèn key vào vị trí đúng
    end
end

arr = [5, 2, 9, 1, 5]
insertion_sort(arr)
println("Kết quả sau Insertion Sort:", arr)
