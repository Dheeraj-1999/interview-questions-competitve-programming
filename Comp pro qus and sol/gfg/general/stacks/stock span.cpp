#include<bits/stdc++.h>
using namespace std;


void nextGreaterleft(int* arr, int n) {
    stack<int> stk;
    queue<int> ans;

    for(int i=0; i<n; i++) {
        // cout << 1 << " " << i <<  endl;
        if(stk.empty()) {
            cout << 1 << " ";
            ans.push(-1);
        }
        else {
            while(!stk.empty() and arr[i] >= arr[stk.top()]) {
                stk.pop();
            }
            
            if(stk.empty()) {
                ans.push(-1);
                cout << 1 << " ";
            }else
                cout << i - stk.top() << " ";
                ans.push(stk.top()); 
        }
        stk.push(i);
    }

    // while(!ans.empty()) {
    //     cout << ans.front() << " ";
    //     ans.pop();
    // }

}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int* arr = new int[n];

    for(int i=0; i<n; i++)
        cin >> arr[i]; 
    nextGreaterleft(arr, n);   
    return 0;
}
