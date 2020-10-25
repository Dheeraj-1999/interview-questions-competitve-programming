#include<bits/stdc++.h>
using namespace std;

vector<int> findMinsSizei(int* arr, int n, int k) {
    vector<int> ans;
    
    // deque<int> dq(k);
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
    ans.push_back(arr[q.front()] );


}

void maxOfMins(int* arr, int n) {
    int maxMinArr = INT_MIN;
    for(int i=1; i<=n; i++) {
        vector<int> minArr;
        minArr = findMinsSizei(arr, n, i);
        maxMinArr = INT_MIN;
        for(int j=0; j<minArr.size(); j++ ) {
            maxMinArr = max(minArr[i], maxMinArr);
        }
        cout << maxMinArr << " ";
        // for(int j=0; j<minArr.size(); j++ ) {
        //     maxMinArr = max(minArr[j], maxMinArr);
        //     cout << minArr[i] << " ";
        // }
        // cout << endl;
    }
    
    int mini = INT_MAX;
    for(int i=0; i<n; i++) {
        mini = min(arr[i], mini);
    }
    // ans.push_back(mini);
    cout << mini;
    
    // cout << maxMinArr << " ";
}

int main(int argc, char const *argv[])
{
    
    int n;
    cin >> n;

    int* arr = new int[n];
    for(int i=0; i<n; i++)
        cin >>  arr[i];
    maxOfMins(arr, n);
    return 0;
}
