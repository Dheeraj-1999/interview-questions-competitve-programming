#include<bits/stdc++.h>
using namespace std;

pair<int, int> findPair(int* arr, int n, int sum) {
    int low = 0; 
    int high = n-1;

    while(low < high) {
        if(arr[low] + arr[high] < sum) {
            low++;
        } else if(arr[low] + arr[high] > sum)
            high--;
        else {
            return(make_pair(arr[low], arr[high]));
        }
    }
    return make_pair(-1, -1);
}

int main(int argc, char const *argv[])
{
    
    int n, k;
    cin >> n >> k;
    int* arr = new int[n+1];
    for(int i=0; i<n; i++) {
        cin >>arr[i];
    }
    pair<int, int> ans = findPair(arr, n, k);
    cout << ans.first << " "  << ans.second;
    return 0;
}