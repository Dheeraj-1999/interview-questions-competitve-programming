#include<bits/stdc++.h>
using namespace std;
void insert(vector<int> & arr, int ele)  {
    if(arr.size() == 0 || ele >= arr[arr.size()-1]) {
        arr.push_back(ele);
        return;
    }

    int temp = arr[arr.size()-1];
    arr.pop_back();
    insert(arr, ele);
    arr.push_back(temp);
}

void sort(vector<int> & arr) {
    if(arr.size() == 1) {
        return;
    }
    int ele = arr[arr.size()-1];
    arr.pop_back();
    sort(arr);
    insert(arr, ele);
    
}

int main(int argc, char const *argv[])
{
    
    vector<int> inputArr;
    int temp;
    while(cin >> temp) {
        inputArr.push_back(temp);
    }

    sort(inputArr);

    for(int i : inputArr) {
        cout << i << " ";
    }



    return 0;

    
}
