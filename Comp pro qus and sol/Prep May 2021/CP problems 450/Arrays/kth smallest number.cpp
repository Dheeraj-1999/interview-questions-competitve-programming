#include<bits/stdc++.h>
using namespace std;

int findKthMin(int* arr, int n, int k) {
    sort(arr, arr+n);
    cout << arr[k-1];

}
int main(int argc, char const *argv[])
{
     int n, k;
    cin >> n >> k;
    int* arr = new int[n];

    for(int i=0; i<n; i++) {
        cin >>arr[i];
    }
    findKthMin(arr, n, k);
    return 0;
}
