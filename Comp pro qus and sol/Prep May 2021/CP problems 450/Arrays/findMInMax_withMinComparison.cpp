#include<bits/stdc++.h>
using namespace std;

void findMinMax(int* arr, int n) {
    int p1 = -1;
    int min = INT16_MAX;
    int max = INT16_MIN;
    for(int i=0; i<n; i++) {
        if(arr[i] < min) {
            min = arr[i];
        }
        if(arr[i] > max) {
            max = arr[i]; 
        }
    }
    cout << min << " " <<max;
}

int main(int argc, char const *argv[])
{
     int n;
    cin >> n;
    int* arr = new int[n];

    for(int i=0; i<n; i++) {
        cin >>arr[i];
    }
    findMinMax(arr, n);
    return 0;
}
