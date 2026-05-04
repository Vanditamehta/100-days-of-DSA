/*Sort array of non-negative integers using counting sort.
Find max, build freq array, compute prefix sums, build output.*/
#include <stdio.h>

// Counting Sort
void countingSort(int arr[], int n) {
    // Step 1: Find max
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    // Step 2: Create count array
    int count[max + 1];
    for (int i = 0; i <= max; i++)
        count[i] = 0;

    // Store frequency
    for (int i = 0; i < n; i++)
        count[arr[i]]++;

    // Step 3: Prefix sum
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1];

    // Step 4: Build output (stable)
    int output[n];
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Step 5: Copy back
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    countingSort(arr, n);

    // Print sorted array
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}