def binary_search(arr, target):
    left, right = 0, len(arr) - 1
    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1  
        else:
            right = mid - 1  
    return -1  # Nếu không tìm thấy phần tử

arr = list(range(1, 17))  # Mảng từ 1 đến 16
print(binary_search(arr, 10))  # Output: 9 (vì 10 có chỉ số 9 trong mảng)
