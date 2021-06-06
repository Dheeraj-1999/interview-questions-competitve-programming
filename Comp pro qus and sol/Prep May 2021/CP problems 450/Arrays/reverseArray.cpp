#include<bits/stdc++.h>
using namespace std;

int* reverseArray(int* arr, int n) {
    for(int i=0; i<n/2; i++) {
        swap(arr[i], arr[n-i-1]);
        // cout << arr[i] << " " << arr[n-i-1] << endl;
    }
    return arr;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int* arr = new int[n];

    for(int i=0; i<n; i++) {
        cin >>arr[i];
    }
    int* op = reverseArray(arr, n);
    for(int i=0; i<n; i++) {
        cout << op[i] << " ";
    }
    return 0;
}
