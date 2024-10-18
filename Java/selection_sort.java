// Selection Sort
import java.util.Arrays;
import java.util.Scanner;

class GfG {

    static void selectionSort(int[] arr){
        int n = arr.length;
        for (int i = 0; i < n - 1; i++) {
            int min_idx = i;

            for (int j = i + 1; j < n; j++) {
                if (arr[j] < arr[min_idx]) {
                    min_idx = j;
                }
            }
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;           
        }
    }

    static void printArray(int[] arr){
        for (int val : arr) {
            System.out.print(val + " ");
        }
        System.out.println();
    }
  
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        print("Enter the size of the array:");
        int n = sc.nextInt();
        int arr[]= new int[n];
        print("Enter the elements of the array:");
        for (int i : n) {
            arr[i]=sc.nextInt();
        }
        System.out.print("Original array: ");
        printArray(arr);

        selectionSort(arr);

        System.out.print("Sorted array: ");
        printArray(arr);
    }
}
