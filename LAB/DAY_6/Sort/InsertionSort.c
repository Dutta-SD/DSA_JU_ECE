# include <stdio.h>
# include <stdlib.h>
# include <time.h>
// USED LARGE SIZED FILES, SORTED OUTPUT NOT SHOWN

/* ---------INSERTION SORT ALGORITHM----------*/
void insertionSort(long arr[], long n){
    long i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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
    insertionSort(arr, len);
    clock_t stop = clock();

    double runtime = (double)(stop - start) / CLOCKS_PER_SEC;

    printf("InsertionSort, U, %ld, %lf\n", len, runtime);
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
    insertionSort(arr, len);
    clock_t stop = clock();

    double runtime = (double)(stop - start) / CLOCKS_PER_SEC;

    printf("InsertionSort, P, %ld, %lf\n", len, runtime);
}
  
int main(){
    runOnRandomData();
    runOnPartialSortData();
    return 0;
}