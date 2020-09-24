#include<bits/stdc++.h>
using namespace std;

int rangeSum(int* arr, int n) {
    int l;
    int r, sum = 0;
    cin >> l >> r;
    for(int i=l-1; i<r; i++) {
        sum += arr[i];
    }
    return(sum);
}

int main(int argc, char const *argv[])
{
    
    int n;
    cin >> n;
    int* arr = new int[n+1];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    
    int nQueries;
    cin >> nQueries;
    while(nQueries--)
        cout << rangeSum(arr, n) << endl;
    return 0;
}
