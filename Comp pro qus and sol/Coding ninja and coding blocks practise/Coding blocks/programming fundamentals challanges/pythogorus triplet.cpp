#include<bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    // if(N < 3) return -1;
    // bool flag = true;
    // vector<int> toSort;
    int m, n;
    if(N%2) { // n is odd
        m = (N+1)/2 ;
        n = (N-1)/2;
        cout << 2*m*n << " " << m*m + n*n << endl;
    } else {
        m = N/2;
        n = 1;
        cout << m*m - n*n << " " << m*m + n*n << endl;
    }
    // toSort.push_back(m*m - n*n);
    // toSort.push_back(2*m*n);
    // toSort.push_back(m*m + n*n);
    // sort(toSort.begin(), toSort.end());
    // for(int i: toSort) {
    //     cout << i << " ";
    // }

}
