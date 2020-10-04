def nthfibRec(n):
    if(n == 1):
        return 1
    if n == 0:
        return 0
    return(nthfibRec(n-1) + nthfibRec(n-2))
    # return


def nthfibMem(n, dp):
    if(n == 1):
        return 1
    if n == 0:
        return 0

    if(dp[n] > -1):
        return dp[n]
    dp[n] = (nthfibMem(n-1, dp) + nthfibMem(n-2,dp))
    return dp[n]


def nthfibDp(n):
    dp = [0]*(n+1)

    dp[0] = 0
    dp[1] = 1
    for i in range(2, n):
        dp[i] = dp[i-1] + dp[i-2]
    
    return dp[n]

n = int(input())
dp = [-1]*(n+1)
print(nthfibMem(n, dp))

# 0 1 1 2 3 5 8