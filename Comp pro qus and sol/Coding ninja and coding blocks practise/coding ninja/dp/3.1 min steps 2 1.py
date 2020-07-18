import sys
sys.setrecusrionlimit=10**6
def minStepsTo1DP(n,dp):
    ''' Return Minimum no of steps required to reach 1 using using Dynamic Prog'''
    if n==1:
        return 0
    if dp[n]!=-1:
        return dp[n]
    ans2=999999999
    if n%2==0:
        ans2=minStepsTo1DP(n//2,dp)
    ans3=999999999
    if n%3==0:
        ans3=minStepsTo1DP(n//3,dp)
    ans1=minStepsTo1DP(n-1,dp)
    ans=1+min(ans1,ans2,ans3)
    dp[n]=ans
    return ans

def minStepsTo1DPIter(n):
    dp=[0 for i in range(n+1)]
    dp[1]=1
    i=2
    while i<=n:
        ans1=dp[i-1]
        ans2=dp[i//2] if i%2==0 else 999999999
        ans3=dp[i//3] if i%3==0 else 999999999
        dp[i]=1+min(ans1,ans2,ans3)
    
    return dp[n]

def minStepsDng(n, dp):
    if(n == 1):
        return 0
    a = 100000
    b = 100000
    c = 100000
    
    if(dp[n] > 0):
        return dp[n]
    if n%2==0:
        a = minStepsDng(n//2,dp)
    # ans3=999999999
    if n%3==0:
        b = minStepsDng(n//3,dp)
    
    c = minStepsDng(n-1, dp)
    
    ans = 1 + min(a, min(b, c))
    dp[n] = ans
    return ans
    
    

    
# Main
n=int(input())
dp=[0 for i in range(n+1)]
# print(minStepsTo1DP(n,dp))
print(minStepsDng(n, dp))
