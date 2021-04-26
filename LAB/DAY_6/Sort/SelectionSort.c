# include <stdio.h>
# include <stdlib.h>
# include <time.h>
// USED LARGE SIZED FILES, SORTED OUTPUT NOT SHOWN

/* ---------SELECTION SORT ALGORITHM----------*/
void swap(long *xp, long *yp){
    long temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
void selectionSort(long arr[], long n){
    long i, j, min_idx;
  
    for (i = 0; i < n-1; i++){
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
  
        swap(&arr[min_idx], &arr[i]);
    }
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
    selectionSort(arr, len);
    clock_t stop = clock();

    double runtime = (double)(stop - start) / CLOCKS_PER_SEC;

    printf("SelectionSort, U, %ld, %lf\n", len, runtime);
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
    selectionSort(arr, len);
    clock_t stop = clock();

    double runtime = (double)(stop - start) / CLOCKS_PER_SEC;

    printf("SelectionSort, P, %ld, %lf\n", len, runtime);
}
  
int main(){
    runOnRandomData();
    runOnPartialSortData();
    return 0;
}