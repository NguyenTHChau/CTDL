#include <iostream>
#include <deque>
#include <string>
#include <locale>

using namespace std;

class RequestQueue {
private:
    deque<string> queue;

public:
    // Thêm yêu cầu vào hàng đợi
    void add_request(const string& request) {
        queue.push_back(request);
        wcout << L"Đã thêm yêu cầu '" << request.c_str() << L"' vào hàng đợi." << endl;
    }

    // Xử lý yêu cầu từ hàng đợi
    void process_request() {
        if (!queue.empty()) {
            string request = queue.front();
            queue.pop_front();
            wcout << L"Đang xử lý yêu cầu: " << request.c_str() << endl;
        } else {
            wcout << L"Không có yêu cầu nào để xử lý." << endl;
        }
    }

    // Hiển thị hàng đợi
    void display_queue() {
        wcout << L"Hàng đợi yêu cầu: ";
        for (const auto& req : queue) {
            wcout << req.c_str() << L" ";
        }
        wcout << endl;
    }
};

int main() {
    // Thiết lập môi trường để in tiếng Việt có dấu
    setlocale(LC_ALL, "en_US.UTF-8");

    RequestQueue rq;

    rq.add_request("Yêu Cầu 1");
    rq.add_request("Yêu Cầu 2");
    rq.add_request("Yêu Cầu 3");

    rq.display_queue();  // Output: Yêu Cầu 1 Yêu Cầu 2 Yêu Cầu 3

    rq.process_request();
    rq.display_queue();  // Output: Yêu Cầu 2 Yêu Cầu 3

    rq.process_request();
    rq.display_queue();  // Output: Yêu Cầu 3

    rq.process_request();
    rq.display_queue();  // Output: Hàng đợi yêu cầu: 

    rq.process_request();  // Output: Không có yêu cầu nào để xử lý.

    return 0;
}
