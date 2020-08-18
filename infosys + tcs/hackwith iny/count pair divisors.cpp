#include <bits/stdc++.h>

using namespace std;

int PairSum(int* input, int n, int m) {	 
	unordered_map<int, int> m1;
    int count = 0;
	for (int i = 0; i < n; ++i) {
        m1[input[i]%m] += 1;
    }
    unordered_map<int, int>:: iterator it;
    if(m1[m - (m/2)] > 0) {
        count -= 1;
        m1[m - (m/2)] -= 1;
    }
    for(it=m1.begin(); it!=m1.end(); it++) {
        if(m1[m - it->first] > 0) {
            // cout << "map: " << it->first << endl;
            count += it->second;
            m1[m - it->first] -= 1;
        }
        if(it->first == 0) {
            count += it->second;
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    /* code */
    int n, m;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }
    cin >> m;
    cout << PairSum(arr, n, m);
    return 0;
}
