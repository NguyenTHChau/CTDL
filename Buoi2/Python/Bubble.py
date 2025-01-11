# Hàm Bubble Sort
def bubbleSort(arr):
    n = len(arr)
    for i in range(n - 1):
        swapped = False
        for j in range(n - 1 - i): # Điều chỉnh vòng lặp để tránh so sánh phần tử đã được sắp xếp
            if arr[j] > arr[j + 1]: # Hoán đổi
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        # Nếu không có hoán đổi nào, mảng đã được sắp xếp
        if not swapped:
            break

arr = [5, 2, 9, 1, 5]
bubbleSort(arr)
print("Ket qua sau Bubble Sort:", arr)
