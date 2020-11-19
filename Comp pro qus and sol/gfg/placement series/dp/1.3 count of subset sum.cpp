// 8
// 479 758 315 472 730 101 460 619
#include<bits/stdc++.h>
using namespace std;

bool subsetSumDp(int* arr, int sum, int n) {
    int dp[sum+1][n+1];
    for(int i=0; i<n+1; i++) {
        for(int j=0; j<sum; j++) {
            dp[i][j] = -1;
            if( i == 0) dp[i][j] = 0;
            if(j == 0) dp[i][j] = 1;
        }
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++) {
            if(arr[i-1] <= j) {
                int opt1 = dp[i-1][j-arr[i-1]]; //include the number
                int opt2 = dp[i-1][j]; // exclude the number
                dp[i][j] = opt1 + opt2;
            } else {
                dp[i][j] = dp[i-1][j];
            }  
        }
    }

    for(int i=0; i<n; i++){
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
    int* arr = new int[n+1];
    for(int i=0; i<n; i++){
        cin >> arr[i];
        // sum += arr[i];
    }
    
    cout << subsetSumDp(arr, sum, n);
    return 0;
}