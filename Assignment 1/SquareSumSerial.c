// #include<stdio.h>
// #include <omp.h>

// int main()
// {
//     int sum = 0;
//     float start,end;

//     start = omp_get_wtime();
//     for(int i=0;i<100;i++)
//     {
//         int val = (i + 1) * (i + 1);
//         printf("The square of %d is %d and Thread id : %d\n",i, val,omp_get_thread_num());        
//         sum = sum + val;
//     }

//     end = omp_get_wtime();
//     printf("\n Time taken : %f\n",end-start);
//     printf("\n Sum : %d\n", sum);

//     return 0;
// }

#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    double time;
    clock_t begin = clock();

    int sum = 0;
    #pragma omp parallel for
    for (int i = 1; i <= 100; i++) 
    {
        printf("thread No. %d  Number : %d Square : %d\n", omp_get_thread_num(), i, i * i);
        sum += i * i;
    }
    printf("Sum : %d\n", sum);

    clock_t end = clock();
    time = (double)(end - begin) / CLOCKS_PER_SEC;
    printf("Time : %lf\n", time);
    return 0;
}
