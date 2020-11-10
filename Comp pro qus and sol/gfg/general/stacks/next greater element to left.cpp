#include<bits/stdc++.h>
using namespace std;


void nextGreaterleft(int* arr, int n) {
    stack<int> stk;
    // vector<int> ans;

    for(int i=0; i<n; i++) {
        // cout << 1 << " " << i <<  endl;
        if(stk.empty()) {
            cout << "-1" << " ";
            // ans.push(-1);
        }
        else {
            while(!stk.empty() and arr[i] >= stk.top()) {
                stk.pop();
            }
            
            if(stk.empty()) {
                cout << "-1" << " ";
            }else
                cout << stk.top() << " ";
                // ans.push_back(stk.top()); 
        }
        stk.push(arr[i]);
    }
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
