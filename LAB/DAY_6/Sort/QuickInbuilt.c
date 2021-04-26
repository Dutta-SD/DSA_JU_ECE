# include <stdio.h>
# include <stdlib.h>
# include <time.h>
// USED LARGE SIZED FILES, SORTED OUTPUT NOT SHOWN

/* ---------QUICK SORT ALGORITHM----------*/
// We will be using the inbuilt quick sort 
// algorithm. It needs a comparing function
int cmpfunc (const void * a, const void * b) {
   return ( *(long*)a - *(long*)b );
}
/*---------------------------------------*/

void runOnRandomData(void) {
    freopen("CompletelyUnsorted.input", "r", stdin);
    freopen("runtimes.csv", "a", stdout);
    long len;
    scanf("%ld", &len);
    long *arr = malloc(len * sizeof(long));

    for(long i = 0; i < len; ++i){
        scanf("%ld", &arr[i]);
    }

    clock_t start = clock();

    qsort(arr, len, sizeof(long), cmpfunc);

    clock_t stop = clock();

    double runtime = (double)(stop - start) / CLOCKS_PER_SEC;

    printf("QuickSortInbuilt, U, %ld, %lf\n", len, runtime);
}

void runOnPartialSortData(void) {
    freopen("PartiallySorted.input", "r", stdin);
    freopen("runtimes.csv", "a", stdout);
    long len;
    scanf("%ld", &len);
    long *arr = malloc(len * sizeof(long));

    for(long i = 0; i < len; ++i){
        scanf("%ld", &arr[i]);
    }

    clock_t start = clock();
    qsort(arr, len, sizeof(long), cmpfunc);
    clock_t stop = clock();

    double runtime = (double)(stop - start) / CLOCKS_PER_SEC;

    printf("QuickSortInbuilt, P, %ld, %lf\n", len, runtime);
}
  
int main(){
    runOnRandomData();
    runOnPartialSortData();
    return 0;
}