#include<bits/stdc++.h>
using namespace std;

int go(int* arr, int n ,int m) {
    
    int maxi = INT_MIN;
    for(int i=0; i<n; i++) 
        maxi = max(maxi, arr[i]);
    int sums = 0;
    for(int i=0; i<n; i++) 
        sums += arr[i];
    int k = maxi;
    bool flag = true;
    while(flag) {
        int i = 0;
        int num = 0;
        while(i<n) {
            int cur_sum = 0;
            int temp = i;
            while(cur_sum <= k) {
                cur_sum += arr[temp];
                temp += 1;
            }
            num += 1;
            if(num > m) {
                cout << "NOT possible for:" << k << endl;
                flag = false;
                break;
            }
            i = temp-1;
            // cout << i << " " << cur_sum << endl;
        }
        if(flag == true) {  
            cout << "possible for:" << k << endl;
            break;
        }
        k += 1;
    }
    return k;
}
int isPossible(int* arr, int n, int m, int k) {
    // int k;
    // int maxi = INT_MIN;
    
    bool flag = true;
    int i = 0;
    int num = 0;
    
    while(i<n) {
        int cur_sum = 0;
        int temp = i;
        while(cur_sum <= k) {
            cur_sum += arr[temp];
            temp += 1;
        }
        num += 1;
        if(num > m) {
            cout << "NOT possible for:" << k << endl;
            flag = false;
            return false;
        }
        i = temp-1;
        // cout << i << " " << cur_sum << endl;
    }
    if(flag == true) {  
        cout << "possible for:" << k << endl;
        return true;
    }
}


int bin_search_k(int* arr, int n, int m, int start, int end) {
    bool k;
    if(start == end) {
        return start;

    }
    int mid = (start+end)/2;
    if(isPossible(arr, n, m, mid)) {
        k = bin_search_k(arr,n, m, start, mid);
    }
    else {
        k = bin_search_k(arr,n, m, mid+1, end);
    }
}


int main(int argc, char const *argv[])
{
    /* code */
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        int m;
        cin >> m;

        int* arr = new int[n];
        for(int i=0; i<n; i++)
            cin >> arr[i];
        int maxi = INT_MIN;
        for(int i=0; i<n; i++) 
            maxi = max(maxi, arr[i]);
        int sums = 0;
        for(int i=0; i<n; i++) 
            sums += arr[i];
        cout << bin_search_k(arr, n, m, maxi, sums);
    }
    return 0;
}

