#include <omp.h>
#include <pthread.h>
#include <stdio.h>

int main() {
    int N = 50;
    int A[50];
    for (int i = 0; i < N; i++)
        A[i] = 10;

    int B[50];
    for (int i = 0; i < N; i++)
        B[i] = 20;

    int C[50] = {0};
    double stime = omp_get_wtime();
#pragma omp parallel for
    for (int i = 0; i < N; i++) {
        C[i] = A[i] + B[i];
        printf("Index: %d Thread: %d \n", i, omp_get_thread_num());
    }
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", C[i]);
    }

    double etime = omp_get_wtime();
    double time = etime - stime;
    printf("\n\nTime taken is %f\n", time);
    printf("\n");
    return 0;
}
