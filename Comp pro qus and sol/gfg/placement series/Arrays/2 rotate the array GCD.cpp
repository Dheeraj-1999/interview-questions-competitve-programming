#include<bits/stdc++.h>
using namespace std;

// juggling array prblm................

// https://www.youtube.com/watch?v=utE_1ppU5DY

int* rotateArray(int* arr, int n, int k) {
    for(int i=1; i<=n; i++) {
        int nuSets = __gcd(n, k);
        int nuEle = n/nuSets;

        for(int i=1; i<nuSets; i++) {
            int temp = arr[i];
            int j =1;
            int k = i;
            while(j < nuEle){
                arr[k] = arr[k+nuSets];
                j ++;
                k += nuSets;
            }
            arr[k] = temp;
        }

    }
    return arr;
}

int main(int argc, char const *argv[])
{
    
    int n, k;
    cin >> n >> k;
    int* arr = new int[n+1];
    for(int i=1; i<=n; i++) {
        cin >>arr[i];
    }
    rotateArray(arr, n, k);
    return 0;
}
