#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NOT_FOUND -1

int linear_search(int *arr, int arrSize, int key);

int main()
{
    int arrSize, key, i;
    int *arr;
    clock_t start, stop;
    FILE *fl;

    // Opening the csv files
    fl = fopen("linear_search.csv", "a");

    srand(time(0));

    // Creating the array
    printf("Enter the number of elements:");
    scanf("%d", &arrSize);

    arr = (int *)malloc(arrSize * sizeof(int));
    for (i = 0; i < arrSize; i++)
    {
        arr[i] = rand() % 100;
    }

    // Input the element to search
    // printf("\nEnter the element to search:");
    // scanf("%d", &key);
    key=100;

    // Searching the array

    // linear_search
    start = clock();
    linear_search(arr, arrSize, key);
    stop = clock();

    double timeTaken = (double)(stop - start) / CLOCKS_PER_SEC;
    fprintf(fl, "%d, %f\n", arrSize, timeTaken);

    fclose(fl);
    return 0;
}

int linear_search(int *arr, int arrSize, int key)
{
    int i;
    for (i = 0; i < arrSize; i++)
    {
        if (arr[i] == key)
        {
            printf("\n%d found at index %d of the array.", key, i);
            return i;
        }
    }
    if (i == arrSize)
    {
        printf("\n%d not found in the array.", key);
        return NOT_FOUND;
    }
}