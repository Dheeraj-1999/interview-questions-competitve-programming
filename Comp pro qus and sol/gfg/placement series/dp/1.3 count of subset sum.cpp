// 8
// 479 758 315 472 730 101 460 619
#include<bits/stdc++.h>
using namespace std;

bool subsetSumDp(int* arr, int sum, int n) {
    int** dp = new int* [n+1]; //size sum x n
    for(int i=0; i<n+1; i++) {
        dp[i] = new int[sum+1]();
        for(int j=0; j<n; j++) {
            dp[i][j] = -1;
            if( i == 0) dp[i][j] = 0;
            if(j == 0) dp[i][j] = 1;
        }
    }

// check if sum/2  sunbset exist in array
    for(int i=1; i<n; i++){
        for(int j=1; j<sum; j++) {
            if(arr[i-1] <= sum) {
                int opt1 = dp[i-1][j-arr[i-1]]; //include the number
                int opt2 = dp[i-1][j]; // exclude the number
                dp[i][j] = opt1 or opt2;
            } else {
                dp[i][j] = dp[i-1][j];
            }  
        }
    }
    return dp[n-1][sum-1];
}



bool findPartition(int arr[], int n) {
    int sum = 0;
    for(int i=0; i<n; i++){
        sum += arr[i];
    }
    // If sum is odd then we can't divide the array into subsets of equal sum
    if(sum % 2 != 0){
        // cout << "False";
        return 0;
    }

    return subsetSumDp(arr, sum/2, n);
    // code here
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int* arr = new int[n+1];
    for(int i=0; i<n; i++){
        cin >> arr[i];
        // sum += arr[i];
    }
    // If sum is odd then we can't divide the array into subsets of equal sum
    if(findPartition(arr, n)){
        cout << "true";
        return 0;
    }
    cout << "false";

    // else we will check if subset of sum = sum/2 exist in an array
    // if it exist then another subset will definately exist due to equal sums of both subsets.............
    // cout << subsetSumDp(arr, sum/2, n);
    return 0;
}