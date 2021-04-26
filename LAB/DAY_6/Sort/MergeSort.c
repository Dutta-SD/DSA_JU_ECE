# include <stdio.h>
# include <stdlib.h>
# include <time.h>
// USED LARGE SIZED FILES, SORTED OUTPUT NOT SHOWN

/* ---------MERGE SORT ALGORITHM----------*/
void merge(long arr[], long l, long m, long r){
    long i, j, k;
    long n1 = m - l + 1;
    long n2 = r - m;
 
    /* create temp arrays */
    long L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l is for left index and r is right index of the
sub-array of arr to be sorted */
void mergeSort(long arr[], long l, long r){
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        long m = l + (r - l) / 2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
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
    mergeSort(arr, 0, len - 1);
    clock_t stop = clock();

    double runtime = (double)(stop - start) / CLOCKS_PER_SEC;

    printf("MergeSort, U, %ld, %lf\n", len, runtime);
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
    mergeSort(arr,0, len - 1);
    clock_t stop = clock();

    double runtime = (double)(stop - start) / CLOCKS_PER_SEC;

    printf("MergeSort, P, %ld, %lf\n", len, runtime);
}
  
int main(){
    runOnRandomData();
    runOnPartialSortData();
    return 0;
}