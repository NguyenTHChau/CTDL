#include <iostream>
#include <queue>
using namespace std;

void findSmallestMultiple(int N) {
    queue<string> q;
    q.push("9");

    while (!q.empty()) {
        string s = q.front();
        q.pop();

        long long num = stoll(s);
        if (num % N == 0) {
            cout << num << endl;
            return;
        }

        q.push(s + "0");
        q.push(s + "9");
    }
}

int main() {
    int T, N;
    cin >> T;
    while (T--) {
        cin >> N;
        findSmallestMultiple(N);
    }
    return 0;
}
