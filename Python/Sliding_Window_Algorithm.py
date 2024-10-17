def max_sum_subarray(arr, k):
    """
    Function to find the maximum sum of a subarray of size k using the sliding window technique.
    
    Parameters:
    arr (list): List of integers.
    k (int): Size of the subarray.
    
    Returns:
    int: Maximum sum of the subarray of size k.
    """
    # Edge case: if array length is smaller than k
    if len(arr) < k:
        print("Invalid: Array length is smaller than subarray size")
        return None
    
    # Compute the sum of the first window of size k
    window_sum = sum(arr[:k])
    max_sum = window_sum
    
    # Slide the window from the start of the array to the end
    for i in range(len(arr) - k):
        # Slide the window: subtract the element going out of the window and add the new element
        window_sum = window_sum - arr[i] + arr[i + k]
        max_sum = max(max_sum, window_sum)
    
    return max_sum

# Example Usage
if __name__ == "__main__":
    arr = [2, 1, 5, 1, 3, 2]
    k = 3
    result = max_sum_subarray(arr, k)
    print(f"Maximum sum of a subarray of size {k} is: {result}")
