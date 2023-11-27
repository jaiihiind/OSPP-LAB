#include<stdio.h>

void fcfs(int requests[], int n ){
    printf("FCFS disc sheduling : \n");
    for (int i =0; i< n  ; i++){
        printf("%d ",requests[i]);
    }
    printf("\n");
}

void scan(int requests[], int n , int start){
    printf("SCAN disc sheduling : \n");
    printf("%d ",start);
    for(int i =0; i< n ; i++){
        printf("%d ", requests[i]);

    }
}

int main(){
    int requests[] = {44,32,45,55,84,33,23,56,90};
    int n = sizeof(requests) / sizeof(requests[0]);
    int start = 56;

    fcfs(requests, n );
    scan(requests ,n , start );


}