#include <bits/stdc++.h>

using namespace std;

struct Process {
    int id;
    int burstTime;
};


void sjfSchedule(vector<Process> &p) {
    sort(p.begin(), p.end(), [](const Process &a, const Process &b) {
        return a.burstTime < b.burstTime;
    });

    cout << "SJF Process Schedule:\n";
    cout << "Process\tBurst Time\n";
    for (const auto &process : p) {
        cout << process.id << "\t" << process.burstTime << "\n";
    }
}

int main() {
    vector<Process> p = {
        {1, 6}, {2, 8}, {3, 3}, {4, 9}, {5, 2},
        {6, 5}, {7, 4}, {8, 7}, {9, 1}, {10, 10}
    };

    sjfSchedule(p);

    return 0;
}
