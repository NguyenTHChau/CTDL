# Hàm Merge để hợp nhất hai nửa đã được sắp xếp
def merge(arr, left, mid, right):
    n1 = mid - left + 1
    n2 = right - mid
    L = arr[left:left + n1]  # Tạo mảng con L từ left đến mid
    R = arr[mid + 1:mid + 1 + n2]  # Tạo mảng con R từ mid+1 đến right

    i, j = 0, 0
    k = left
    while i < n1 and j < n2:
        if L[i] <= R[j]:
            arr[k] = L[i]
            i += 1
        else:
            arr[k] = R[j]
            j += 1
        k += 1

    # Sao chép phần còn lại của L, nếu có
    while i < n1:
        arr[k] = L[i]
        i += 1
        k += 1

    # Sao chép phần còn lại của R, nếu có
    while j < n2:
        arr[k] = R[j]
        j += 1
        k += 1

# Hàm Merge Sort đệ quy
def merge_sort(arr, left, right):
    if left < right:
        mid = (left + right) // 2  # Tính chỉ số giữa
        merge_sort(arr, left, mid)  # Sắp xếp nửa bên trái
        merge_sort(arr, mid + 1, right)  # Sắp xếp nửa bên phải
        merge(arr, left, mid, right)  # Trộn hai nửa đã sắp xếp

if __name__ == "__main__":
    arr = [5, 2, 9, 1, 5, 6]
    merge_sort(arr, 0, len(arr) - 1)
    print("Kết quả Merge Sort:", arr)
