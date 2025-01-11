#include <iostream>
#include <vector>
using namespace std;

// Hàm Merge để hợp nhất hai nửa đã được sắp xếp
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[left + i];
    for (int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Hàm Merge Sort đệ quy
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // Tính chỉ số giữa
        mergeSort(arr, left, mid);  // Sắp xếp nửa bên trái
        mergeSort(arr, mid + 1, right);  // Sắp xếp nửa bên phải
        merge(arr, left, mid, right);  // Trộn hai nửa đã sắp xếp
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    mergeSort(arr, 0, arr.size() - 1);
    cout << "Kết quả Merge Sort: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
