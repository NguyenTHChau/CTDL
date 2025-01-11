def find_first_element(arr, target): 
    for i in range(len(arr)):
        if arr[i] == target: 
            return i  # Trả về chỉ số khi tìm thấy target
    return -1  # Trả về -1 nếu không tìm thấy target

arr = [10, 20, 30, 40, 50]
print(find_first_element(arr, 10))  # Output: 0
