#include <stdio.h>
#include <stdlib.h>

// Function to calculate total seek time for SCAN
int scan(int arr[], int head, int size) {
    int totalSeekOperations = 0;

    // Assuming head starts at the beginning
    int start = 0;
    int end = size - 1;

    // Move the head towards the end
    for (int i = start; i <= end; i++) {
        totalSeekOperations += abs(arr[i] - head);
        head = arr[i];
    }

    // Move the head towards the beginning
    for (int i = end; i >= start; i--) {
        totalSeekOperations += abs(arr[i] - head);
        head = arr[i];
    }

    return totalSeekOperations;
}

int main() {
    int requests[] = {98, 183, 37, 122, 14, 124, 65, 67};
    int head = 53;
    int size = sizeof(requests) / sizeof(requests[0]);

    printf("SCAN:\n");
    int scanSeekOperations = scan(requests, head, size);
    printf("Total number of seek operations: %d\n", scanSeekOperations);

    return 0;
}
