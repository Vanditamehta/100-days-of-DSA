/*Problem: Given a sorted array of n integers, remove duplicates in-place. Print only unique elements in order.

Input:
- First line: integer n
- Second line: n space-separated integers (sorted array)

Output:
- Print unique elements only, space-separated

Example:
Input:
6
1 1 2 2 3 3

Output:
1 2 3

Explanation: Keep first occurrence of each element: 1, 2, 3*/
#include <stdio.h>
int main() 
{    int n;
    // Read size of the array
    printf("Enter number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    // Read elements of the array    
    for (int i = 0; i < n; i++) 
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    // Print unique elements
    printf("Unique elements: ");
    for (int i = 0; i < n; i++) 
    {
        if (i == 0 || arr[i] != arr[i - 1]) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
    return 0;
}