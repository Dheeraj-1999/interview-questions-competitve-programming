#include<bits/stdc++.h>
using namespace std;

// static int counts = 0;
int mini =INT_MAX;
int minSubsetDiff(int* arr, int n) {
    if(n == 0) {
        return arr[0];
    }
    int opt1 = *arr + minSubsetDiff(arr+1, n-1);
    int opt2 = minSubsetDiff(arr+1, n-1);
    return min(mini, abs(opt1-opt2));
}
// subset diff will lie between the range of 0 to total sum of array.
int minSubsetDiff2(int* arr, int n, int sumTotal, int sumCal) {
    if(n == 0) {
        return abs(sumTotal - sumCal);
    }
    int opt1 = *arr + minSubsetDiff2(arr+1, n-1, sumTotal, sumCal - *arr); //including
    int opt2 = minSubsetDiff2(arr+1, n-1, sumTotal, sumCal);
    return min(opt1, opt2);
}


int minSubsetDiffDp(int* arr, int n, int sum) {
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
    int n, sumTotal;
    cin >> n;
    int* set = new int[n+1];
    for(int i=0; i<n; i++){
        cin >> set[i]; 
        sumTotal += set[i];
    }
    cout << minSubsetDiff2(set, n, sumTotal, sumTotal);   
    return 0;
}
