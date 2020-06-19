// given an arry of price of wines
// condn1: in one year we can sell only one bottle either extreme left or rigth
// condn2: In yth year p[i] = p[i]*y

// Recursive approach + DP approach

#include<bits/stdc++.h>
using namespace std;

int winesPrblm(int* arr, int i, int j, int y, int n, int** dp) {
    
    if(i>j) {
        return 0;
    }
    if(dp[i][j] > -1) {
        return dp[i][j];
    }
    int opt1 = y*(arr[i]) + winesPrblm(arr, i+1, j, y+1, n-1, dp);
    int opt2 = y*(arr[j]) + winesPrblm(arr, i, j-1, y+1, n-1, dp);
    dp[i][j] = max(opt1, opt2);
    return(max(opt1, opt2));
    // return(dp[0][n-1)];
}

int winesPrblmDp(int* arr, int n) {
    int** dp = new int*[n+1];
    for (int i = 0; i < n; i++) {
        dp[i] = new int [n+1];
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }

    for(int i=0; i<n-1; i++) {
        for(int j=i; j<n-1; j--) {
            dp[i][j] = arr[i]*n;
            break;
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
    
            if(i<j){
                dp[i][j] = -1;
                continue;
            } else {

                int opt1 = (i+1)*arr[i] + dp[i+1][j];
                int opt2 = (i+1)*arr[j] + dp[i][j-1];
                dp[i][j] = max(opt1, opt2);
            }
        } 
    }
    return dp[0][n-1];

}

int winesPrblmGreedy(int* arr, int n) {
    // IF Order of elements in array doesn't matter.

    sort(arr, arr+n);
    int pro = 0;
    int y = 1;
    for (int i = 0; i < n; i++) {
        pro += arr[i]*y;
        y++;
    }
    return pro;
}

int main(int argc, char const *argv[])
{
    
    int n;
    cin >> n;
    int *arr = new int[n+1];
    int** dp = new int*[n+1];
    for (int i = 0; i < n; i++)
    {
        dp[i] = new int [n+1];
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = -1;
        }      
    }
    
    
    for(int i=0; i<n; i++) cin >> arr[i];
    cout << winesPrblm(arr, 0, n-1, 1, n, dp);
    // cout << winesPrblmGreedy(arr, n);
    return 0;
}

