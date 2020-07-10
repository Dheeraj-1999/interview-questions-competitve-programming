// Given an array A of N integers, find any 3 elements in it such that A[i] < A[j] < A[k] and i < j < k. 

#include<bits/stdc++.h>
using namespace std;


void sortedSub(int* arr, int n) {
    int* smaller = new int[n+1];
    int* greater = new int[n+1];
    smaller[0] = -1;
    greater[n-1] = -1;
    bool flag = true;
    for(int i=1; i<n; i++) {
        for(int j=i-1; j>=0; j--) {
           
            if(arr[i] > arr[j]){
                smaller[i] = j;
                flag = false;
                break;
            }
        }
        if(flag == true) {
            smaller[i] = -1;
        }
    }
    
    bool flag1 = true;
    for(int i=n-2; i>=0; i--) {
        for(int j=i; j<n; j++) {
            if(arr[i] < arr[j]){
                greater[i] = j;
                flag1 = false;
                break;
            }
        }
        if(flag1 == true) {
            cout << " i" << i ;
            greater[i] = -1;
        }
    }

    for(int i=0; i<n; i++) {
       cout << arr[i] << " " << smaller[i] << " " << greater[i] << endl;
    }
}

int main(int argc, char const *argv[])
{
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int* arr = new int[n+1];
        for(int i=0; i<n; i++) {
            cin >> arr[i];
        }
        sortedSub(arr, n);  
    } 
    
    return 0;
}
