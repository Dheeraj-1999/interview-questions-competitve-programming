#include<bits/stdc++.h>
using namespace std;

int knapSack(int* arr, int* value, int w, int n) {
    if(w <= 0 or n == 0) {
        return 0;
    }

    if(*arr > w) {
        return knapSack(arr+1, value+1, w, n-1);
    }
    int opt1 = *value + knapSack(arr, value, w-*arr, n); //including the value
    int opt2 = knapSack(arr+1, value+1, w, n-1);
    return(max(opt1, opt2));

}

int knapSackDp(int* arr, int* val, int kw, int n) {
    int** dp = new int*[n+1];
    for(int i=0; i<n+1; i++) {
        dp[i] = new int[kw+1]();
    }

    // for(int i=0; i<=n; i++) { //i stands for qunatity
    //     for(int w=0; w<=kw; w++) {
    //         cout << dp[i][w] << " ";
    //     }
    //     cout << endl;
    // }

    
    for(int i=0; i<=n; i++) { //i stands for qunatity
        for(int w=0; w <= kw; w++) { // j stands for weight
            if (i == 0 || w == 0) 
                dp[i][w] = 0; 
            else if (arr[i - 1] <= w)
                dp[i][w] = max((val[i-1] + dp[i][w-arr[i-1]]), (dp[i-1][w]));
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    // cout << endl;
    // for(int i=0; i<=n; i++) { //i stands for qunatity
    //     for(int w=0; w<=kw; w++) {
    //         cout << dp[i][w] << " ";
    //     }
    //     cout << endl;
    // }
    return dp[n][kw];
}


int main(int argc, char const *argv[])
{
    
    int n, w;
    cin >> n >> w;
    int* weight = new int[n+1];
    int* val = new int[n+1];
    
    for(int i=0; i<n; i++) {
        cin >> val[i];
    }
    for(int i=0; i<n; i++)
        cin >> weight[i];

    int** dp = new int*[n+1];
    for(int i=0; i<n+1; i++) {
        dp[i] = new int[n+1]();
    }
    cout << endl << knapSack(weight, val, w, n);
    return 0;
}
