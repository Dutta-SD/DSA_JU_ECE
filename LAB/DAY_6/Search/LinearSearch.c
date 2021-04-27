# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# define FIND_VALUE 2299

/* ---------BINARY SEARCH----------*/
long linearSearch(long arr[], long l, long r, long x){
    for(long i = l; i <= r; ++i){
        if(arr[i] == x) return i;
    }    
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
    searchResult = linearSearch(arr, 0, len - 1, FIND_VALUE);
    if(searchResult != -1){
        printf("VALUE FOUND AT : %ld\n", searchResult);
    } else {
        printf("VALUE NOT FOUND\n");
    }

    // End the function
    clock_t stop = clock();

    double runtime = (double)(stop - start) / CLOCKS_PER_SEC;

    fprintf(fp, "LinearSearch, %ld, %lf\n", len, runtime);
    fclose(fp);
}

int main(){
    runDiagonistics();
    return 0;
}