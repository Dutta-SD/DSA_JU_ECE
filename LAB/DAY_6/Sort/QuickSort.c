# include <stdio.h>
# include <stdlib.h>
# include <time.h>
// USED LARGE SIZED FILES, SORTED OUTPUT NOT SHOWN

/* ---------QUICK SORT ALGORITHM----------*/
void swap(long* a, long* b){ 
    long t = *a; 
    *a = *b; 
    *b = t; 
}  

long partition (long arr[], long low, long high) { 
    long pivot = arr[high]; // pivot 
    long i = (low - 1); // Rightmost element
  
    for (long j = low; j <= high - 1; j++){ 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
void quickSort(long arr[], long low, long high) { 
    if (low < high){ 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        long pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
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
    quickSort(arr, 0, len - 1);
    clock_t stop = clock();

    double runtime = (double)(stop - start) / CLOCKS_PER_SEC;

    printf("QuickSort, U, %ld, %lf\n", len, runtime);
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
    quickSort(arr,0, len - 1);
    clock_t stop = clock();

    double runtime = (double)(stop - start) / CLOCKS_PER_SEC;

    printf("QuickSort, P, %ld, %lf\n", len, runtime);
}
  
int main(){
    runOnRandomData();
    runOnPartialSortData();
    return 0;
}