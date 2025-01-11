#include <iostream>
#include <vector>
using namespace std;

// Hàm Partition để phân chia mảng dựa trên pivot
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Chọn pivot là phần tử cuối
    int i = low - 1;  // Chỉ số nhỏ hơn pivot
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);  // Hoán đổi arr[i] và arr[j]
        }
    }
    swap(arr[i + 1], arr[high]);  // Hoán đổi pivot vào vị trí đúng
    return i + 1;
}

// Hàm Quick Sort đệ quy
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int p = partition(arr, low, high);  // Tìm vị trí pivot
        quickSort(arr, low, p - 1);  // Sắp xếp phần bên trái của pivot
        quickSort(arr, p + 1, high);  // Sắp xếp phần bên phải của pivot
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    quickSort(arr, 0, arr.size() - 1);
    cout << "Kết quả Quick Sort: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
