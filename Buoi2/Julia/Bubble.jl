# Hàm Bubble Sort
function bubbleSort(arr)
    n = length(arr)
    for i in 1:n-1
        swapped = false
        for j in 1:n-1-i  # Điều chỉnh vòng lặp để tránh so sánh phần tử đã được sắp xếp
            if arr[j] > arr[j + 1]  # Hoán đổi
                temp = arr[j]
                arr[j] = arr[j + 1]
                arr[j + 1] = temp
                swapped = true
            end
        end
        # Nếu không có hoán đổi nào, mảng đã được sắp xếp
        if !swapped
            break
        end
    end
end

arr = [5, 2, 9, 1, 5]
bubbleSort(arr)
println("Ket qua sau Bubble Sort:", arr)
