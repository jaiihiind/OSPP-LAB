#include <stdio.h>

struct Process {
    int id;
    int burstTime;
};

void sjfSchedule(struct Process processes[], int n) {
    // Sort processes by burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (processes[j].burstTime > processes[j + 1].burstTime) {
                struct Process temp = processes[j];
                processes[j] = processes[j + 1];
                processes[j + 1] = temp;
            }
        }
    }

    // Print the scheduled order
    printf("SJF Process Schedule:\n");
    printf("Process\tBurst Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\n", processes[i].id, processes[i].burstTime);
    }
}

int main() {
    struct Process processes[10] = {
        {1, 6}, {2, 8}, {3, 3}, {4, 9}, {5, 2},
        {6, 5}, {7, 4}, {8, 7}, {9, 1}, {10, 10}
    };

    int n = sizeof(processes) / sizeof(processes[0]);

    sjfSchedule(processes, n);

    return 0;
}
