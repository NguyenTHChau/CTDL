#include <iostream>
#include <vector>
using namespace std;

// Hàm phân hoạch
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Chọn pivot là phần tử cuối
    int i = low - 1;       // Vị trí của phần tử nhỏ hơn pivot

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]); // Đổi chỗ phần tử nhỏ hơn pivot
        }
    }

    // Đưa pivot vào vị trí chính xác
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Hàm Quick Sort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) { // Điều kiện dừng
        int p = partition(arr, low, high); // Phân hoạch mảng
        quickSort(arr, low, p - 1);        // Sắp xếp phần bên trái
        quickSort(arr, p + 1, high);       // Sắp xếp phần bên phải
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};

    quickSort(arr, 0, arr.size() - 1);

    cout << "Ket qua Quick Sort: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    return 0;
}
