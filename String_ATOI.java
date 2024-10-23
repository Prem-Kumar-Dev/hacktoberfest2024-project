import java.util.*;

public class String_ATOI {

    // Function to convert a string to an integer
    static int myAtoi(String s) {
        int N = s.length();  // Length of the input string
        int i = 0;           // Pointer to traverse the string
        int A = 1;           // Sign variable (1 for positive, -1 for negative)
        int count = 0;       // Counter to check if we've started processing digits
        long sum = 0;        // Resulting integer (stored as long to handle overflow)
        int count1 = 0;      // Counter to ensure only one sign (+ or -) is processed

        // Skip any leading spaces
        while (i < N && s.charAt(i) == ' ') {
            i++;
        }

        // Process the string starting from the first non-whitespace character
        for (int k = i; k < N; k++) {
            char C = s.charAt(k);  // Current character

            // Case: Handling the first character (+, -, or a digit)
            if (count == 0 && count1 == 0) {
                if (C == '-') {
                    A = -1;  // Set the sign to negative
                    count1++;  // Mark that a sign has been processed
                } else if (C == '+') {
                    A = 1;  // Set the sign to positive
                    count1++;  // Mark that a sign has been processed
                } else if (C < '0' || C > '9') {
                    // If the first non-space character is not a valid digit, return 0
                    return 0;
                } else if (C >= '0' && C <= '9') {
                    sum = sum * 10 + (int)(C - '0');  // Convert character to digit and add to sum
                    count++;  // Mark that digits are being processed
                }
            }

            // Case: After the first digit, continue processing the digits
            else if (count > 0) {
                if (C == '-' || C == '+') {
                    break;  // Stop if we encounter another sign after processing digits
                } else if (C < '0' || C > '9') {
                    break;  // Stop if a non-digit character is found
                } else if (C >= '0' && C <= '9') {
                    sum = sum * 10 + (int)(C - '0');  // Continue converting characters to digits
                    count++;  // Increment digit count
                }
            }

            // Case: Handle only one sign
            else if (count1 > 0) {
                if (C == '-' || C == '+') {
                    return 0;  // Return 0 if another sign is found after the first sign
                } else if (C < '0' || C > '9') {
                    return 0;  // Return 0 if a non-digit character follows a sign
                } else if (C >= '0' && C <= '9') {
                    sum = sum * 10 + (int)(C - '0');  // Start processing digits
                    count++;  // Mark that digits are being processed
                }
            }

            // Check for overflow or underflow
            if (sum * A > Integer.MAX_VALUE) {
                return Integer.MAX_VALUE;  // Return max int if the number exceeds the max value
            } else if (sum * A < Integer.MIN_VALUE) {
                return Integer.MIN_VALUE;  // Return min int if the number goes below the min value
            }
        }

        // Return the final result with the correct sign
        return (int) sum * A;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);  // Create a scanner for input
        String str = sc.next();  // Get the input string
        int result = myAtoi(str);  // Convert the string to an integer using myAtoi
        System.out.println(result);  // Output the result

        sc.close();  // Close the scanner to prevent resource leak
    }
}
