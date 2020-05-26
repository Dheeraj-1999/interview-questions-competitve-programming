#include<bits/stdc++.h>
using namespace std;

int minStepsToOne(int n, int* dp) {
    int c = INT_MAX;
    int b = INT_MAX;
    int a = INT_MAX;
    
    if(n <= 1) {
        // cout << a << " " << b  << " " << c << endl;
        // cout << n << " " << min(a, min(b, c))+1 << endl;
        return 0;
    }

    // cout << a << " " << b  << " " << c << endl;
    // cout << n << " " << min(a, min(b, c))+1 << endl;
    if(dp[n] > 0) return dp[n];
    if(n%3 == 0)
        a = minStepsToOne(n/3, dp);
    if(n%2 == 0){
        b = minStepsToOne(n/2, dp);
    }
    c =  minStepsToOne(n-1, dp);

    int ans = min(a, min(b, c))+1;
    dp[n] = ans;
    return dp[n];

}


int minStepsToOneDp(int n) {
    int* dp = new int[n+1];
    dp[1] = 0;
    for(int i=2; i<n+1; i++) {
        int a = INT_MAX, b = INT_MAX, c = INT_MAX;
        if(i%3 == 0){
            a = dp[i/3];
        } else if(i%2 == 0) 
            b = dp[i/2];
        c = dp[i-1];
        dp[i] = min(a, min(b,c))+1;
    }
    // for(int i=1; i<n+1; i++){
    //     cout << dp[i] << " ";
    // } 
    // cout << endl;
    return dp[n];
}

int main(int argc, char const *argv[])
{
    
    int n;
    cin >> n;
    int* dp = new int[n+1]();
    cout << minStepsToOne(n, dp) << endl;
    cout << minStepsToOneDp(n);

    return 0;
}
