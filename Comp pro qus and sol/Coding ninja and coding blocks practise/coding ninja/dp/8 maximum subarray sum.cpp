#include<bits/stdc++.h>
using namespace std;

void maxSubArray(int* arr, int n) {
    int* dp = new int[n+1]();
    int bestTillNow = 0;
    // int currMax = INT_MIN;

    dp[0] = max(1, arr[0]);
    for(int i=1; i<n; i++) {
        dp[i] = dp[i-1] + arr[i];
        if(dp[i] < 0) dp[i] = 0;
        if(bestTillNow < dp[i]) {
            bestTillNow = dp[i];
            cout << bestTillNow << " ";
        }
    }
    cout << endl;
    for(int i=0; i<n; i++) {
        cout << dp[i] << " ";
    }
}

// KADANE ALGPRITHM

void maxSubArrayOptimized(int* arr, int n) {
    // int* dp = new int[n+1]();
    int bestTillNow = 0;
    int currMax = INT_MIN;

    currMax = max(1, arr[0]);
    for(int i=1; i<n; i++) {
        currMax = currMax + arr[i];
        if(currMax < 0) currMax = 0;
        if(bestTillNow < currMax) {
            bestTillNow = currMax;
            cout << bestTillNow << " ";
        }
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    
    int n;
    cin >> n;
    int* arr = new int[n];
    for(int i=0; i < n; i++) {
        cin >> arr[i];
    }
    maxSubArrayOptimized(arr, n);
    return 0;
}
