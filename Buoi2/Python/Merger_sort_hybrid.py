# Hàm Insertion Sort
def insertion_sort(arr, low, high):
    for i in range(low + 1, high + 1):  # Duyệt qua mảng từ low+1 đến high
        key = arr[i]
        j = i - 1
        while j >= low and arr[j] > key:  # Dịch các phần tử lớn hơn key
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key  # Đặt key vào vị trí đúng

# Hàm Merge để trộn hai mảng con đã sắp xếp
def merge(arr, left, mid, right):
    n1 = mid - left + 1  # Kích thước mảng con bên trái
    n2 = right - mid     # Kích thước mảng con bên phải
    L = arr[left:left + n1]
    R = arr[mid + 1:mid + 1 + n2]

    i = 0  # Chỉ số cho mảng L
    j = 0  # Chỉ số cho mảng R
    k = left  # Chỉ số cho mảng chính

    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    while i < n1:  # Sao chép phần còn lại của L vào mảng chính
        arr[k] = L[i]
        i += 1
        k += 1

    while j < n2:  # Sao chép phần còn lại của R vào mảng chính
        arr[k] = R[j]
        j += 1
        k += 1

# Hàm Merge Sort Hybrid (kết hợp Merge Sort và Insertion Sort)
def merge_sort_hybrid(arr, left, right):
    if right - left + 1 < 10:  # Nếu số phần tử trong mảng con nhỏ hơn 10, dùng Insertion Sort
        insertion_sort(arr, left, right)
    elif left < right:
        mid = (left + right) // 2
        merge_sort_hybrid(arr, left, mid)  # Sắp xếp nửa bên trái
        merge_sort_hybrid(arr, mid + 1, right)  # Sắp xếp nửa bên phải
        merge(arr, left, mid, right)  # Trộn hai mảng đã sắp xếp lại

# Kiểm tra với mảng ví dụ
if __name__ == "__main__":
    arr = [5, 2, 9, 1, 5, 6, 8, 7, 3, 4]
    merge_sort_hybrid(arr, 0, len(arr) - 1)
    print("Kết quả sau Merge Sort Hybrid:", arr)
