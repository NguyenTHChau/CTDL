#include <iostream>
#include <vector>
#include <chrono>  // Thư viện để đo thời gian

using namespace std;
using namespace std::chrono;

// Hàm Merge
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;  // Kích thước mảng con trái
    int n2 = right - mid;     // Kích thước mảng con phải

    // Tạo các mảng con tạm
    vector<int> L(n1), R(n2);

    // Sao chép các phần tử vào mảng tạm L và R
    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[mid + 1 + j];

    // Trộn hai mảng con đã sắp xếp vào mảng arr
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            ++i;
        } else {
            arr[k] = R[j];
            ++j;
        }
        ++k;
    }

    // Sao chép phần còn lại của L vào mảng arr nếu có
    while (i < n1) {
        arr[k] = L[i];
        ++i;
        ++k;
    }

    // Sao chép phần còn lại của R vào mảng arr nếu có
    while (j < n2) {
        arr[k] = R[j];
        ++j;
        ++k;
    }
}

// Hàm Merge Sort
void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Gọi đệ quy để sắp xếp hai nửa
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Trộn hai mảng con đã sắp xếp lại
        merge(arr, left, mid, right);
    }
}

int main() {
    // Tạo mảng ngẫu nhiên
    vector<int> arr = {5, 2, 9, 1, 5, 6};

    // Bắt đầu đo thời gian
    auto start = high_resolution_clock::now();

    // Gọi thuật toán Merge Sort
    mergeSort(arr, 0, arr.size() - 1);

    // Kết thúc đo thời gian
    auto end = high_resolution_clock::now();

    // Tính toán thời gian đã trôi qua (tính bằng miligiây)
    auto duration = duration_cast<milliseconds>(end - start).count();

    // In kết quả
    cout << "Kết quả Merge Sort: ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;

    // In thời gian thực thi
    cout << "Thời gian thực thi (ms) = " << duration << " ms" << endl;

    return 0;
}
