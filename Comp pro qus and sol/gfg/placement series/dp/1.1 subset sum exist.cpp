// given an array and a sum as input
// just check if subset is presentin array which give sum  equal to 'sum' input

#include<bits/stdc++.h>
using namespace std;

bool subsetSum(int* arr, int sum, int n) {
    if(n == 0){
        if(sum != 0) 
            return false;
        return true;
    }
    if(sum == 0)
        return true;
    
    bool opt1 = subsetSum(arr+1, sum-*arr, n-1); //include
    bool opt2 = subsetSum(arr+1, sum, n-1); //exclude
    return(opt1 or opt2);
}

bool subsetSumDp(int* arr, int sum, int n) {
    int** dp = new int* [n+1]; //size sum x n
    for(int i=0; i<n+1; i++) {
        dp[i] = new int[sum+1];
        for(int j=0; j<n; j++) {
            dp[i][j] = -1;
            if( i == 0) dp[i][j] = 0;
            if(j == 0) dp[i][j] = 1;
        }
    }

    for(int i=1; i<n; i++) {
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

    for(int i=0; i<n; i++) {
        for(int j=0; j<sum; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

}


int main(int argc, char const *argv[])
{
    int n,sum;
    cin >> n >> sum;
    int* arr = new int[n+1];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    cout << subsetSumDp(arr, sum, n);
    return 0;
}
