#include <stdio.h>

void selectionSort(int arr[], int n) {
    //write your code here...
     for (int i = 0; i < n - 1; i++) { int maxIdx = i; for (int j = i + 1; j < n; j++) { if (arr[j] > arr[maxIdx]) { maxIdx = j; }    }
    int temp = arr[i]; arr[i] = arr[maxIdx]; arr[maxIdx] = temp; }    
}

int main() {
    int n;

    // Input number of elements in the array
    scanf("%d", &n);

    int arr[n];

    // Input array elements
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array in descending order using selection sort
    selectionSort(arr, n);

    // Output the sorted array
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
