#include<bits/stdc++.h>
using namespace std;


void nextGreater(int* arr, int n) {
    stack<int> stk;
    stack<int> ans;
    for(int i=n-1; i>=0; i--) {
        if(stk.empty()) {
            ans.push(-1);
        }
        else {
            while(arr[i] >= stk.top()) {
                stk.pop();
            }
            ans.push(stk.top()); 
        }
        stk.push(arr[i]);
        // cout << stk.top() << " ";
    }

    while(!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
}


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int* arr = new int[n];

    for(int i=0; i<n; i++)
        cin >> arr[i]; 
    nextGreater(arr, n);   
    return 0;
}
