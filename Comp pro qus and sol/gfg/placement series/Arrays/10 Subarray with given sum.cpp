#include<bits/stdc++.h>
using namespace std;

void subarraySum(int arr[], int n, int s){
    int dp[n];
    int sum = 0;
    int index = 0;
    dp[0] = arr[0];
    for(int i=1; i<n; i++) {
        dp[i] = dp[i-1]+arr[i];
        if(dp[i] >= s) {
            index = i;
        }
    }
    cout << " index " << index << endl;
    if(arr[0] == s){
      cout << "1 1";
      return;
    } 
    
    for(int i=index; i<n; i++) {
        if(dp[i] == s) {
            cout <<"1 " << i+1 ;
            return;
        }
        for(int j=0; j<i; j++) {
            if(dp[i] - dp[j] == s) {
                cout << j+2 << " " << i+1;
                return;
            }
        }
        // int j = binary_search_recursive(arr, abs(arr[i] - s), 0, i-1);
        // if(j != -1)
        //     cout << j << " " << i;
        //     return;
    }
    cout << "-1";
    return;
    // Your code here
    
}
int main(int argc, char const *argv[])
{
    int n, s;
    cin >> n >> s;
    int* arr = new int[n+1];
    for(int i=0; i<n; i++) cin >> arr[i];
    subarraySum(arr, n, s);
    return 0;
}
