#include <stdio.h>

void heapify(int arr[], int len, int i) {
    int lar = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < len && arr[l] > arr[lar])
        lar = l;

    if (r < len && arr[r] > arr[lar])
        lar = r;

    if (lar != i) {
        int tmp = arr[i];
        arr[i] = arr[lar];
        arr[lar] = tmp;
        heapify(arr, len, lar);
    }
}

void heap_sort(int arr[], int len) {
    for (int i = len / 2 - 1; i >= 0; i--)
        heapify(arr, len, i);

    for (int i = len - 1; i > 0; i--) {
        int tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heapify(arr, i, 0);
    }
}

void print_arr(int arr[], int len) {
    for (int i = 0; i < len; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int len = sizeof(arr) / sizeof(arr[0]);

    heap_sort(arr, len);

    printf("Sorted array is\n");
    print_arr(arr, len);
    return 0;
}
