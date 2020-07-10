#include<bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> n >> m;
    
    int* arr1 = new int[n+1];
    int* arr2 = new int[m+1];

    for(int i=0; i<n; i++) {
        cin >> arr1[i];
    }
    for(int i=0; i<m; i++) {
        cin >> arr2[i];
    }
    map<int, int> m1;
    for(int i=0; i<n; i++) {
        m1[arr1[i]] = 1;
    }
    for(int i=0; i<m; i++) {
        m1[arr2[i]] = 1;
    }
    map<int, int> :: iterator it;
    int count = 0;
    for(it = m1.begin(); it != m1.end(); it++) {
        count += 1;
    }
    cout << count;
}