#define HASH_SIZE 100000

int hash(int num) {
    // Simple hash function to handle negative numbers and large values
    return (num + HASH_SIZE) % HASH_SIZE;
}

int majorityElement(int* nums, int numsSize) {
    int* count = (int*)calloc(
        HASH_SIZE,
        sizeof(int)); // Dynamic allocation and initialization to zero

    // Count occurrences
    for (int i = 0; i < numsSize; i++) {
        count[hash(nums[i])]++;
    }

    // Find the majority element
    int ans = INT_MIN;
    for (int i = 0; i < numsSize; i++) {
        if (count[hash(nums[i])] > numsSize / 2) {
            ans = nums[i];
            break; // Early termination
        }
    }

    free(count); // Free allocated memory
    return ans;
}
