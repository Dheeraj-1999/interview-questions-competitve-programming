// You are given an array of positive integers as input. 
// Write a code to return the length of the largest such subsequence 
// in which the values are arranged first in strictly ascending order 
// and then in strictly descending order.
// Such a subsequence is known as bitonic subsequence. 
// A purely increasing or purely decreasing subsequence will also be considered as a bitonic sequence with the other part empty.

// Note that the elements in bitonic subsequence need not be consecutive in the given array but the order should remain same.
// Input Format:

// Line 1 : A positive Integer N, i.e., the size of array
// Line 2 : N space-separated integers as elements of the array 

// Output Format:

// Length of Largest Bitonic subsequence

// Input Constraints:

// 1<= N <= 100000

// Sample Input 1:

// 6
// 15 20 20 6 4 2

// Sample Output 1:

// 5

// Sample Output 1 Explanation:

// Here, longest Bitonic subsequence is {15, 20, 6, 4, 2} which has length = 5.



#include<bits/stdc++.h>
using namespace std;

int bitLongestInc(int* arr, int n, int i, int* lis) {
    // int* dp = new int[n+1]();
    for (int i = 0; i < n; i++) 
      lis[i] = 1;
    for (int i = 1; i < n; i++) 
      for (int j = 0; j < i; j++) 
         if (arr[i] > arr[j] && lis[i] < lis[j] + 1) 
            lis[i] = lis[j] + 1; 
    for(int i=0; i<n; i++) cout << lis[i] << " ";
}

int bitLongestDec(int* arr, int n, int i, int *dp) {
    // int* dp = new int[n+1];
    dp[0] = 1;
    for(int i=1; i<n; i++) {
        dp[i] = 1;
        for(int j=0; j<i; j++) {
            if(arr[j] > arr[i]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    for(int i=0; i<n; i++) cout << dp[i] << " ";
}

int main(int argc, char const *argv[])
{
    
    int n;
    cin >> n;
    int* arr = new int[n];
    int* arr2 = new int[n];
    int*dp = new int[n+1]();
    int*dp1 = new int[n+1]();
    for(int i=0; i < n; i++) {
        cin >> arr[i];
        arr2[i] = arr[i];
    }

    bitLongestInc(arr, n, 0, dp);
    cout << endl;
    bitLongestDec(arr2, n, 0, dp1);

    int max = dp[0] + dp1[0] - 1; 
    for (int i = 1; i < n; i++) 
        if (dp[i] + dp1[i] - 1 > max) 
            max = dp[i] + dp1[i] - 1; 
    cout << max; 
    return 0;
}

