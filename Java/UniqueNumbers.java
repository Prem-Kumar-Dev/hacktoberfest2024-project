import java.util.HashMap;
import java.util.Scanner;

public class UniqueNumbers {

    // Method to find and display unique numbers in the array
    public static void findUniqueNumbers(int[] array) {
        // Create a HashMap to store the frequency of each number
        HashMap<Integer, Integer> frequencyMap = new HashMap<>();

        // Populate the frequency map with numbers and their counts
        for (int num : array) {
            frequencyMap.put(num, frequencyMap.getOrDefault(num, 0) + 1);
        }

        // Display unique numbers (those that appear only once)
        System.out.println("Unique numbers in the array are: ");
        boolean foundUnique = false;
        for (int num : frequencyMap.keySet()) {
            if (frequencyMap.get(num) == 1) {
                System.out.print(num + " ");
                foundUnique = true;
            }
        }

        if (!foundUnique) {
            System.out.println("No unique numbers found.");
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // Taking input for the array size
        System.out.print("Enter the number of elements in the array: ");
        int size = scanner.nextInt();

        int[] array = new int[size];

        // Taking input for the array elements
        System.out.println("Enter " + size + " integers: ");
        for (int i = 0; i < size; i++) {
            array[i] = scanner.nextInt();
        }

        // Find and display unique numbers
        findUniqueNumbers(array);

        scanner.close();
    }
}
