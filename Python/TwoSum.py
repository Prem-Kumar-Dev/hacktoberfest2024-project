# arr = []
n = int(input("Enter number of elements : "))
# for i in range(n):
#     ele = int(input())
#     arr.append(ele)
arr = list(map(int, input().strip().split()))[:n]
target = int(input("Enter target value : "))
arr.sort()
l = 0
r = n - 1
while l < r:
    if (arr[l] + arr[r]) == target:
        print("Pair found (", arr[l], ",", arr[r], ")")
        break
    elif arr[l] + arr[r] < target:
        l += 1
    else:
        r -= 1

if(l >= r):
    print("No such pair exists")

# Time Complexity: O(n log n) due to sorting
# Space Complexity: O(1)