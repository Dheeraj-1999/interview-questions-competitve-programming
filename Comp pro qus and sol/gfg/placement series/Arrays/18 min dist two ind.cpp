#include<bits/stdc++.h>
using namespace std;

int minDist(int arr[], int n, int x, int y) {
    int mindist = INT_MAX;
    int idx1 = -1;
    int idx2 = -1;
    for(int i=0; i<n; i++) {
        // mindist = min(minsist, arr[i] - i)
        
        if(arr[i] == x) {
            idx1 = i;
        } else if(arr[i] == y) {
            idx2 = i;
        }
        // cout << idx1 << " " << idx2 << endl;
        mindist = min(mindist, abs(idx1 - idx2));
    }
    if(idx1 == -1 or idx2 == -1) {
        mindist = -1;
    }
    // cout << mindist << endl;
    return mindist;
    // code here
}
int main() 
{ 
    int arr[] = {86, 39, 90, 67, 84, 66, 62}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int x = 42; 
    int y = 12; 
  
    cout << "Minimum distance between " << x << 
                        " and " << y << " is "<< 
                        minDist(arr, n, x, y) << endl; 
    return 0; 
} 