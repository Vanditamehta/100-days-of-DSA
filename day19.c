/*Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.*/
#include <stdio.h>

// Function to reverse part of array
void reverse(int arr[], int start, int end) {
    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];

    // Input array
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int k;
    scanf("%d", &k);

    // Handle k greater than n
    k = k % n;

    // Step 1: Reverse whole array
    reverse(arr, 0, n-1);

    // Step 2: Reverse first k elements
    reverse(arr, 0, k-1);

    // Step 3: Reverse remaining elements
    reverse(arr, k, n-1);

    // Print rotated array
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}