from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        complement_map = {}  # Dictionary to store number and its index
        for i, num in enumerate(nums):
            complement = target - num
            if complement in complement_map:
                return [complement_map[complement], i]  # Return indices of complement and current number
            complement_map[num] = i  # Store index of the current number
        return []  # In case no solution is found
    
# Example usage
solution = Solution()
nums = [2, 7, 11, 15]
target = 9
print(solution.twoSum(nums, target))  # Output: [0, 1]