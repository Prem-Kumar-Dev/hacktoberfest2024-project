#include<bits/stdc++.h>
using namespace std;

// Function to sort the array using bubble sort algorithm.
void bubbleSort(int arr[], int n) {
    
    // Initialize a flag to track if any swaps were made
    bool flag = false;
    
    // Outer loop to iterate through the array
    for (int i = 0; i < n - 1; i++) {  
        // Inner loop for comparing adjacent elements
        for (int j = 0; j < n - 1 - i; j++) {
            // If the current element is greater than the next, swap them
            if (arr[j] > arr[j + 1]) {
                flag = true; 
                swap(arr[j], arr[j + 1]); // Swap the elements
            }
        }
        // If no swaps were made in the inner loop, the array is sorted
        if (flag == false) break; 
    }
}
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]); // Calculate the number of elements in the array

    cout << "Unsorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Print the unsorted array
    }
    cout << endl;

    // Call the bubbleSort function to sort the array
    bubbleSort(arr, n);

    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; // Print the sorted array
    }
    cout << endl;

    return 0; 
}