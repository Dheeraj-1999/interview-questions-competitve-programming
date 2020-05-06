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

void add_element(int* heap, int value, int n) {
    int index = n+1;
    heap[index] = value;
    while(index > 1 and heap[index/2] < heap[index]) {
        swap(heap[index/2], heap[index]);
        index = index/2;
    }

    for(int i=1; i<=n+1; i++) 
        cout << heap[i] << " ";
    cout << endl;
}

void delete_element(int* heap, int value, int n) {
    for(int i=1; i<=n; i++) {
        if(heap[i] == value) { // we have to delete this value
            swap(heap[i], heap[n]);
            n -= 1;
            do_maxhipify(heap, i, n);
        }
    }
    for(int i=1; i<=n; i++) 
        cout << heap[i] << " ";
    cout << endl;
}

int main() {
    int n;
    cin >> n;
    int *arr = new int[n+1];

    for(int i=1; i<=n; i++) 
        cin >> arr[i];

    int* heap = new int[n+5];
    heap = buildHeap(arr, n);
    // for(int i=1; i<=n; i++) 
    //     cout << heap[i] << " ";
    // cout << endl;
    int value;
    cin >> value;
    delete_element(heap, value, n);

}