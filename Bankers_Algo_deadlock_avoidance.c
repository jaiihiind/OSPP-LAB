#include <stdio.h>

void bankersAlgorithm(int maxAllocation[][10], int need[][10], int available[], int allocation[][10], int processCount, int resourceCount) {
    int safeSequence[processCount];
    int work[resourceCount];
    int finished[processCount];

    for (int i = 0; i < resourceCount; i++) {
        work[i] = available[i];
    }

    for (int i = 0; i < processCount; i++) {
        finished[i] = 0;
    }

    int safeCount = 0;
    while (safeCount < processCount) {
        for (int i = 0; i < processCount; i++) {
            if (!finished[i] && checkSafe(need[i], work, resourceCount)) {
                safeSequence[safeCount++] = i;
                finished[i] = 1;

                for (int j = 0; j < resourceCount; j++) {
                    work[j] += allocation[i][j];
                }

                break;
            }
        }
    }

    if (safeCount == processCount) {
        printf("Safe sequence:");
        for (int i = 0; i < safeCount; i++) {
            printf(" P%d", safeSequence[i] + 1);
        }
    } else {
        printf("System is in an unsafe state.");
    }
}

int checkSafe(int need[][10], int work[], int resourceCount) {
    for (int i = 0; i < resourceCount; i++) {
        if (need[i] > work[i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int processCount = 3;
    int resourceCount = 3;

    int maxAllocation[][10] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2}
    };

    int need[][10] = {
        {3, 2, 2},
        {0, 0, 1},
        {2, 1, 1}
    };

    int available[] = {2, 2, 1};
    int allocation[][10] = {
        {4, 3, 1},
        {3, 2, 0},
        {7, 0, 1}
    };

    bankersAlgorithm(maxAllocation, need, available, allocation, processCount, resourceCount);

    return 0;
}
