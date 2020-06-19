#include<bits/stdc++.h>
using namespace std;

void windowMaxBrute(deque<int> deq, int* arr, int k, int n) {
    // Brute Force
    for(int i=0; i<k; i++) deq.push_back(arr[i]);
    for(int i=0; i+k<=n; i++) {
        int maxi = INT_MIN;
        for(auto it = deq.begin(); it != deq.end(); it++) {
            maxi = max(maxi, *it);
        }
        cout << maxi << " ";
        deq.pop_front();
        deq.push_back(arr[i+k]);
    }
}

void windowMax(deque<int> Q, int* a, int k, int n) {

// PROCESS FIRST K ELEMENTS

    int i;
    for(i=0;i<k;i++){
        
        while(!Q.empty() &&a[i]>a[Q.back()]){
            Q.pop_back();
        }
        Q.push_back(i);
        
    }
    //Process the remaining elements 
    for(;i<n;i++){
        cout<<a[Q.front()]<<" ";
        
        //1. Remove the elements which are not the part of the window(Contraction)
        while((!Q.empty() && (Q.front()<=i-k))){
            Q.pop_front();
        }
        
        //2. Remove the elements which are not useful and are in window
        while(!Q.empty() && a[i]>=a[Q.back()]){
            Q.pop_back();   
        }
        
        //3. Add the new elements(Expansion)
        Q.push_back(i);
    }
    
    cout<<a[Q.front()]<<endl;
}

int main(int argc, char const *argv[])
{
    
    int n, k;
    cin >> n >> k; 
    int* arr = new int[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    deque<int> deq;
    windowMax(deq, arr, k, n);
    return 0;
}
