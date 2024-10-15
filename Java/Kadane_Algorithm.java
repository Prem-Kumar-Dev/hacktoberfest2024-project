public class KadaneAlgorithm {
    public static int maxSubArraySum(int[] arr) {
        int maxSoFar = arr[0]; // Initialize to the first element
        int maxEndingHere = arr[0]; // Also start with the first element

        for (int i = 1; i < arr.length; i++) {
            maxEndingHere = Math.max(arr[i], maxEndingHere + arr[i]);
            maxSoFar = Math.max(maxSoFar, maxEndingHere);
        }

        return maxSoFar;
    }

    public static void main(String[] args) {
        int[] arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
        int result = maxSubArraySum(arr);
        System.out.println("Maximum contiguous sum is: " + result);
    }
}
