#include<bits/stdc++.h>
using namespace std;

int rodMaxProfitRec(int* length, int* price, int L, int n) {
    if(L == 0 or n <= 0) {
        return 0;
    }
    if(*length > L) {
        return rodMaxProfitRec(length+1, price+1, L, n-1);
    }
    int opt1 = *price + rodMaxProfitRec(length, price, L-*length, n);
    int opt2 = rodMaxProfitRec(length+1, price+1, L, n-1);
    return(max(opt1, opt2));
}
int dp[10][10];
int rodMaxProfitDp(int* length, int* price, int L, int n) {
    for(int i=0; i<=n; i++) {
        for(int j=0; j<=L; j++) {
            if(i == 0 or  j == 0) {
                dp[i][j] = 0;
            }
            else if(length[i-1] <= j) {
                dp[i][j] = max(price[i-1] + dp[i][j-length[i-1]], dp[i-1][j]);
            }
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][L];
}

int main(int argc, char const *argv[])
{
    int n, L;
    cin >> n >> L;
    int* length = new int[n+1];
    int* price = new int[n+1];

    for(int i=1; i<n+1; i++){ 
        cin >> price[i];
        length[i] = i;    
    }

    cout << rodMaxProfitDp(length, price, L, n);
    return 0;
}
