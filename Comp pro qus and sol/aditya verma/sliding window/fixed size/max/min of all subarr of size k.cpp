
// Sliding Window Maximum (Maximum of all subarrays of size k)

// Given an array and an integer K, find the maximum for each and every contiguous subarray of size k.a



#include<bits/stdc++.h>
using namespace std;

int firstWindowMax(int* arr, int i, int k) {
    int maxi = INT_MIN;
    for(k=i; i<k+i; i++) {
        maxi = max(arr[i], maxi);
    }
    return maxi;
}   

void  maxOfAllSubs(int* arr, int n, int k) {

    int p1, p2;
    int firstMax;
    firstMax = firstWindowMax(arr, 0, k);
    p1 = 0;
    p2 = k;
    for(int i=0; i<n-k; i++) {
        firstWindowMax(arr, i, k);
    }

}

int main(int argc, char const *argv[])
{
    
    int n, k;
    cin >> n >> k;

    int* arr = new int[n+1];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    maxOfAllSubs(arr, n, k);    
    return 0;
}
