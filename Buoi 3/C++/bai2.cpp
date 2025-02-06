#include <iostream>
#include <deque>
#include <thread>
#include <mutex>
#include <random>
#include <chrono>

using namespace std;

class Sensor {
public:
    int id;
    class PrintQueue& print_queue;

    Sensor(int id, PrintQueue& pq) : id(id), print_queue(pq) {}

    void send_data() {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<> dis(1, 100);
        uniform_real_distribution<> sleep_dis(0.5, 2);

        while (true) {
            string data = "Du lieu tu cam bienbien" + to_string(id) + ": " + to_string(dis(gen));
            print_queue.enqueue(data);
            this_thread::sleep_for(chrono::milliseconds(int(sleep_dis(gen) * 1000)));
        }
    }
};

class PrintQueue {
public:
    deque<string> queue;
    mutex mtx;

    void enqueue(const string& data) {
        lock_guard<mutex> lock(mtx);
        queue.push_back(data);
        cout << "Da them vao hang doidoi: " << data << endl;
    }

    void process_queue() {
        while (true) {
            lock_guard<mutex> lock(mtx);
            if (!queue.empty()) {
                string data = queue.front();
                queue.pop_front();
                cout << "Dang xu lyly: " << data << endl;
            }
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
};

int main() {
    PrintQueue print_queue;

    // Khởi động thread xử lý hàng đợi
    thread processor(&PrintQueue::process_queue, &print_queue);

    // Tạo và khởi động các cảm biến
    vector<thread> sensor_threads;
    for (int i = 1; i <= 3; ++i) {
        Sensor sensor(i, print_queue);
        sensor_threads.push_back(thread(&Sensor::send_data, sensor));
    }

    // Đảm bảo các thread cảm biến và xử lý vẫn chạy
    for (auto& t : sensor_threads) {
        t.detach();
    }

    processor.join();  // Đảm bảo rằng thread xử lý hoàn tất

    return 0;
}
