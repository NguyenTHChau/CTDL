# Hàm Insertion Sort
def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]  # Lấy phần tử cần chèn
        j = i - 1  # Tìm vị trí chèn đúng

        # Di chuyển các phần tử lớn hơn key sang phải
        while j >= 0 and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key  # Chèn key vào vị trí đúng

if __name__ == '__main__':
    arr = [5, 2, 9, 1, 5]
    insertion_sort(arr)
    print("Kết quả sau Insertion Sort:", arr)
