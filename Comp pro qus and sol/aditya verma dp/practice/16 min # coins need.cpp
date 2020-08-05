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
        cout << value - input[k] << " " << mini << endl;
    }
    
    dp[value] = mini;
    return mini;
}

int minCoinChangeDp(int* coins, int numD, int sum) {
    int dp[numD+1][sum+1];
    memset(dp,0,sizeof(dp));

    for(int j=0; j<=sum; j++) {
        dp[0][j] = INT_MAX - 1;
    }   
    for(int j=1; j<=sum; j++) {
        if(j%coins[0] == 0)
            dp[1][j] = j/coins[0];
        else
            dp[1][j] = INT_MAX - 1;
    }       
    // for(int i=1; i<=numD; i++) {
    //     dp[i][0] = 0;
    // }    
    for(int i=2; i<=numD; i++) {
        for(int j=1; j<=sum; j++) {
            if(coins[i] <= j) {
                int opt1 = 1+dp[i][j-coins[i-1]];
                int opt2 = dp[i-1][j];
                dp[i][j] = min(opt1, opt2);
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    // for(int i=0; i<=numD; i++) {
    //     for(int j=0; j<=sum; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[numD][sum];
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

    int* dp = new int[value+1]();
    
    // minCoinChangeDp(deno, n, value);
    cout << minCoinChangeDp(deno, n, value);

    // for(int i=0; i<value; i++) {
    //     cout << dp[i] << " ";
    // }

    return 0;
}
