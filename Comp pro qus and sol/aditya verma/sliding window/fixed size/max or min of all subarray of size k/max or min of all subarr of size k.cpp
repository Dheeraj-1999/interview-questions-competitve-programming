
// Sliding Window Maximum (Maximum of all subarrays of size k)

// Given an array and an integer K, find the maximum for each and every contiguous subarray of size k.a



#include<bits/stdc++.h>
using namespace std;

int WindowMax(int* arr, int i, int ws) {
    int maxi = INT_MIN;
    for(int k=i; k<ws+i; k++) {
        maxi = max(arr[k], maxi);
    }
    return maxi;
}   

void  maxOfAllSubsnsquare(int* arr, int n, int k) {

    // firstMax = firstWindowMax(arr, 0, k);
    for(int i=0; i<n-k+1; i++) {
        cout << WindowMax(arr, i, k) << " ";
    }

}

void maxOfAllSubOptimized(int* arr, int n, int k) {
    deque<int> q;
    //  cout <<"he " << q.front() << " ";  
    
    // =============== for first k elements ==================
    for(int i=0; i<k; i++) {
        while( (!q.empty()) and arr[q.back()] <= arr[i] ) {
            q.pop_back();
        }
        q.push_back(i);
        // cout << q.front() << " ";
    }


//  =================== for next K element ================
    // cout << q.front() << " ";
    for(int i=k; i<n; i++) {
        cout << arr[q.front()] << " ";

        while(q.front() <= (i-k) and !(q.empty()) ) {
           q.pop_front();
        }
        while((!q.empty()) and arr[q.back()] <= arr[i] ) {
            q.pop_back();
        }
        q.push_back(i);
    }
    cout << arr[q.front()] << " ";
}


void minOfAllSubOptimized(int* arr, int n, int k) {
    deque<int> q;
    //  cout <<"he " << q.front() << " ";  
    
    // =============== for first k elements ==================
    for(int i=0; i<k; i++) {
        while( (!q.empty()) and arr[q.back()] >= arr[i] ) {
            q.pop_back();
        }
        q.push_back(i);
        // cout << q.front() << " ";
    }


//  =================== for next K element ================
    // cout << q.front() << " ";
    for(int i=k; i<n; i++) {
        cout << arr[q.front()] << " ";

        //conditon for : keep only those values which are part of window size
        while(q.front() <= (i-k) and !(q.empty()) ) { 
           q.pop_front();
        }
        while((!q.empty()) and arr[q.back()] >= arr[i] ) {
            q.pop_back();
        }
        q.push_back(i);
    }
    cout << arr[q.front()] << " ";
}

int main(int argc, char const *argv[])
{
    
    int n, k;
    cin >> n >> k;

    int* arr = new int[n+1];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    minOfAllSubOptimized(arr, n, k);    
    return 0;
}