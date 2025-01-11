#include <iostream>
#include <vector>
using namespace std;

// Hàm Insertion Sort
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Lấy phần tử cần chèn
        int j = i - 1; // Tìm vị trí chèn đúng

        // Di chuyển các phần tử lớn hơn key sang phải
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key; // Chèn key vào vị trí đúng
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5};
    insertionSort(arr);
    cout << "Ket qua sau Insertion Sort: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
