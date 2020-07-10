#include<bits/stdc++.h>
using namespace std;


// Another Approach (Swap elements in Array) :
// 1) Iterate through elements in array
// 2) If arr[i] >= 0 && arr[i] != i, put arr[i] at i ( swap arr[i] with arr[arr[i]])


// Approach 2:

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    
    int* arr1 = new int[n+1];
    // int* arr2 = new int[n+1];

    for(int i=0; i<n; i++) {
        cin >> arr1[i];
    }
    map<int, int> m;
    for(int i=0; i<n; i++) {
        if(arr1[i] != -1 ) {
            m[arr1[i]] = 1;
        }
    }
    for(int i=0; i<n; i++) {
        // cout << arr1[i] << " " << i << " ";
        if(m[i] == 1) 
            arr1[i] = i;
        else arr1[i] = -1;
        // cout << arr1[i] << " " << i << endl;
    }  
    for(int i=0; i<n; i++) {
        cout << arr1[i] << " ";
    }     
    return 0;
}