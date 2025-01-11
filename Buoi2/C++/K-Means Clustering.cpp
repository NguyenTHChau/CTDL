#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;

// Hàm tính khoảng cách Euclidean giữa hai điểm
double euclidean_distance(const vector<double>& a, const vector<double>& b) {
    double sum = 0.0;
    for (int i = 0; i < a.size(); i++)
        sum += pow(a[i] - b[i], 2);
    return sqrt(sum);
}

// Hàm K-Means Clustering
vector<int> k_means(const vector<vector<double>>& data, int k, int T) {
    int n = data.size();
    int d = data[0].size();

    vector<vector<double>> centroids(k, vector<double>(d, 0.0));
    vector<int> labels(n, 0);  // Khởi tạo nhãn cho các điểm dữ liệu

    // Khởi tạo centroids ngẫu nhiên
    srand(time(0));
    for (int i = 0; i < k; i++) {
        centroids[i] = data[rand() % n];
    }

    for (int iter = 0; iter < T; iter++) {
        bool changed = false;

        // Gán cụm cho mỗi điểm dữ liệu
        for (int i = 0; i < n; i++) {
            double min_dist = euclidean_distance(data[i], centroids[0]);
            int label = 0;
            for (int j = 1; j < k; j++) {
                double dist = euclidean_distance(data[i], centroids[j]);
                if (dist < min_dist) {
                    min_dist = dist;
                    label = j;
                }
            }
            if (labels[i] != label) {
                labels[i] = label;
                changed = true;
            }
        }

        // Cập nhật centroids
        vector<vector<double>> new_centroids(k, vector<double>(d, 0.0));
        vector<int> counts(k, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < d; j++) {
                new_centroids[labels[i]][j] += data[i][j];
            }
            counts[labels[i]]++;
        }

        // Tính lại giá trị của centroids
        for (int j = 0; j < k; j++) {
            if (counts[j] != 0) {
                for (int i = 0; i < d; i++) {
                    new_centroids[j][i] /= counts[j];
                }
            }
        }

        centroids = new_centroids;

        // Nếu không có sự thay đổi nào trong vòng lặp, dừng lại
        if (!changed) break;
    }

    return labels;
}

int main() {
    // Ví dụ dữ liệu: 6 khách hàng với 2 đặc trưng
    vector<vector<double>> data = {
        {5.0, 2.0}, {2.0, 9.0}, {9.0, 1.0},
        {1.0, 5.0}, {5.0, 6.0}, {6.0, 3.0}
    };

    int k = 2; // Số cụm
    int T = 100; // Số vòng lặp tối đa

    // Gọi thuật toán K-Means
    vector<int> labels = k_means(data, k, T);

    // In kết quả
    for (int i = 0; i < labels.size(); i++) {
        cout << "Dữ liệu " << i + 1 << " thuộc cụm " << labels[i] << endl;
    }

    return 0;
}
