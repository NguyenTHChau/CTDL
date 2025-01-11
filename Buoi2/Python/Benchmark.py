import time

# Hàm Merge
def merge(arr, left, mid, right):
    n1 = mid - left + 1
    n2 = right - mid

    L = arr[left:mid + 1]
    R = arr[mid + 1:right + 1]

    i = j = 0
    k = left
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

# Hàm Merge Sort
def mergeSort(arr, left, right):
    if left < right:
        mid = (left + right) // 2
        mergeSort(arr, left, mid)
        mergeSort(arr, mid + 1, right)
        merge(arr, left, mid, right)

if __name__ == '__main__':
    arr = [5, 2, 9, 1, 5, 6]

    # Bắt đầu đo thời gian
    start_time = time.time()

    # Gọi thuật toán Merge Sort
    mergeSort(arr, 0, len(arr) - 1)

    # Kết thúc đo thời gian
    end_time = time.time()

    # Tính toán thời gian đã trôi qua (tính bằng giây)
    duration = (end_time - start_time) * 1000  # miligiây

    # In kết quả
    print("Kết quả Merge Sort:", arr)
    print(f"Thời gian thực thi (ms) = {duration:.2f} ms")
