// given an array and a sum as input
// just check if two subsets of having same sum is present in array.
// ......................................
// tutorial....................
// https://www.youtube.com/watch?v=UmMh7xp07kY&list=PL_z_8CaSLPWekqhdCPmFohncHwz8TY2Go&index=8
// .......................
// ......................

#include<bits/stdc++.h>
using namespace std;

bool subsetSumDp(int* arr, int sum, int n) {
    int** dp = new int* [n+1]; //size sum x n
    for(int i=0; i<n+1; i++) {
        dp[i] = new int[sum+1];
        for(int j=0; j<sum+1; j++) {
            dp[i][j] = -1;
            if( i == 0) dp[i][j] = 0;
            if(j == 0) dp[i][j] = 1;
        }
    }

    // cout << endl;
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<sum; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

// check if sum/2  sunbset exist in array
    for(int i=1; i<=n; i++){
        for(int j=1; j<=sum; j++) {
            if(arr[i-1] <= sum) {
                int opt1 = dp[i-1][j-arr[i-1]]; //include the number
                int opt2 = dp[i-1][j]; // exclude the number
                dp[i][j] = opt1 or opt2;
            } else {
                dp[i][j] = dp[i-1][j];
            }  
        }
    }
    // return dp[n-1][sum-1];
    cout << endl;
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<sum; j++) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << dp[n-1][sum-1] << " " << dp[n][sum];
}

int main(int argc, char const *argv[])
{
    int n,sum = 0;
    cin >> n;
    int* arr = new int[n+1];
    for(int i=0; i<n; i++){
        cin >> arr[i];
        sum += arr[i];
    }
    // If sum is odd then we can't divide the array into subsets of equal sum
    if(sum % 2 != 0){
        cout << "False";
        return 0;
    }

    // else we will check if subset of sum = sum/2 exist in an array
    // if it exist then another subset will definately exist due to equal sums of both subsets.............
    cout << subsetSumDp(arr, sum/2, n);
    return 0;
}