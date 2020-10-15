
#include<bits/stdc++.h>
using namespace std;

void findFirstNeg(int* arr, int k, int n) {
    queue<int> q;
    for(int i=0; i<n; i++) {
        if(arr[i] < 0)
            q.push(i);
    }

    int curr = 0;
    for(int i=0; i<n-k+1; i++) {
        if(q.empty() or q.front() > (i+k-1))
            cout << "0" << " ";
        else {
            if(i == q.front()) {
                cout << arr[q.front()] << " ";
                q.pop();
            }
            else if(i < q.front()) {
                cout << arr[q.front()] << " ";
            }
        } 
        
    }
}   

int main(int argc, char const *argv[])
{
    
    int n, k;
    cin >> n >> k;

    int* arr = new int[n+1];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    findFirstNeg(arr, k, n);
    return 0;
}