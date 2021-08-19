#include<bits/stdc++.h>
using namespace std;

void remove(stack<int> &arr, int n) {
    if(arr.size() == n/2) {
        arr.pop();
        return;
    }
    int temp = arr.top();
    arr.pop();
    remove(arr, n);
    arr.push(temp);
}

int main(int argc, char const *argv[])
{
    stack<int> inputArr;
    int temp;
    while(cin >> temp) {
        inputArr.push(temp);
    }
    remove(inputArr, inputArr.size());
    while(inputArr.size()!=0){
        cout<<inputArr.top()<<" ";
        inputArr.pop();
    }
    return 0;
}
