#include <stdio.h>
#include <stdlib.h>
// Optimization
#define RUN 32

void ins_srt(int arr[], int lft, int rgt) {
    for (int i = lft + 1; i <= rgt; i++) {
        int tmp = arr[i];
        int j = i - 1;
        while (j >= lft && arr[j] > tmp) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = tmp;
    }
}

void mrg(int arr[], int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    int *lft = (int*)malloc(len1 * sizeof(int));
    int *rgt = (int*)malloc(len2 * sizeof(int));

    for (int x = 0; x < len1; x++)
        lft[x] = arr[l + x];
    for (int x = 0; x < len2; x++)
        rgt[x] = arr[m + 1 + x];

    int i = 0, j = 0, k = l;
    while (i < len1 && j < len2) {
        if (lft[i] <= rgt[j]) {
            arr[k] = lft[i];
            i++;
        } else {
            arr[k] = rgt[j];
            j++;
        }
        k++;
    }

    while (i < len1) {
        arr[k] = lft[i];
        k++;
        i++;
    }

    while (j < len2) {
        arr[k] = rgt[j];
        k++;
        j++;
    }

    free(lft);
    free(rgt);
}

void tim_srt(int arr[], int n) {
    for (int i = 0; i < n; i += RUN)
        ins_srt(arr, i, i + RUN - 1 < n - 1 ? i + RUN - 1 : n - 1);

    for (int sz = RUN; sz < n; sz = 2 * sz) {
        for (int lft = 0; lft < n; lft += 2 * sz) {
            int mid = lft + sz - 1;
            int rgt = (lft + 2 * sz - 1) < (n - 1) ? (lft + 2 * sz - 1) : (n - 1);

            if (mid < rgt)
                mrg(arr, lft, mid, rgt);
        }
    }
}

void prt_arr(int arr[], int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {5, 21, 7, 23, 19};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Given Array is\n");
    prt_arr(arr, n);

    tim_srt(arr, n);

    printf("After Sorting Array is\n");
    prt_arr(arr, n);
    return 0;
}
