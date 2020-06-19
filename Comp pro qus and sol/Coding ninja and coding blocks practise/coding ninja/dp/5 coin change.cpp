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

    int opt1 = coinChange(input, n, value, i+1); //we are excluding d[0]
    int opt2 = coinChange(input, n, value-*input, i); //we are including d[0]
    return (opt1+opt2);
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

int coinChangeDp(int* S, int m, int n) {
    // We need n+1 rows as the table  
    // is constructed in bottom up 
    // manner using the base case 0 
    // value case (n = 0) 
    int i, j, x, y;
    int table[n + 1][m]; 
      
    // Fill the enteries for 0 
    // value case (n = 0) 
    for (i = 0; i < m; i++) 
        table[0][i] = 1; 
  
    for(int i=0; i<m+1; i++) {
        for(int j=0; j<n+1; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    // Fill rest of the table entries  
    // in bottom up manner  
    for (i = 1; i < n + 1; i++) 
    { 
        for (j = 0; j < m; j++) 
        { 
            // Count of solutions including S[j] 
            // x = (i-S[j] >= 0) ? table[i - S[j]][j] : 0;
            table[i][j] = 0;
            if(i-S[j] >=0) {
                x = table[i-S[j]][j];
            } else x = 0;
  
            // Count of solutions excluding S[j] 
            // y = (j >= 1) ? table[i][j - 1] : 0; 
            if((j >= 1)) {
                y = table[i][j - 1];
            } else y = 0; 
  
            // total count 
            table[i][j] = x + y; 
        } 
    } 
    return table[n][m - 1]; 


    for(int i=0; i<m+1; i++) {
        for(int j=0; j<n+1; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
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
    cout << coinChangeDp(deno, n, value);
    return 0;
}
