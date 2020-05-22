#include<bits/stdc++.h>
using namespace std;

int minJumps(int* arr, int n) {
    if(n == 0) return 0;

    for(int i=1; i<*arr; i++) {
        int maxi = arr[0];
        maxi = max(maxi, arr[i]);
    }

}

int main() {
    int n;
    cin >> n;

    int* arr = new int[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    minJumps(arr, n);
}