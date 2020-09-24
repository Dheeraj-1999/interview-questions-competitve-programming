#include<bits/stdc++.h>
using namespace std;

int maxSumWindow(int* arr, int n, int sizeWindow) {
    int maxSum, j;
    maxSum=0; j = sizeWindow;
    for(int i=0; i<sizeWindow; i++) {
        maxSum += arr[i];
    }
    for(int i=1; i<n; i++) {
        // int sum = 0;
        maxSum = max(maxSum, maxSum + arr[i+sizeWindow-1] - arr[i-1]);
        cout << maxSum << " ";
    }
    return maxSum;
}

int main(int argc, char const *argv[])
{
    
    int n, sub;
    cin >> n >> sub;
    int* arr = new int[n+1];

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    maxSumWindow(arr, n, sub);
    return 0;
}
