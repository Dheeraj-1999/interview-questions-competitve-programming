#include<bits/stdc++.h>
using namespace std;

class heap { // heap type: for both maxHeap and minHeap
    vector<int> v;
    bool minheap;

    bool compare(int a, int b) {
        if(minheap) {
            return (a>b);
        } else {
            return (a<b);
        }
    }
    
    void heapify(int index) {
        // int parent = index;
        int left = 2*index;
        int right= left + 1;

        int minIdx = index;
        int last = v.size() - 1;

        if(left <= last and compare(v[index], v[left])) {
            minIdx = left;
        }
        if(compare(v[minIdx], v[right]) and right <= last) {
            minIdx = right;
        }
        if(minIdx != index){
           swap(v[minIdx], v[index]);
           heapify(minIdx);
        }
    }

    public:
        heap(int default_size=10, bool type=true) {
            v.reserve(default_size);
            v.push_back(-1);
            bool minheap = type; // for 0th index as heap will start from 1st index of array
        }

        void push(int d) {
            v.push_back(d);
            int index = v.size()-1;
            int parent = index/2;

            while(index>1 and compare(v[parent], v[index])) {
                swap(v[parent], v[index]);
                index = parent;
                parent = parent / 2;
            }
        }
        int top() {
            return v[1];
        }
        void pop() {
            int lastIndex = v.size()-1;
            swap(v[1], v[lastIndex]);
            v.pop_back();
            heapify(1);
        }

        bool isempty() {
            return v.size() == 1;
        }

};

int main(int argc, char const *argv[])
{
    heap minHeap;
    int n;

    cin >> n;
    for(int i=0;i<n; i++) {
        int no;
        cin >> no;
        minHeap.push(no);
    }
    
    while(!minHeap.isempty()) {
        cout << minHeap.top() << " ";
        minHeap.pop();
    }
    return 0;
}
