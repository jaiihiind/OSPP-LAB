#include<stdio.h>
#include <pthread.h>

void *show (void *u){
    printf("new thread \n");

}


int main(){

    pthread_t id;    //used to store the id of thread
    pthread_create(&id, NULL , &show, NULL );   //Creating thread (id , attributes, function, arguments )
    printf("main thread \n");

    pthread_join(id, NULL);  //will make the main thread to wait, until the new thread completes
}
