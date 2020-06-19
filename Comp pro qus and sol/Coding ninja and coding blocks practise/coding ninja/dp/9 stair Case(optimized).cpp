#include<bits/stdc++.h>
using namespace std;

int stairCaseDp(int n, int k) {
    int* dp = new int[n];
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
    for(int i=3; i<n; i++) {
        for(int j=1; j<=k; j++) {
            dp[i] += dp[i-j];
        }
    }
    for(int i=0; i<n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
    return dp[n-1];
}


int stairCaseDpOpt(int n, int k) {
    int* dp = new int[n+1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    for(int i=4; i<=n; i++) {
        // no need to travel in j direction(backward)
        // dp[i] is just = (dp[i-1] - dp[i-k-1]) + dp[i-1];
        dp[i] = 2*dp[i-1] - dp[i-k-1]; //here is the optimization
    }
    for(int i=1; i<=n; i++) {
        cout << dp[i] << " ";
    }
    cout << endl;
    return dp[n];
}

int main(int argc, char const *argv[])
{
    
    int n, k;
    cin >> n >> k;
    cout << endl << stairCaseDp(n, k);
    cout << endl << stairCaseDpOpt(n, k);
    return 0;
}
