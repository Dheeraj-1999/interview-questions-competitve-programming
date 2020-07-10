#include<bits/stdc++.h>
using namespace std;

int findPivot(int* arr, int n) {
    for(int i=0; i<n-1; i++) {
        if(arr[i] > arr[i+1]) {
            cout << "pivot " << arr[i+1] << endl;
            return i+1;
        }
    }
    return -1;
}

pair<int, int> helper(int* arr, int n, int sum, int low, int high) {

    while(low != high) {
        if(arr[low] + arr[high] < sum) {
            low = (low+1)%n;
        } else if(arr[low] + arr[high] > sum)
            high = (n+high - 1)%n;  
        else {
            return(make_pair(arr[low], arr[high]));
        }
    }
    return make_pair(-1, -1);
}

void findPairRotated(int* arr, int n, int sum) {
    int pivot = findPivot(arr, n);
    
    int low = pivot;
    int high = pivot - 1;

    pair<int, int> ans = helper(arr, n, sum, low, high);
    cout << ans.first << " "  << ans.second;

}
int main(int argc, char const *argv[])
{
    
    int n, k;
    cin >> n >> k;
    int* arr = new int[n+1];
    for(int i=0; i<n; i++) {
        cin >>arr[i];
    }
    
    findPairRotated(arr, n, k);
    return 0;
}