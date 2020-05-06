#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int>arr(20);
    vector<int> index(20);
    int counts = 0 ;
    int sizeArr;

    cout<<"enter the array size"<<endl<<endl;
    cin>>sizeArr;
    for (int i = 0; i<sizeArr; i++){
        cin>>arr[i];
    }

    for (int i = 0; i<sizeArr; i++){
        index[arr[i]-1] = i;
    }
    int temp;
    for (int i = 0; i<sizeArr;i++){
        if( arr[i]!= i+1 ){
            counts += 1;
            temp = arr[i];
            swap(arr[i], arr[index[i]]);
            index[temp-1] = index[i];
        }
    }

    cout<<endl<<counts<<endl;
}
