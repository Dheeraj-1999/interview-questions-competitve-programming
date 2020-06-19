// problem coin change: find total number of ways

// You are given an infinite supply of coins of each of denominations D = {D0, D1, D2, D3, ...... Dn-1}. 
// You need to figure out the total number of ways W, in which you can make change for Value V using coins of denominations D.
// Note : Return 0, if change isn't possible.

// probelm structure 2: find min coin change
// // find the minimum number of coins needed for a given change



// You have infinite supply of coins, each having some value. Can you figure out the minimum number coins required so that coins to sum-up to a certain required value. We'll use dynamic programmic to solve this question.

// You are given an amount denoted by value. You are also given an array of coins. The array contains the denominations of the give coins. You need to find the minimum number of coins to make the change for value using the coins of given denominations. Also, keep in mind that you have infinite supply of the coins.
// If making the change is not possible then print "Not Possible"

// Input Format:
// The first line of input contains number of testcases. Number of testcases follow. Each testcase contains three line of input. The first line contains value for which you need to make the change. The second line contains size of the array. The third line contains the denominations of the coins.

// Output Format:
// For each testcase, in a new line, print the minimum number of coins required.

// Your Task:
// This is a function problem. The input is already taken by the driver code.  You only need to complete the function minimumNumberOfCoins that take array of coins, size of array, and value as parameters. You need to return the minimum number of coins required.

// Expected Time Complexity: O(N*V).
// Expected Auxiliary Space: O(V)

// Constraints:
// 1 <= T <= 100
// 1 <= value <= 103
// 1 <= numberOfCoins <= 103
// 1 <= coinsi <= 1000

// Example:
// Input:
// 2
// 5
// 3
// 3 6 3
// 10
// 4
// 2 5 3 6
// Output:
// Not Possible
// 2

// Explanation:
// Testcase1: We need to make the change for value = 5
// The denominations are {3,6,3}
// It is certain that we cannot make 5 using any of these coins.
// Testcase2: We need to make the change for value = 10
// The denominations are {2,5,3,6}
// We can use two 5 coins to make 10. So minimum coins are 2.

#include<bits/stdc++.h>
using namespace std;

int minCoinChange(int* input, int n, int value, int* dp) {
    
    if(value <= 0) return 0;

    // if(dp[value][n] >  0)

    int mini = INT_MAX;
    for(int k=0; k<n; k++) { // loop over the coin array
        cout << value - input[k] << " " << mini << endl;
        if(dp[value-input[k]] > -1) return dp[value-input[k]]; // if remaining value exist in dp array
        
        if(value - input[k] >= 0){ // remaining value should not be negative

            int opt = minCoinChange(input, n, value-input[k], dp);
            mini = min(mini, opt+1); // which coin pattern is giving minimum coin change
        }
        
        dp[value] = mini;
    }
    
    return mini;
}


long long minimumNumberOfCoinsgfg(int input[],int n,int value)
{
    int* dp = new int[value+1];

    dp[0] = 0;
    // dp[1] = 1;
    // int mini = INT_MAX;
    
    for(int i=1; i<=value; i++){ // will iterate over dp array
        int mini = INT_MAX-1;
        for(int j=0; j<n; j++){ // will iterate over coin array
            if(i-input[j] >= 0)
                mini = min(mini, dp[i-input[j]]);
            // if(value-input[j] < 0)
            //     dp[i]= ;
            // dp[k] = min(dp[k], dp);
        }
        dp[i] = mini+1;
        // o(value*n)
    }
    // for(int i=0; i<value; i++) {
    //     cout << dp[i] << " ";
    // }
    return dp[value];
}
//
int main(int argc, char const *argv[])
{
    
    int n;
    cin >> n;
    int* deno = new int[n+1];
    
    for(int i=0; i<n; i++)
        cin >> deno[i];
    
    int value;
    cin >> value;

    int* dp = new int[value+1];
    for(int i=0; i<value; i++) {
        dp[i] = -1;
    }
    
    // minCoinChangeDp(deno, n, value);
    minCoinChange(deno, n, value, dp);

    for(int i=0; i<value; i++) {
        cout << dp[i] << " ";
    }

    return 0;
}
