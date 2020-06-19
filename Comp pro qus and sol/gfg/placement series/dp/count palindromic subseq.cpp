#include<bits/stdc++.h>
using namespace std;

int countPalindromic(string str, int i, int j) {
    if(i == j)
        return 1;
    if(str[i] == str[j]) {
        return countPalindromic(str, i+1, j) + countPalindromic(str, i, j-1) + 1;
    } else {
        return countPalindromic(str, i+1, j) + countPalindromic(str, i, j-1) - countPalindromic(str, i+1, j-1);
    }
}

int countPalindromicDp(string str) {
    int n = str.length();
    int dp[n+5][n+5];
    memset(dp, 0 ,sizeof(dp));

    for(int i=0; i<n; i++) {
        dp[i][i] = 1;
    }

    for(int l=2; l<=n; l++) {
        for(int i=0; i<n; i++) {
            int k = l+i-1;
            if(str[i] == str[k]) {
                dp[i][k] = dp[i+1][k] + dp[i][k-1] + 1;
            } else {
                dp[i][k] = dp[i+1][k] + dp[i][k-1] - dp[i+1][k-1];
            }
        }
    }
    return dp[0][n-1];
}

int countPS(string str) 
{ 
    int N = str.length(); 
  
    // create a 2D array to store the count of palindromic 
    // subsequence 
    int cps[N+1][N+1]; 
    memset(cps, 0 ,sizeof(cps)); 
  
    // palindromic subsequence of length 1 
    for (int i=0; i<N; i++) 
        cps[i][i] = 1; 
  
    // check subsequence of length L is palindrome or not 
    for (int L=2; L<=N; L++) 
    { 
        for (int i=0; i<N; i++) 
        { 
            int k = L+i-1; 
            if (str[i] == str[k]) 
                cps[i][k] = cps[i][k-1] + 
                            cps[i+1][k] + 1; 
            else
                cps[i][k] = cps[i][k-1] + 
                            cps[i+1][k] - 
                            cps[i+1][k-1]; 
        } 
    } 
  
    // return total palindromic subsequence 
    return cps[0][N-1]; 
} 

int main(int argc, char const *argv[])
{
    
    string str;
    cin >> str;
    int n = str.length();
    cout << countPalindromicDp(str);
    return 0;
}