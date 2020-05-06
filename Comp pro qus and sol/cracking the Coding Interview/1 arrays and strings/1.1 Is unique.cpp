// implement an algorithm to deermine if a string has all unique charactrers without using any data structure
#include<bits/stdc++.h>
using namespace std;

bool isUnique(string unique) {
    bool* checker = new bool[128]();

    for(int i=0; i<unique.size(); i++) {
        if(checker[unique[i]] == 1)
            return false;
        checker[unique[i]] = true;
    }
    return true;
}

int main(int argc, char const *argv[])
{
    // int n;
    // cin >> n;
    string unique;
    cin >> unique;
    // char* uniqueArr = new char[unique.size()];
    

    // sort(unique.begin(), unique.end());
    // // sort(uniqueArr, uniqueArr+unique.size());

    // for(int i=0; i<unique.size(); i++) {
    //     int a = 0;
    //     int b = 0;

    //     if(unique[i+1] == unique[i]){
    //         cout << "No" << endl;
    //         return 0;
    //     }
    // }
    // // cout << unique;
    // cout << "Yes" << endl;


    // Another Method
    cout << isUnique(unique);
    return 0;
}

