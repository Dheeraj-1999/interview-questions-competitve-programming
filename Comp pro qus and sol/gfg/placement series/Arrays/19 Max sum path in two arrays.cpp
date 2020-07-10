#include<bits/stdc++.h>
using namespace std;

int maxSum(int* arr1, int* arr2, int m, int n) {
    
    int i = 0;
    int j = 0;
    int sum1 = 0 ; 
    int sum2 = 0;
    int result = 0;

    while(i < m and j < n) {
            // cout <<arr1[i]<<" "<<arr2[j]<<" "<< sum1 << " sums " << sum2 << " " << result << endl;
        if(arr1[i] < arr2[j]) {
            sum1 += arr1[i++];
        }
        
        else if(arr2[j] < arr1[i]) {
            sum2 += arr2[j++];
        }

        else {
            result += max(sum1, sum2);
            sum1 = 0;
            sum2 = 0;

            while (i < m and j < n and arr1[i] == arr2[j] ) {
                result += arr1[i++];
                j += 1;
            }
        }
            
            // cout <<arr1[i]<<" "<<arr2[j]<<" "<< sum1 << " sums " << sum2 << " " << result << endl;
        // cout << sum1 << " " << sum2 << endl;
    }

    while (i < m) 
        sum1  +=  arr1[i++]; 
  
    // Add remaining elements of ar2[] 
    while (j < n) 
        sum2 +=  arr2[j++]; 
  
    // Add maximum of two sums of remaining elements 
    result +=  max(sum1, sum2);

    return result;
    
}

int main(int argc, char const *argv[])
{
    int n, m;
    cin >> m >> n;
    
    int* arr1 = new int[m+1];
    int* arr2 = new int[n+1];

    for(int i=0; i<m; i++) {
        cin >> arr1[i];
    }    
    for(int i=0; i<n; i++) {
        cin >> arr2[i];
    }   
    cout << maxSum(arr1, arr2, m, n); 
    return 0;
}
