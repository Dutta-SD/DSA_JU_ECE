# include <stdio.h>
# include <stdlib.h>
# include <time.h>
// USED LARGE SIZED FILES, SORTED OUTPUT NOT SHOWN

/* ---------BUBBLE SORT ALGORITHM----------*/
void swap(long *xp, long *yp){
    long temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
void bubbleSort(long arr[], long n){
   long i, j;
   for (i = 0; i < n - 1; i++)  
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
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
    bubbleSort(arr, len);
    clock_t stop = clock();

    long runtime = (double)(stop - start) / CLOCKS_PER_SEC;

    printf("BubbleSort, U, %ld, %lf\n", len, runtime);
}
  
int main(){
    runOnRandomData();
    return 0;
}