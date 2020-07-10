#include<bits/stdc++.h>
using namespace std;

vector<long long> reverseInGroups(vector<int> arr, int n, int k){
    // if(k > n) k=n;
    // reverse(mv.begin()+0, mv.begin()+k);
    
    // while(k < n) {
    //     int i = k;
    //     reverse(mv.begin()+i, mv.begin()+k);
    // }
    // return mv;
    // int g = 0;
    // if(k>n) {
    //     reverse(mv.begin()+g, mv.end());
    //     return mv;
    // }
    // while(k <= n) {
    //     reverse(mv.begin()+g, mv.begin()+k);
    //     g = k;
    //     k = 2*k;
    // }
    // // if(n == 32253 or k == 7679 )
    // //     cout << k << " " << g << endl;
    // if(g != n){
    //     reverse(mv.begin()+g, mv.begin()+n);
    //     g = n;
    // }
    // if(n == 32253 or k == 7679 ){
    //     // cout << k << " " << g << endl;
    //     for(int i=0; i<n; i++){  
    //         cout << mv[i] << " ";
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < n; i += k) 
    { 
        int left = i; 
  
        // to handle case when k is not multiple of n 
        int right = min(i + k - 1, n - 1); 
  
        // reverse the sub-array [left, right] 
        // while (left < right) 
        //     swap(arr[left++], arr[right--]); 
        reverse(arr.begin()+left, arr.begin()+right+1);
  
    } 
    return arr;
    // your code here
    
}


int main(int argc, char const *argv[])
{
    
    int t;
    cin >> t;
    while(t--) {
        int n, g;
        cin >> n >> g;
        vector<int> arr;
        // int* dp = new int[n+1]();
        for(int i=0; i<n; i++){  
            int a;
            cin >> a;
            arr.push_back(a);
        }
        reverseInGroups(arr, n, g);
        // reverse(arr.begin(), arr.begin()+g);
        
        for(int i=0; i<n; i++){  
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    
}
