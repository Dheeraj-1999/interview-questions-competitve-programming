



#include<bits/stdc++.h>
using namespace std;

pair<int, int> WindowSum(int* arr, int sum, int n) {

    sort(arr, arr+n);
    int i=0, j=0;
    int temp = 0;
    for(int i=0; i<n; i++) {
        temp += arr[i];
        if(temp == sum)
            return(make_pair(i, j));
        else if(temp < sum) {
            j++;
        }
        else {
            i++;
        }
    }
    
}   

int main(int argc, char const *argv[])
{
    
    int n, k;
    cin >> n >> k;

    int* arr = new int[n+1];
    for(int i=0; i<n; i++)
        cin >> arr[i];

    WindowSum(arr, k, n);    
    return 0;
}