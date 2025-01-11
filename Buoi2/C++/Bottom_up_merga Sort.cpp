#include <iostream>
#include <vector>
#include <algorithm>  // Để sử dụng hàm min
using namespace std;

// Hàm Merge để trộn hai mảng con đã sắp xếp
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;  // Kích thước mảng con bên trái
    int n2 = right - mid;     // Kích thước mảng con bên phải
    vector<int> L(n1), R(n2);

    // Sao chép dữ liệu vào mảng con
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    // Trộn các phần tử trở lại vào mảng arr
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

    // Sao chép phần còn lại của L, nếu có
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Sao chép phần còn lại của R, nếu có
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Hàm Bottom-Up Merge Sort
void bottomUpMergeSort(vector<int>& arr) {
    int n = arr.size();
    for (int curr_size = 1; curr_size < n; curr_size = 2 * curr_size) {
        for (int left_start = 0; left_start < n - 1; left_start += 2 * curr_size) {
            int mid = min(left_start + curr_size - 1, n - 1);
            int right_end = min(left_start + 2 * curr_size - 1, n - 1);
            merge(arr, left_start, mid, right_end);  // Gọi hàm merge để trộn các mảng con
        }
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5, 6};
    bottomUpMergeSort(arr);  // Gọi hàm Bottom-Up Merge Sort
    cout << "Kết quả sau Bottom-Up Merge Sort: ";
    for (int x : arr) {
        cout << x << " ";  // In mảng đã sắp xếp
    }
    cout << endl;
    return 0;
}
