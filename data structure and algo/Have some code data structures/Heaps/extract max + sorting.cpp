#include<bits/stdc++.h>
using namespace std;

void do_maxhipify(int* arr, int i, int n) {
    int l = 2*i;
    int r = (2*i) + 1;
    int largest = INT_MIN;
    if(l <= n and arr[l] >= arr[i]) {
        largest = l;
    } else largest = i;
    if(r <= n and arr[r] >= arr[largest])
        largest = r;
    if(largest != i) {
        swap(arr[largest], arr[i]);
        do_maxhipify(arr, largest, n);
    }
}

int* buildHeap(int* arr, int n) {
    for(int i=(n/2); i>0; i--) {
        do_maxhipify(arr, i, n);
    }
    return arr;
}

void extract_max(int* heap, int &n) {
    int max = heap[1];
    heap[1] = heap[n];
    n -= 1;
    do_maxhipify(heap, 1, n);
    cout << max << " ";
    // for(int i=1; i<=n; i++) 
    //     cout << heap[i] << " ";
    // cout << endl;
    
}

void heapify(int* heap, int &n) {
    while(n > 0) {
        extract_max(heap, n);
    }
}
int main() {
    int n;
    cin >> n;
    int *arr = new int[n+1];

    for(int i=1; i<=n; i++) 
        cin >> arr[i];

    int* heap = new int[n+1];
    heap = buildHeap(arr, n);
    // for(int i=1; i<=n; i++) 
    //     cout << heap[i] << " ";
    // cout << endl;

    heapify(heap, n);

}