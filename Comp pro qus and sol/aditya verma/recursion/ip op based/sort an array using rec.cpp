#include<bits/stdc++.h>
using namespace std;


void sortByRec(int* arr, int n) {

}

int main(int argc, char const *argv[])
{
    
    int n;
    cin >> n; 
    int* arr = new int[n];

    for(int i=0; i<n; i++)
        cin >> arr[i];

    sortByRec(arr, n);
    return 0;
}
