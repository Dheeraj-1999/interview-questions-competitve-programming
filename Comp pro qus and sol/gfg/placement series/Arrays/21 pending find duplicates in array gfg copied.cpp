#include<bits/stdc++.h>
using namespace std;


vector<int> duplicates(int a[], int n) {
    // First check all the values that are
    // present in an array then go to that
    // values as indexes and increment by
    // the size of array
    for (int i = 0; i < n; i++) {
        int index = a[i] % n;
        a[index] += n;
    }

    // Now check which value exists more
    // than once by dividing with the size
    // of array
    bool flag = false;
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        if ((a[i] / n) > 1) {
            ans.push_back(i);
            flag = true;
        }
    }
    if (!flag) ans.push_back(-1);
    return ans;
}