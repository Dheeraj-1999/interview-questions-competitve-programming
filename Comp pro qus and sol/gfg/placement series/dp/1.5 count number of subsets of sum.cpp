#include<bits/stdc++.h>
using namespace std;

static int counts = 0;
int numSubsets(int* arr, int n, int sum) {
    if(sum == 0) {
        // counts += 1;
        return counts+1;
    }
    if(n == 0) {
        if(sum != 0) 
            return 0;
        return counts+1;
    }
    int opt1 = numSubsets(arr+1, n-1, sum-*arr);
    int opt2 = numSubsets(arr+1, n-1, sum);
    return opt1 + opt2;
}

int numSubsetsDp(int* arr, int n, int sum) {
    int dp[n+1][sum+1];

    // memset(dp, -1, sizeof(dp));
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<sum+1; j++) {
            if( i == 0) dp[i][j] = 0;
            if(j == 0) dp[i][j] = 1;
        }
    }
    
    for(int i=1; i<=n; i++) {
        for(int j=1; j<=sum; j++) {
            if(arr[i-1] <= j)
                dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
            else
                dp[i][j] = dp[i-1][j];
        }
    }
    for(int i=0; i<n; i++) {
        for(int j=0; j<sum; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    return dp[n][sum];
}

int main(int argc, char const *argv[])
{
    int n, sum;
    cin >> n >> sum;
    int* set = new int[n+1];
    for(int i=0; i<n; i++)
        cin >> set[i]; 
    cout << numSubsetsDp(set, n, sum);   
    return 0;
}
