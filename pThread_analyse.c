#include <stdio.h>
#include <pthread.h>

int main() {
    // Print pthread library version
    printf("Pthreads library version: %s\n", pthread_version());

    // Print the size of pthread_t
    printf("Size of pthread_t: %lu bytes\n", sizeof(pthread_t));

    // Print the size of pthread_attr_t
    printf("Size of pthread_attr_t: %lu bytes\n", sizeof(pthread_attr_t));

    // Print the size of pthread_mutex_t
    printf("Size of pthread_mutex_t: %lu bytes\n", sizeof(pthread_mutex_t));

    // Add more prints for other pthread-related types and functions as needed

    return 0;
}
