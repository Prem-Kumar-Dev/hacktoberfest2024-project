# A Naive Recursive Python3 
# program to count derangements

def countDer(n):
	
	# Base cases
	if (n == 1): return 0
	if (n == 2): return 1
	
	# countDer(n) = (n-1)[countDer(n-1) + der(n-2)]
	return (n - 1) * (countDer(n - 1) +
					countDer(n - 2))

# Driver Code
n = 4
print("Count of Derangements is ", countDer(n))


