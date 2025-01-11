#include <iostream>
#include <vector>
using namespace std;

int binary_search(const vector<int>& arr, int target) {
    int left = 0, right = arr.size() - 1;  // Chỉ số 0-based
    while (left <= right) {
        int mid = left + (right - left) / 2;  // Tính chỉ số giữa
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  // Nếu không tìm thấy
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    cout << binary_search(arr, 7) << endl;  // Output: 3
    return 0;
}
