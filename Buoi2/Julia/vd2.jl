function linear_search(arr, target)
    for (index, value) in enumerate(arr)  # Duyệt qua từng phần tử trong mảng
        if value == target  # Nếu tìm thấy phần tử target
            return index  # Trả về chỉ số của phần tử đó
        end
    end
    return -1  # Nếu không tìm thấy, trả về -1
end

arr = [4, 2, 5, 1, 3]
println(linear_search(arr, 5))  # Output: 3
