#include <iostream>
#include <vector>
using namespace std;

// Hàm Selection Sort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        // Tìm chỉ số của phần tử nhỏ nhất trong [i..n-1]
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }
        // Hoán đổi nếu min_index khác i
        if (min_index != i) {
            swap(arr[i], arr[min_index]);
        }
    }
}

int main() {
    vector<int> arr = {5, 2, 9, 1, 5};
    selectionSort(arr);
    cout << "Ket qua sau Selection Sort: ";
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}
