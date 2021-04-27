# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define FIND_VALUE 2299

/* ---------BINARY SEARCH----------*/
long binarySearch(long arr[], long l, long r, long x){
    if (r >= l) {
        // to avoid overflow
        int mid = l + (r - l) / 2;
 
        // If the element is present at the middle
        if (arr[mid] == x)
            return mid;
 
        // If element is smaller than mid
        if (arr[mid] > x) return binarySearch(arr, l, mid - 1, x);
 
        // Else the element can only be present
        return binarySearch(arr, mid + 1, r, x);
    }
 
    // element is not in array
    return -1;
}
/*---------------------------------*/

void runDiagonistics(void) {
    FILE* fp;

    freopen("InputNumbers.input", "r", stdin);
    fp = fopen("SearchRuntimes.csv", "a");

    long len;

    // equal to -1 if not found, else equal to index at which
    // found the number
    long searchResult;

    scanf("%ld", &len);

    long *arr = malloc(len * sizeof(long));

    for(long i = 0; i < len; ++i){
        scanf("%ld", &arr[i]);
    }

    clock_t start = clock();

    // Start the function
    searchResult = binarySearch(arr, 0, len - 1, FIND_VALUE);
    if(searchResult != -1){
        printf("VALUE FOUND AT : %ld\n", searchResult);
    } else {
        printf("VALUE NOT FOUND\n");
    }

    // End the function
    clock_t stop = clock();

    double runtime = (double)(stop - start) / CLOCKS_PER_SEC;

    fprintf(fp, "BinarySearch, %ld, %lf\n", len, runtime);
    fclose(fp);
}

int main(){
    runDiagonistics();
    return 0;
}