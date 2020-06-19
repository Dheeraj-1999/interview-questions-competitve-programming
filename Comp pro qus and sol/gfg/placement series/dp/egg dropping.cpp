#include<bits/stdc++.h>
using namespace std;
/*
int eggFloor(int e, int f) {
    if(f == 1 or f == 0) {
        return f;
    }
    if(e == 1 ){
        return f;
    }
    
    int count = INT_MAX;
    for(int k=1; k<=f; k++) {
        int worst_case = max(eggFloor(e-1, k-1), eggFloor(e, f-k));// worst case will be maximum floor of building
        count = min(count, worst_case); // minimum number of attempts 
        // cout << count << " ";
        cout << count << " " << worst_case << " " << e << " " << f << endl;
    }
    return count+1;
}
*/

int static dp[11][51]; 
// memset(dp, -1, sizeof(dp)); 
int eggFloorMem(int e, int f) {
    if(f == 1 or f == 0) {
        return f;
    }
    if(e == 1 ){
        return f;
    }
    
    int count = INT_MAX;

    if(dp[e][f] > -1) {
        return dp[e][f];
    }

    for(int k=1; k<=f; k++) {
        if(dp[e-1][f-1] > -1) {
            return dp[e-1][f-1];
        }
        if(dp[e][f-k] > -1) {
            return dp[e][f-k];
        }
        int worst_case = max(eggFloorMem(e-1, k-1), eggFloorMem(e, f-k));// worst case will be maximum floor of building
        count = min(count, worst_case); // minimum number of attempts 
        dp[e][f] = count+1;
    }
    return count+1;
}

// int static dp[11][51];  
int eggFloorMemOpt(int e, int f) {
    if(f == 1 or f == 0) {
        return f;
    }
    if(e == 1 ){
        return f;
    }
    
    int count = INT_MAX;

    if(dp[e][f] > -1) {
        return dp[e][f];
    }

    for(int k=1; k<=f; k++) {
        int low, high;
        if(dp[e-1][f-1] > -1) {
            low =  dp[e-1][f-1];
        } else {
            low = eggFloorMem(e-1, k-1);
        }
        if(dp[e][f-k] > -1) {
            high = dp[e][f-k];
        } else {
            high = eggFloorMem(e, f-k);
        }
        int worst_case = max(low, high);// worst case will be maximum floor of building
        count = min(count, worst_case); // minimum number of attempts 
        dp[e][f] = count+1;
    }
    return count+1;
}

int main(int argc, char const *argv[])
{
    
    int n, f;
    cin >> n >> f;
    // cout << endl << eggFloor(n, f);

    // int** dp = new int* [n+1];
    for(int i=0; i<n+1; i++) {
        // dp[i] = new int[f+1]();
        for(int j=0; j<f+1; j++) {
            dp[i][j] = -1;
        }
    }
    cout << endl << eggFloorMemOpt(n, f);

    
    return 0;
}
