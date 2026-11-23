#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cout << "Enter number of customers n: ";
    cin >> n;

    vector<double> t(n);
    cout << "Enter service times t_1, ..., t_n (in minutes): ";
    for (int i = 0; i < n; ++i) {
        cin >> t[i];
    }

    vector<double> c(n);
    double prevFinish = 0.0;
    int minServiceIdx = 0;
    int maxQueueIdx = 0;

    for (int i = 0; i < n; ++i) {
        double arrival = static_cast<double>(i); // 0, 1, 2, ...
        double startService = max(arrival, prevFinish);
        double finishService = startService + t[i];

        c[i] = finishService - arrival;
        prevFinish = finishService;

        if (t[i] < t[minServiceIdx]) {
            minServiceIdx = i;
        }
        if (c[i] > c[maxQueueIdx]) {
            maxQueueIdx = i;
        }
    }

    cout << "\nTime spent in queue (c_1, ..., c_n): ";
    for (int i = 0; i < n; ++i) {
        cout << c[i] << " ";
    }
    cout << "\nCustomer with minimum service time: #" << minServiceIdx + 1
         << " (" << t[minServiceIdx] << " min)\n";
    cout << "Customer who spent the most time in queue: #" << maxQueueIdx + 1
         << " (" << c[maxQueueIdx] << " min)\n";

    return 0;
}