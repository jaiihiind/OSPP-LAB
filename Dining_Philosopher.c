#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define NUM_PHILOSOPHERS 5

pthread_mutex_t chopstick[NUM_PHILOSOPHERS];
pthread_t philosophers[NUM_PHILOSOPHERS];

void *philosopher(void *arg) {
    int id = *(int *)arg;
    int left_chopstick = id;
    int right_chopstick = (id + 1) % NUM_PHILOSOPHERS;

    while (1) {
        printf("Philosopher %d is thinking.\n", id);
        usleep(1000000);  // Simulating thinking

        pthread_mutex_lock(&chopstick[left_chopstick]);
        printf("Philosopher %d picked up left chopstick %d.\n", id, left_chopstick);
        pthread_mutex_lock(&chopstick[right_chopstick]);
        printf("Philosopher %d picked up right chopstick %d. Eating...\n", id, right_chopstick);
        usleep(1000000);  // Simulating eating

        pthread_mutex_unlock(&chopstick[left_chopstick]);
        printf("Philosopher %d put down left chopstick %d.\n", id, left_chopstick);
        pthread_mutex_unlock(&chopstick[right_chopstick]);
        printf("Philosopher %d put down right chopstick %d.\n", id, right_chopstick);
    }
}

int main() {
    int philosopher_ids[NUM_PHILOSOPHERS];

    // Initialize mutexes for chopsticks
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_init(&chopstick[i], NULL);
    }

    // Create philosopher threads
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        philosopher_ids[i] = i;
        pthread_create(&philosophers[i], NULL, philosopher, &philosopher_ids[i]);
    }

    // Wait for philosopher threads to finish (this won't happen in this example)
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_join(philosophers[i], NULL);
    }

    // Destroy mutexes
    for (int i = 0; i < NUM_PHILOSOPHERS; i++) {
        pthread_mutex_destroy(&chopstick[i]);
    }

    return 0;
}
