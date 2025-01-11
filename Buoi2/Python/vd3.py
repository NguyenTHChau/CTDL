def binary_search(arr, target):
    left, right = 0, len(arr) - 1  # Python dùng chỉ số 0-based
    while left <= right:
        mid = (left + right) // 2  # Tính chỉ số giữa
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1
    return -1  # Nếu không tìm thấy

arr = [1, 3, 5, 7, 9, 11]
print(binary_search(arr, 7))  # Output: 3
