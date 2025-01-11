# Hàm Insertion Sort
def insertion_sort(arr, low, high):
    for i in range(low + 1, high + 1):  # Duyệt qua mảng từ low+1 đến high
        key = arr[i]
        j = i - 1
        while j >= low and arr[j] > key:  # Dịch các phần tử lớn hơn key
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key  # Đặt key vào vị trí đúng

# Hàm Partition cho Quick Sort
def partition(arr, low, high):
    pivot = arr[high]  # Chọn pivot là phần tử cuối
    i = low - 1
    for j in range(low, high):
        if arr[j] <= pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]  # Hoán đổi arr[i] và arr[j]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]  # Hoán đổi pivot vào vị trí đúng
    return i + 1

# Hàm Quick Sort Hybrid (kết hợp Quick Sort và Insertion Sort)
def quick_sort_hybrid(arr, low, high):
    while low < high:
        if high - low + 1 < 10:  # Nếu số phần tử trong mảng con nhỏ hơn 10, dùng Insertion Sort
            insertion_sort(arr, low, high)
            break
        else:
            p = partition(arr, low, high)  # Chia mảng và tìm pivot
            # Sắp xếp phần bên trái và bên phải của pivot
            if p - low < high - p:
                quick_sort_hybrid(arr, low, p - 1)  # Sắp xếp phần bên trái
                low = p + 1  # Cập nhật low để sắp xếp phần bên phải
            else:
                quick_sort_hybrid(arr, p + 1, high)  # Sắp xếp phần bên phải
                high = p - 1  # Cập nhật high để sắp xếp phần bên trái

# Kiểm tra với mảng ví dụ
if __name__ == "__main__":
    arr = [5, 2, 9, 1, 5, 6, 8, 7, 3, 4]
    quick_sort_hybrid(arr, 0, len(arr) - 1)
    print("Kết quả sau Quick Sort Hybrid:", arr)
