#include<bits/stdc++.h>
using namespace std;


int main(int argc, char const *argv[])
{
    
    string input;
    cin >> input;

    int* helper = new int[26]();

    for(int i=0; i<input.length(); i++) {
        helper[input[i] - 'a'] += 1;
    }
    map<int, int> m;
    for(int i=0; i<input.length(); i++) {
        if(helper[input[i] - 'a']) {
            cout << helper[input[i] - 'a'] << " ";
            m[helper[input[i] - 'a']]++;
            helper[input[i] - 'a'] = 0;
        }
    }

    

    return 0;
}
