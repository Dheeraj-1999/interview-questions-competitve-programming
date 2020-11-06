#include<bits./stdc++.h>
using namespace std;

void solve(int* arr, int n) {
    int maxCol = INT_MIN;

    for(int i=0; i<n; i++) {
        maxCol = max(maxCol, arr[i]);
    }
    cout << maxCol << endl;
// ********************************************
    int matrix[n][maxCol];

    for(int i=0; i<n; i++) {
        for(int j=0; j<arr[i]; j++) {
            matrix[i][j] = 1;
        }

        for(int j=arr[i]; j<maxCol; j++) {
            matrix[i][j] = 0;
        }
    }
// **********************************************************

// Printing portion
    // for(int i=0; i<n; i++) {
    //     for(int j=0; j<maxCol; j++) {
    //         cout << matrix[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    for(int i=n; i>0; i--) {
        for(int j=0; j<maxCol; j++) {
            cout << matrix[j][i] << " ";
        }
        cout << endl;
    }
    

}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int* arr = new int[n];

    for(int i=0; i<n; i++) cin >> arr[i];


    solve(arr, n);
    return 0;
}
