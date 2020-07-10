#include<bits/stdc++.h>
using namespace std;

void convertToWave(int *arr, int n){
    int i=0;
    while(i < n-1){
        cout << arr[i] << " " << arr[i+1] << " " << i << endl;
        if(arr[i] < arr[i+1])
            swap(arr[i], arr[i+1]);
        i += 2;
    }
    for(int i=0; i<n; i++) cout << arr[i] << " ";
    // Your code here
    
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int* arr = new int[n+1];
    for(int i=0; i<n; i++) cin >> arr[i];
    convertToWave(arr, n);
    return 0;
}
