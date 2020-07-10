# Given an array A of N positive numbers. The task is to find the first Equilibium Point in the array. 
# Equilibrium Point in an array is a position such that the sumof elements before it is equal to the sum of elements after it.

def equilibriumPoint(A, n):
    # sumArr = sum(A)
    sumCheck = 0
    dp = []
    if(n == 1):
        return 1
    for i in range(len(A)):
        sumCheck += A[i]
        dp.append(sumCheck)
    for i in range(1, len(A)):
        sumLeft = dp[i-1]
        sumRight = dp[n-1] - dp[i]
        if(sumRight == sumLeft):
            return i+1
    return -1