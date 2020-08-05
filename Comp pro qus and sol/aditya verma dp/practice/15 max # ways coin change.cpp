// problem coin change: find total number of ways

// You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. 
// You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
// Note : Return 0, if change isn't possible.



#include<bits/stdc++.h>
using namespace std;

int coinChange(int* input, int n, int sum) {
    
    if(sum == 0) return 1;
    if(sum < 0 or n == 0) {
        return 0;                                                                                                                                    
    }

    // if(dp[value][n] >  0)
    if(*input <= sum) {
        int opt1 = coinChange(input+1, n-1, sum); //we are excluding d[0]
        int opt2 = coinChange(input, n, sum-*input); //we are including d[0]
        return (opt1+opt2);
    }
    return coinChange(input+1, n-1, sum);
}


int coinChangeMem(int* input, int n, int value, int i, int** dp) {
    
    if(value == 0) return 1;
    if(value < 0 or n == 0) {
        return 0;                                                                                                                                    
    }

    if(dp[value][n] >  0) {
        return dp[value][n];
    }

    int opt1 = coinChangeMem(input, n, value, i+1, dp); //we are excluding d[0]
    int opt2 = coinChangeMem(input, n, value-*input, i, dp); //we are including d[0]
    dp[value][n] = opt1 + opt2;
    return (opt1+opt2);
}

int coinChangeDp(int* coins, int numD, int sum) {
    int dp[numD+1][sum+1];

    for(int j=0; j<=sum; j++) {
        dp[0][j] = 0;
    }    
    for(int i=0; i<=numD; i++) {
        dp[i][0] = 1;
    }    

    for(int i=1; i<=numD; i++) {
        for(int j=1; j<=sum; j++) {
            if(coins[i] <= j) {
                int opt1 = dp[i][j-coins[i-1]];
                int opt2 = dp[i-1][j];
                dp[i][j] = opt1 + opt2;
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    return dp[numD][sum];
} 


int main(int argc, char const *argv[])
{
    
    int n;
    cin >> n;
    int* deno = new int[n+1];
    for(int i=0; i<n; i++)
        cin >> deno[i];
    int value;
    cin >> value;
    cout << coinChange(deno, n, value);
    return 0;
}
