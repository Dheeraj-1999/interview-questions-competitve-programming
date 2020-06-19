// rod given len l. 
// given for eaach length there is cost associated with it

//cut the rod in such way, maximizing  the profit is our goal


#include<bits/stdc++.h>
using namespace std;

int maxRodCut(int* arr, int n, int* dp) {
    if(n == 0) {
        return 0;
    }
    int profit = INT_MIN;
    for(int i=1; i<=n; i++) {
        if(dp[n] > 0) {
            return dp[n];
        }
        profit = max(profit, arr[i] + maxRodCut(arr, n-i, dp));
        dp[n] = profit;
    }
    return profit;
}

int maxRodCutDp(int* arr, int n) {
    
    int* dp = new int[n+1]; 
    int profit = INT_MIN;
    dp[0] = 0;
    for(int i=1; i<=n; i++) {
        dp[i] = 0;
        for(int j=1; j<=i; j++) {
            dp[i] = max(dp[i], arr[j] + dp[i-j]);
        }
    }
    return dp[n];
}


int main(int argc, char const *argv[])
{
    
    int n;
    cin >> n;
    int* profit = new int[n+1];
    for(int i=1; i<=n; i++)
        cin >> profit[i];
    int* dp = new int[n+1]();
    cout << maxRodCut(profit, n, dp) << endl;    
    cout << maxRodCutDp(profit, n);    
    return 0;
}
