#include<bits/stdc++.h>
using namespace std;

int knapSack(int* arr, int w, int n, int* val) {
    if(n ==0 or w <=0 ) {
        // cout << endl << " weight " << w << endl;
        return 0;
    }

    if(arr[0] > w)
    	return knapSack(arr+1, w, n-1, val+1);
    
    // cout << "ans" << ans << "ansEnd" << endl;
    int opt1 = val[0] + knapSack(arr+1, w-arr[0], n-1, val+1); //include the number
    // cout << w  << " "<< n  << endl;
    int opt2 = knapSack(arr+1, w, n-1, val+1); // exclude the number
    // cout << w  << " "<< n  << endl;
    return(max(opt1, opt2));

}

int knapSackMem(int* arr, int w, int n, int* val, int** dp, int i) {
    if(n ==i or w <=0 ) {
        // cout << endl << " weight " << w << endl;
        return 0;
    }

    if(arr[i] > w)
    	return knapSackMem(arr, w, n, val+1, dp, i+1);
    
    // cout << "ans" << ans << "ansEnd" << endl;
    if(dp[i][w] > 0) {
        return dp[i][w];
    }

    int opt1 = val[0] + knapSackMem(arr, w-arr[i], n, val+1, dp, i+1); //include the number
    // cout << w  << " "<< n  << endl;
    int opt2 = knapSackMem(arr, w, n, val+1, dp, i+1); // exclude the number
    // cout << w  << " "<< n  << endl;
    dp[i][w] = max(opt1, opt2);
    return(max(opt1, opt2));

}

int knapSackDp(int* arr, int kw, int n, int* val) {
    int** dp = new int*[n+1];
    for(int i=0; i<n+1; i++) {
        dp[i] = new int[kw+1]();
    }

    for(int i=0; i<=n; i++) { //i stands for qunatity
        for(int w=0; w<=kw; w++) {
            cout << dp[i][w] << " ";
        }
        cout << endl;
    }

    
    for(int i=0; i<=n; i++) { //i stands for qunatity
        for(int w=0; w <= kw; w++) { // j stands for weight
            if (i == 0 || w == 0) 
                dp[i][w] = 0; 
            else if (arr[i - 1] <= w)
                dp[i][w] = max((val[i-1] + dp[i-1][w-arr[i-1]]), (dp[i-1][w]));
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    cout << endl;
    for(int i=0; i<=n; i++) { //i stands for qunatity
        for(int w=0; w<=kw; w++) {
            cout << dp[i][w] << " ";
        }
        cout << endl;
    }
    return dp[n][kw];
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;

    while(t--) {
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
        cout << endl << knapSackDp(weight, w, n, val);
    }
    return 0;
}
