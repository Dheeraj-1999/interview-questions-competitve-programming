#include<bits/stdc++.h>
using namespace std;
void insert(stack<int> & arr, int ele)  {
    if(arr.size() == 0 || ele >= arr.top()) {
        arr.push(ele);
        return;
    }

    int temp = arr.top();
    arr.pop();
    insert(arr, ele);
    arr.push(temp);
}

void sort(stack<int> & arr) {
    if(arr.size() == 1) {
        return;
    }
    int ele = arr.top();
    arr.pop();
    sort(arr);
    insert(arr, ele);
    
}

int main(int argc, char const *argv[])
{
    
    stack<int> inputArr;
    int temp;
    while(cin >> temp) {
        inputArr.push(temp);
    }

    sort(inputArr);

    while(inputArr.size()!=0){
        cout<<inputArr.top()<<" ";
        inputArr.pop();
    }



    return 0;

    
}