#include <stdio.h>
#include <stdlib.h>

// Compare function for qsort (sort by start time)
int compare(const void* a, const void* b) {
    int* m1 = (int*)a;
    int* m2 = (int*)b;
    return m1[0] - m2[0];
}

// Min Heap functions
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(int heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent] > heap[index]) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else break;
    }
}

void heapifyDown(int heap[], int size, int index) {
    int smallest = index;

    while (1) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left] < heap[smallest])
            smallest = left;
        if (right < size && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else break;
    }
}

// Main function
int minMeetingRooms(int intervals[][2], int n) {
    // Step 1: sort by start time
    qsort(intervals, n, sizeof(intervals[0]), compare);

    int heap[n];  // min heap of end times
    int size = 0;

    // Add first meeting
    heap[size++] = intervals[0][1];

    for (int i = 1; i < n; i++) {
        // If room is free
        if (intervals[i][0] >= heap[0]) {
            heap[0] = intervals[i][1];
            heapifyDown(heap, size, 0);
        } else {
            // Need new room
            heap[size++] = intervals[i][1];
            heapifyUp(heap, size - 1);
        }
    }

    return size;
}

// Main
int main() {
    int n;
    printf("Enter number of meetings: ");
    scanf("%d", &n);

    int intervals[n][2];
    for (int i = 0; i < n; i++) {
        printf("Enter start and end time of meeting %d: ", i + 1);
        scanf("%d %d", &intervals[i][0], &intervals[i][1]);
    }

    printf("%d\n", minMeetingRooms(intervals, n));

    return 0;
}