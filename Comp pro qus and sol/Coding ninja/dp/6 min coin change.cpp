// problem coin change: find total number of ways

// You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. 
// You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
// Note : Return 0, if change isn't possible.

// probelm structure 2: find min coin change
// find the minimum number of coins needed for a given change

#include<bits/stdc++.h>
using namespace std;

int minCoinChange(int* input, int n, int value, int* dp) {
    
    if(value <= 0) return 0;


    // if(dp[value][n] >  0)

    int mini = INT_MAX;
    for(int k=0; k<n; k++){ // loop over the coin array
        if(dp[value-input[k]] > -1) return dp[value-input[k]]; // if remaining value exist in dp array
        
        if(value - input[k] >= 0){ // remaining value should not be negative

            int opt = minCoinChange(input, n, value-input[k], dp);
            mini = min(mini, opt+1); // which coin pattern is giving minimum coin change
        }
    }
    
    dp[value] = mini;
}

int minCoinChangeDp(int* input, int n, int value) {
    int* dp = new int[value+1];

    dp[0] = 1;
    dp[1] = 1;
    // int mini = INT_MAX;
    
    for(int i=2; i<=value; i++){ // will iterate over dp array
        int mini = INT_MAX;
        for(int j=0; j<n; j++){ // will iterate over coin array
            if(value-input[j] >= 0)
                mini = min(mini, dp[value-input[j]]);
            // dp[k] = min(dp[k], dp);
        }
        dp[i] = mini+1;
        // o(value*n)
    }
    for(int i=0; i<value; i++) {
        cout << dp[i] << " ";
    }
    return dp[value];
}

int main(int argc, char const *argv[])
{
    
    int n;
    cin>>n;
    int* deno = new int[n+1];
    for(int i=0; i<n; i++)
        cin >> deno[i];
    int value;
    cin >> value;

    minCoinChangeDp(deno, n, value);

    return 0;
}
