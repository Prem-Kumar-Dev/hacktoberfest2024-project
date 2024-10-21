def shell_sort(arr):
    n = len(arr)
    gap = n // 2  # Start with a large gap, then reduce the gap

    # Continue until the gap reduces to zero
    while gap > 0:
        for i in range(gap, n):
            temp = arr[i]
            j = i
            # Shift elements of arr[0..i-gap] that are greater than temp to one position ahead
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap
            arr[j] = temp
        
        # Reduce the gap for the next pass
        gap //= 2

# TESTING THE FUNCTION (DELETE IF NOT WANTED)
if __name__ == "__main__":
    arr = [12, 34, 54, 2, 3, 7, 8, 1, 22]
    print("Original array:", arr)
    shell_sort(arr)
    print("Sorted array:", arr)
