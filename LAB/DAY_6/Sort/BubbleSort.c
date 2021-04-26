# include <stdio.h>
# include <stdlib.h>
# include <time.h>
// USED LARGE SIZED FILES, SORTED OUTPUT NOT SHOWN
  
void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
void bubbleSort(int arr[], int n){
   int i, j;
   for (i = 0; i < n - 1; i++)  
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

void runOnRandomData(void) {
    freopen("CompletelyUnsorted.input", "r", stdin);
    freopen("BubbleSortUnsorted.output", "w", stdout);
    long len;
    scanf("%d", &len);
    long *arr = malloc(len * sizeof(long));

    for(long i = 0; i < len; ++i){
        scanf("%d", &arr[i]);
    }

    clock_t start = clock();
    bubbleSort(arr, len);
    clock_t stop = clock();

    long runtime = (stop - start) / CLOCKS_PER_SEC;

    printf("BubbleSort, U, %d, %ld\n", len, runtime);
}
  
int main(){
    runOnRandomData();
    return 0;
}