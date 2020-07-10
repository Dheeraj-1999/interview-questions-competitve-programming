#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    
    int t, n;
    cin >> n;
    int* arr = new int[n+1];
    int* dp = new int[n+1]();
    for(int i=0; i<n; i++){  
        cin >> arr[i];
    }
    dp[0] = arr[0];
    for(int i=1; i<n; i++){  
        dp[i] = dp[i-1] + arr[i];  
    }
    cin >> t;
    while(t--) {
        int st, en;
        cin >> st >> en;
        if(st == 0) {
            cout << dp[en] << endl;
            continue;
        }
        cout << dp[en] - dp[st-1];
    }
    return 0;
}
