#include<bits/stdc++.h>
using namespace std;

int longIncSub(int* arr, int n) {
    int*dp =new int[n]();

    dp[n] = 0;
    dp[n-1] = 1;

    for(int i=n-2; i>=0; i--) {
        dp[i] = 1;
        for(int j=i; j<n; j++) {
            if(arr[i] < arr[j]) { //part of lis
                dp[i] = max(dp[i], 1+dp[j]);
            }
        }
    }
    int maxi =INT_MIN;
    for(int i=0; i<n; i++) maxi = max(maxi, dp[i]); 
    for(int i=0; i<n; i++) cout << dp[i] << " ";
        cout << endl;
    // cout << endl;
    return maxi;
}

// OTHER asolution exist nlogn on hackerrank also

int LICnlogn(int* array, int len) { 
    
    // Refer For Help:
    // https://www.youtube.com/watch?v=TocJOW6vx_I&t=176s
    
    
    int sz = 0;
    int* c = new int[len+1];
    int*dp = new int[len];
    c[0] = array[0]; /*at this point, the minimum value of the last element of the size 1 increasing sequence must be array[0]*/
    dp[0] = 1;
    for( int i = 1; i < len; i++ ) {
        if( array[i] < c[0] ) {
            c[0] = array[i]; /*you have to update the minimum value right now*/
            dp[i] = 1;
        }
        else if(array[i] > c[sz] ) {
            c[sz+1] = array[i];
            sz++;
            dp[i] = sz+1;
        }
        else {
            /*you want to find k so that c[k-1]<array[i]<c[k]*/
            int k = lower_bound( c, c+sz, array[i] ) - c; 
            cout << k << " " << c[k] << " " << array[i] << endl;
            c[k] = array[i];
            dp[i] = k+1;
        }
        for(int pi=0; pi<len; pi++) cout << c[pi] << " ";
        cout << endl;

    }
    cout << endl;
    for(int i=0; i<len; i++) cout << dp[i] << " ";
    cout << endl;

}

int main(){
    int n;
    cin >> n;
     int* input = new int[n];
     for(int i=0; i<n; i++) cin >> input[i];

    //  cout << longIncSub(input, n) << " " << endl;
     cout << LICnlogn(input, n) << " ";

}