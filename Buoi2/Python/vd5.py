def partition(arr, low, high):
    pivot = arr[high]  # Chọn pivot là phần tử cuối
    i = low - 1        # Vị trí của phần tử nhỏ hơn pivot

    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]  # Đổi chỗ các phần tử nhỏ hơn pivot

    # Đưa pivot vào vị trí chính xác
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1


def quick_sort(arr, low, high):
    if low < high:  # Điều kiện dừng
        p = partition(arr, low, high)  # Chia mảng thành hai phần
        quick_sort(arr, low, p - 1)    # Sắp xếp phần bên trái
        quick_sort(arr, p + 1, high)   # Sắp xếp phần bên phải


# Chạy chương trình
arr = [5, 2, 9, 1, 5, 6]
quick_sort(arr, 0, len(arr) - 1)
print("Ket qua Quick Sort:", arr)  # Output: [1, 2, 5, 5, 6, 9]
