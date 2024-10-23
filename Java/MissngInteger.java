public class MissngInteger {
    public static void main(String[] args) {
        int[] nums = {1, 2, 5, 4, 10, 9, 12}; // Example input array
        int ans = findMissingNumber(nums); // Call the function to find the missing number
        System.out.println(ans); // Print the result
    }

    public static int findMissingNumber(int[] nums) {
        int n = nums.length; // Length of the array
        int i = 0;

        // Cyclic sort: Place each number in its correct position if possible
        while (i < n) {
            int correctIndex = nums[i] - 1; // Calculate the correct index for nums[i]
            // Swap the number to its correct position if it's within the valid range and not already in place
            if (nums[i] > 0 && nums[i] <= n && nums[i] != nums[correctIndex]) {
                swap(nums, i, correctIndex);
            } else {
                i++; // Move to the next index if the current number is already in place or out of range
            }
        }

        // Check for the first missing positive number
        for (int idx = 0; idx < n; idx++) {
            // If the value at index idx is not equal to idx + 1, return idx + 1
            if (nums[idx] != idx + 1) {
                return idx + 1;
            }
        }

        // If all positive integers from 1 to n are present, return n + 1
        return n + 1;
    }

    // Helper function to swap two elements in the array
    public static void swap(int[] nums, int start, int end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
    }
}
