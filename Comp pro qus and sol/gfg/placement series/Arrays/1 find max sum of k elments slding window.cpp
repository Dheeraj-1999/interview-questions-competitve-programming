#include<bits/stdc++.h>
using namespace std;

int slidWindowMax(int* arr, int n, int k) {
    int sm = 0;
    
    for(int i=1; i<=k; i++)
        sm += arr[i];
    int maxSm = sm;
    for(int i=1; i+k<=n; i++) {
        // int temp = 0;
        // temp = sm;
        sm = sm - arr[i] + arr[i+k];
        maxSm = max(maxSm, sm);
        cout << maxSm << " ";
    }
    return maxSm;
}

int main(int argc, char const *argv[])
{
    
    int n, k;
    cin >> n >> k;
    int* arr = new int[n+1];
    for(int i=1; i<=n; i++) {
        cin >>arr[i];
    }
    slidWindowMax(arr, n, k);
    return 0;
}
