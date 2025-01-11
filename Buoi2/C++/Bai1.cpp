#include <iostream>
#include <vector>
#include <ctime>
#include <cmath>
#include <cstdlib>

using namespace std;

double euclidean_distance(const vector<double>& a, const vector<double>& b) {
    double sum = 0.0;
    for (int i = 0; i < a.size(); i++) {
        sum += pow(a[i] - b[i], 2);
    }
    return sqrt(sum);
}

vector<int> k_means(const vector<vector<double>>& data, int k, int T) {
    int n = data.size();
    int d = data[0].size();
    vector<vector<double>> centroids(k, vector<double>(d, 0.0));
    vector<int> labels(n, 0);

    srand(time(0));

    // Khởi tạo centroids ngẫu nhiên
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
        for (int j = 0; j < k; j++) {
            if (counts[j] != 0) {
                for (int i = 0; i < d; i++) {
                    new_centroids[j][i] /= counts[j];
                }
            }
        }
        centroids = new_centroids;

        if (!changed) break;
    }

    return labels;
}

int main() {
    srand(time(0));
    int n = 1000, k = 3, d = 2, T = 50;

    // Tạo dữ liệu ngẫu nhiên
    vector<vector<double>> data(n, vector<double>(d));
    for (int i = 0; i < n; i++) {
        data[i][0] = rand() % 10 + 1;  // Dữ liệu giả lập cho d = 2
        data[i][1] = rand() % 10 + 1;
    }

    clock_t start = clock();

    vector<int> labels = k_means(data, k, T);

    clock_t end = clock();

    double elapsed_ms = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    cout << "Thời gian thực thi (ms): " << elapsed_ms << endl;

    return 0;
}
