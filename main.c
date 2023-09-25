#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void swap(int *x, int *y);
void printArr(int array[], int length);
void bubbleSort(int array[], int length);
void selectionSort(int array[], int length);
void insertionSort(int array[], int length);
void quickSort(int array[], int length);
void quickSortRecursion(int array[], int low, int high);
int partition(int array[], int low, int high);


int main() {
    int arr[100], arr1[100], arr2[100], arr3[100], arr4[100];

    int n;
    printf("input length n of array ");
    scanf ("%d", &n);
    printf("input array elements \n");
    for (int i = 0; i < n; ++i){
        scanf("%d", &arr[i]);
        arr1[i] = arr[i];
        arr2[i] = arr[i];
        arr3[i] = arr[i];
        arr4[i] = arr[i];
    }
    printf("\n");

    clock_t start = clock();
    printf("sorted using bubble sort: \n");
    bubbleSort(arr1, n);
    clock_t end = clock();
    double seconds = (double)(end - start)/CLOCKS_PER_SEC;
    printf ("%f \n", seconds);
    printf("\n");

    start = clock();
    printf("sorted using selection sort: \n");
    selectionSort(arr2, n);
    end = clock();
    seconds = (float)(end - start)/CLOCKS_PER_SEC;
    printf ("%f \n", seconds);
    printf("\n");

    start = clock();
    printf("sorted using insertion sort: \n");
    insertionSort(arr3, n);
    end = clock();
    seconds = (float)(end - start)/CLOCKS_PER_SEC;
    printf ("%f \n", seconds);
    printf("\n");

    start = clock();
    printf("sorted using quick sort: \n");
    quickSort(arr4, n);
    end = clock();
    seconds = (float)(end - start)/CLOCKS_PER_SEC;
    printf ("%f \n", seconds);

    return 0;
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void printArr(int array[], int length){
    for (int i = 0; i < length; ++i){
        printf ("%d ", array[i]);
    }
    printf("\n");
}

void bubbleSort(int array[], int length){
    for (int i = 0; i < length-1; ++i){
        for (int j = 0; j < length - i - 1; ++j){
            if (array[j] > array[j+1]){
                swap(&array[j], &array[j+1]);
            }
        }
    }
    printArr(array, length);
}

void selectionSort(int array[], int length){
    int indexOfMinValue;
    for (int i = 0; i < length - 1; ++i){
        indexOfMinValue = i;
        for (int j = i + 1; j < length; ++j){
            if (array[j] < array[indexOfMinValue]){
                indexOfMinValue = j;
            }
        }
        if (indexOfMinValue != i){
            swap(&array[i], &array[indexOfMinValue]);
        }
    }
    printArr(array, length);
}

void insertionSort(int array[], int length){
    int currentElement, j;
    for (int i = 1; i < length; ++i){
        currentElement = array[i];
        j = i - 1;
        while ((j >= 0) && (array[j] > currentElement)){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = currentElement;
    }
    printArr(array, length);
}


void quickSort(int array[], int length)
{
    srand(time(NULL));
    quickSortRecursion(array, 0, length - 1);
    printArr(array, length);
}


void quickSortRecursion(int array[], int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(array, low, high);
        quickSortRecursion(array, low, pivotIndex - 1);
        quickSortRecursion(array, pivotIndex + 1, high);
    }
}


int partition(int array[], int low, int high)
{
    int pivotIndex = low + (rand() % (high - low));
    if (pivotIndex != high){
        swap(&array[pivotIndex], &array[high]);
    }

    int pivotValue = array[high];
    int i = low;

    for (int j = low; j < high; j++){
        if (array[j] <= pivotValue){
            swap(&array[i], &array[j]);
            i++;
        }
    }
    swap(&array[i], &array[high]);
    return i;
}
