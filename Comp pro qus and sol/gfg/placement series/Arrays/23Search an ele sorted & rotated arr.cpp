#include<bits/stdc++.h>
using namespace std;

int findPivot(int* arr, int n) {
    for(int i=0; i<n-1; i++) {
        if(arr[i] > arr[i+1]) {
            cout << "pivot " << arr[i+1] << endl;
            return i+1;
        }
    }
    return -1;
}

void sortedRotated(int* arr, int n, int key) {
    int pivot = findPivot(arr, n);
    int pos;
    if(key > arr[0]) {
        pos = lower_bound(arr, arr+pivot-1, key) - arr;
    } else {
        pos = lower_bound(arr+pivot, arr+n, key) - arr;   
    }
    cout << pos;
    
}

int main(int argc, char const *argv[])
{
    
    int n, k;
    cin >> n >> k;
    int* arr = new int[n+1];
    for(int i=0; i<n; i++) {
        cin >>arr[i];
    }
    sortedRotated(arr, n, k);
    return 0;
}