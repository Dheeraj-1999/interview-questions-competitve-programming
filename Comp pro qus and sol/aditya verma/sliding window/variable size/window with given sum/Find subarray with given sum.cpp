
#include<bits/stdc++.h>
using namespace std;

pair<int, int> WindowSum(int* arr, int sm, int n) {

    // sort(arr, arr+n);
    int i=0, j=0;
    int temp = 0;
    while(i < n and j < n) {
        
        if(temp == sm){
            // cout << i << " " << j << endl;
            return(make_pair(i, j));
        }
        else if(temp < sm) {
            temp += arr[j];
            j++;
        }
        else {
            temp -= arr[i];
            i++;
        }
        cout << temp << " ";
    }
    
}   

int main(int argc, char const *argv[])
{
    
    int n, k;
    cin >> n >> k;

    int* arr = new int[n+1];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    pair<int, int> p = WindowSum(arr, k, n);
    cout << endl << p.first << " " << p.second;    
    return 0;
}