#include<bits/stdc++.h>
using namespace std;

int stickler(int* houses, int n) {
    int* dp = new int[n+1]();
    dp[0] = houses[0];
    dp[1] = houses[1];
    for(int i=2; i<n; i++) {
        dp[i] = max(dp[i-1], dp[i-2] + houses[i]);
    }
    // for(int i=0; i<n; i++)
    //     cout << dp[i] << " ";
    return dp[n-1];

}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int* arr = new int[n+1];

        for(int i=0; i<n; i++) 
            cin >> arr[i];
        cout << stickler(arr, n);
    }
}
