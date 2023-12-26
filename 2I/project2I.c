#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

int *AllocateArray(int N)
{
    /* Allocate an array with N integers.
     * The value of each element of the array should be a
     * random number between 0 and 10N.
     * Hint: use the rand() function and a modulo operator.
     */
    int *arr = malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % (10 * N);
    }
    return arr;
}

int compare(const void *m, const void *n) {
    
    int n1 = *(const int *)m;
    int n2 = *(const int *)n;

    if (n1 > n2) return 1;
    if (n1 < n2) return -1;

    return 0;
}

void SortArray(int *A, int N) {
    qsort(A, N, sizeof(int), compare);
}

void DeallocateArray(int *A)
{
    free(A);
}

int main()
{
    int sizes[8] = { 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000 };

/* For fun:
 *  int sizes[11] = { 1000, 2000, 4000, 8000, 16000, 32000, 64000, 128000,
 *                    256000, 512000, 1024000 }; 
 */

    for (int i = 0 ; i < 8 ; i++) {

        double alloc_time = 0., sort_time = 0., dealloc_time = 0.;
        struct timeval startTime;
        struct timeval endTime;
        double sec, micro_sec;

        gettimeofday(&startTime, NULL);
        int *arr = AllocateArray(sizes[i]);
        gettimeofday(&endTime, NULL);
        sec = (endTime.tv_sec - startTime.tv_sec) ;
        micro_sec = ((double)(endTime.tv_usec - (double)startTime.tv_usec) / 1000000);
        alloc_time = (sec + micro_sec);

        gettimeofday(&startTime, NULL);
        SortArray(arr, sizes[i]);
        gettimeofday(&endTime, NULL);
        sec = (endTime.tv_sec - startTime.tv_sec);
        micro_sec = ((double)endTime.tv_usec - (double)startTime.tv_usec) / 1000000;
        sort_time = (sec + micro_sec);

        gettimeofday(&startTime, NULL);
        DeallocateArray(arr);
        gettimeofday(&endTime, NULL);
        sec = (endTime.tv_sec - startTime.tv_sec);
        micro_sec = ((double)endTime.tv_usec - (double)startTime.tv_usec) / 1000000;
        dealloc_time = (sec + micro_sec);

        /* Call the three functions in a sequence. Also use
         * gettimeofday calls surrounding each function and set the 
         * corresponding variable (alloc_time, sort_time, dealloc_time).
         */

        printf("Timings for array of size %d\n", sizes[i]);
        printf("\tTime for allocation is %g, time per element = %g\n", alloc_time * (100000), alloc_time/sizes[i]);
        printf("\tTime for sort_time is %g, time per element = %g\n", sort_time * (100000), sort_time/sizes[i]);
        printf("\tTime for deallocation is %g\n", dealloc_time * (100000));
    }
}
