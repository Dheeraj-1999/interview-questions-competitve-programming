#include<bits/stdc++.h>
using namespace std;

int go(int* arr, int n) {
    // sort(arr, arr+n);
    int* dp = new int[n+1];
    dp[n-1] = arr[n-1];
    dp[n-2] = abs(arr[n-1] - arr[n-2]);
    for(int i=n-3; i>=0; i--) {
        for(int j=i+1; j<n; j++) {
            
        }
        int temp = abs(arr[i] - arr[i+1]);
        dp[i] = min(abs(temp - dp[i+2]), abs(arr[i] - dp[i+1]));
        // cout << temp << " " << dp[i] << endl;
    }
    for(int i=0; i<n-1; i++) cout << dp[i] << " ";
    cout << endl;
    return dp[0];
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int* arr = new int[n+1];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    go(arr, n);
}
