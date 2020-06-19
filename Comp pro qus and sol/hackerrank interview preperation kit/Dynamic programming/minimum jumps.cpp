// Given an array of integers where each element represents the max number of steps that can be made forward from that element. 
// Write a function to return the minimum number of jumps to reach the end of the array (starting from the first element). 
// If an element is 0, then cannot move through that element.


#include<bits/stdc++.h>
using namespace std;
int jumps=0;

int minJumps(int* arr, int si, int n, int* dp) {
    if(si == n) return 0;

    int mini = INT_MAX;
    if(dp[si] > 0) return dp[si] ;
    for(int i=si+1; i<=n; i++) {
        // cout << i << " " << (si+arr[i]) << endl;
        if(i < (si+arr[si]+1)) {
            jumps = minJumps(arr, i, n, dp);
            // cout << jumps << " " << mini << " ";
            // if (jumps + 1 < mini) {
            //     mini = jumps+1;
            // }
            mini = min(jumps+1, mini);
            dp[i] = mini;
            // cout << mini << " " << endl;
        }
    }
    // if(dp[i] > 0) return dp[i];

    // // for(int k=1; k<=arr[i] and k < n; k++) {
    // //     jumps = 1+ minJumps(arr, i+k, n, dp);
    // //     cout << jumps << " ";
    // //     mini = min(mini, jumps);
    // // }
    // minJumps(arr, i, i+arr[i], dp)
    return mini;
}


int minJumpsDp(int* arr, int n) {



    int* dp = new int[n+1]();
    
    if (n == 0 || arr[0] == 0) 
        return INT_MAX;

    
    dp[0] = 1;
    for(int i=1; i<n; i++) {
        dp[i] = INT_MAX;
        for(int j=0; j<i; j++) {
            if(i <= j + arr[j] && arr[j] != INT_MAX){
                dp[i] = min(dp[i], dp[j]+1);
                break;
            }
        }
    }
    for(int i=0; i<n; i++)
        cout << dp[i] << " ";
}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];
    int* dp = new int[n+1]();
    for(int i=0; i<n; i++)
        cin >> arr[i];
    // cout << minJumps(arr, 0, n, dp) << endl; 
    minJumpsDp(arr, n);
    // for(int i=0; i<n; i++)
    //     cout << dp[i] << " ";   
}