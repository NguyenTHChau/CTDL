#include <iostream>
#include <vector>
using namespace std;

int linear_search(const vector<int>& arr, int target) {
    for (size_t i = 0; i < arr.size(); i++) {  // Duyệt qua từng phần tử trong mảng
        if (arr[i] == target) {  // Nếu tìm thấy phần tử target
            return i;  // Trả về chỉ số của phần tử đó
        }
    }
    return -1;  // Nếu không tìm thấy, trả về -1
}

int main() {
    vector<int> arr = {4, 2, 5, 1, 3};
    cout << linear_search(arr, 5) << endl;  // Output: 2
    return 0;
}
