// problem coin change: find total number of ways

// You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. 
// You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
// Note : Return 0, if change isn't possible.

// probelm structure 2: find min coin change
// find the minimum number of coins needed for a given change


#include<bits/stdc++.h>
using namespace std;

int coinChange(int* input, int n, int value, int i) {
    
    if(value == 0) return 1;
    if(value < 0 or n == 0) {
        return 0;                                                                                                                                    
    }

    // if(dp[value][n] >  0)

    int opt1 = coinChange(input, n, value, i+1);//we are excluding d[0]
    int opt2 = coinChange(input,n, value-*input, i);//we are including d[0]
    return (opt1+opt2);
}

int coinChangeDp(int* input, int n, int value) {
    int** dp = new int*[n+1];
    for(int i=0; i<value+1; i++) {
        dp[i] = new int[n+1];
        for(int j=0; j<n+1; j++) {
            dp[i][j] = -1;
        }
    }
    for(int j=0; j<=n; j++)
        dp[0][j] = 0;
    for(int i=1; i<=n; i++)
        dp[i][0] = 1;
    dp[1][0] = 1;
    // dp[1] = 1;
    for(int i=1; i<n; i++) {
        for(int j=0; j<n; j++) {


        }
    }
} 

int main(int argc, char const *argv[])
{
    
    int n;
    int* deno = new int[n+1];
    for(int i=0; i<n; i++)
        cin >> deno[i];
    int value;
    cin >> value;

    return 0;
}
