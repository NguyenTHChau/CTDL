#include <iostream>
#include <vector>
using namespace std;

// Hàm tìm trung vị của ba phần tử đầu, giữa và cuối
int median_of_three(vector<int>& arr, int low, int high) {
    int mid = low + (high - low) / 2;  // Tính chỉ số phần tử giữa
    if (arr[low] > arr[mid]) swap(arr[low], arr[mid]);  // Hoán đổi arr[low] và arr[mid]
    if (arr[low] > arr[high]) swap(arr[low], arr[high]);  // Hoán đổi arr[low] và arr[high]
    if (arr[mid] > arr[high]) swap(arr[mid], arr[high]);  // Hoán đổi arr[mid] và arr[high]
    return mid;  // Trả về chỉ số của phần tử giữa (pivot)
}

// Hàm Partition với Pivot là Median of Three
int partition_median(vector<int>& arr, int low, int high) {
    int median = median_of_three(arr, low, high);  // Tìm median
    swap(arr[median], arr[high]);  // Hoán đổi pivot vào vị trí cuối
    int pivot = arr[high];  // Lấy pivot
    int i = low - 1;  // Chỉ số của phần tử nhỏ hơn pivot
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);  // Hoán đổi arr[i] và arr[j]
        }
    }
    swap(arr[i + 1], arr[high]);  // Hoán đổi pivot vào vị trí đúng
    return i + 1;  // Trả về chỉ số của pivot
}

// Hàm Quick Sort sử dụng Median of Three
void quickSort_median(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partition_median(arr, low, high);  // Tìm vị trí pivot
        quickSort_median(arr, low, p - 1);  // Sắp xếp phần bên trái của pivot
        quickSort_median(arr, p + 1, high);  // Sắp xếp phần bên phải của pivot
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    quickSort_median(arr, 0, arr.size() - 1);  // Gọi hàm Quick Sort
    cout << "Kết quả Quick Sort với Median of Three: ";
    for (int x : arr) {
        cout << x << " ";  // In mảng đã sắp xếp
    }
    cout << endl;
    return 0;
}
