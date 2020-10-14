#include<bits/stdc++.h>
using namespace std;

int lenWithMaxkpairs(int* arr, int n, int k) {
    unordered_map<int, int> freq;
    int np = 0;
    int i = 0, j = 0;
    int len = 0;
    int max_len = INT_MIN;


    while(i<=j and j<n) {
        np -= ((freq[arr[j]]-1) * freq[arr[j]])/2;
        freq[arr[j]] += 1;
        np += ( ( freq[arr[j]]-1 ) * ( freq[arr[j]] ) )/2;

        if(np > k) {
            freq[arr[i]] -= 1;
            i++;
            freq[arr[j]] -= 1;
            j--;
            
            np -= ((freq[arr[i]]-1) * freq[arr[i]])/2;
        } else {
            len = j-i+1;
            
            max_len = max(max_len, len);
            // cout << max_len << " " << len << endl;
            // j++;
        }   
        j++;
        
    }
    return max_len;
    // for(int i=0; i<n; i++) {
    //     freq[arr[i]] += 1;
    // }

}

int main(int argc, char const *argv[])
{
    int n, k;
    cin >> n >> k;

    int* arr = new int[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    cout << lenWithMaxkpairs(arr, n, k);    
    return 0;
}
