#include<bits/stdc++.h>
using namespace std;


void cnvArr2HeapUopt(vector<int> &v) {
    int n = v.size() - 1; //exclude -1 ie v[0]
    for(int i=2; i<=n; i++) {
        int idx = i;
        int parent = i/2;

        while (idx > 1 and v[idx] > v[parent])
        {
            swap(v[idx], v[parent]);
            idx = parent/2;
            parent /= 2;
        }  
    }
}

void heapify(vector<int> &v, int index, int n) {
    int left = 2*index;
    int right = left + 1;

    int maxIdx = index;
    int last = n;
    if(v[left] > v[index] and left <= last) {
        maxIdx = left;
    }

    if(v[right] > v[maxIdx] and last >= right) {
        maxIdx = right;
    }
    
    if(maxIdx != index){
        swap(v[index], v[maxIdx]);
        heapify(v, maxIdx, n);
    }
}

void cnvArr2HeapOpt(vector<int> &v) {
    int n = v.size()-1;
    for(int i=n/2; i>0; i--) {
        heapify(v, i, n);
    }
}

void pop(vector<int> &v, int n){
    // int n = v.size() -1;
    swap(v[1], v[n-1]);
    // cout << v[1] << " " << v[n] << endl;
    heapify(v, 1, n);
}

void heapSort(vector<int> &v) {
    cnvArr2HeapOpt(v);

    int n = v.size() - 1; 
    while(n>1) {
        swap(v[1], v[n-1]);
    // cout << v[1] << " " << v[n] << endl;
        n -= 1;
        heapify(v, 1, n);
    }   
}
int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<int> v;
    v.push_back(-1);
    for(int i=1; i<=n; i++) {
        int no;
        cin >> no;
        v.push_back(no);
    }

    // cnvArr2HeapUopt(v);
    heapSort(v);
    for(int i=0; i<=n; i++) {
        cout << v[i] << " ";
    }
    // print(v);
    return 0;
}
