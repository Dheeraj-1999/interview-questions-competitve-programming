#include<bits/stdc++.h>
using namespace std;

vector<int> findMinsSizei(int* arr, int n, int k) {
    vector<int> ans;

    deque<int> dq(k);

}

void maxOfMins(int* arr, int n) 0{
    vector<int> minArr;
    for(int i=1; i<=n; i++) {
        minArr = findMinsSizei(arr, n, i);
    }
    int maxMinArr = INT_MIN;
    for(int i=0; i<minArr.size(); i++ ) {
        maxMinArr = max(minArr[i], maxMinArr);
    }
    cout << maxMinArr << " ";
}

int main(int argc, char const *argv[])
{
    
    int n;
    cin >> n;

    int* arr = new int[n];
    for(int i=0; i<n; i++)
        cin >>  arr[i];
    return 0;
}
