#include <stdio.h>
#include <stdlib.h>

// Function to calculate total seek time for FCFS
int fcfs(int arr[], int head, int size) {
    int totalSeekOperations = 0;

    for (int i = 0; i < size; i++) {
        totalSeekOperations += abs(arr[i] - head);
        head = arr[i];
    }

    return totalSeekOperations;
}

int main() {
    int requests[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53;
    int size = sizeof(requests) / sizeof(requests[0]);

    printf("FCFS:\n");
    int fcfsSeekOperations = fcfs(requests, head, size);
    printf("Total number of seek operations: %d\n", fcfsSeekOperations);

    return 0;
}
