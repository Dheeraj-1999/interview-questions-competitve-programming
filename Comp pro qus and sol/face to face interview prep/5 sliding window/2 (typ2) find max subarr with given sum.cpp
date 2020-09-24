#include<bits/stdc++.h>
using namespace std;

int findWindow(int* arr, int n, int sum) {
    vector<pair<int, int>> v;
    int winSum = 0;
    int i=0;
    for(int j=0; j<n; j++) {
        if(winSum > sum) {
            winSum -= arr[i];
            i += 1;
            j -= 1;
        } else if(winSum == sum) {
            cout << endl << i << " " << j - 1 << endl << endl;
            v.push_back(make_pair(i, j));
            winSum -= arr[i];
            i += 1;
            j -= 1;
        } else if(winSum < sum) {
            winSum += arr[j];
            // j += 1;
        }
        // cout << winSum << " " << i << " " << j << endl;
    }
}

int main(int argc, char const *argv[])
{
    
    int n, sum;
    cin >> n >> sum;
    int* arr = new int[n+1];

    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    findWindow(arr, n, sum);
    return 0;
}
