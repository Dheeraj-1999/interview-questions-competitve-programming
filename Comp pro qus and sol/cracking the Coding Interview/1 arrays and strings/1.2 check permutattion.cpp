#include<bits/stdc++.h>
using namespace std;

bool isPermu(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());

    for(int i=0; i<s1.length(); i++) {
        if(s1[i] != s2[i])
            return false;
    }
    return true;
}

bool isPermu2(string s1, string s2) {
    map<char, int> checker;
    for(int i=0; i<s1.length(); i++) {
        checker[s1[i]] += 1;
    }
    for(int i=0; i<s1.length(); i++) {
        checker[s2[i]] -= 1;
    }
    map<char, int>:: iterator it;
    for(it = checker.begin(); it != checker.end(); it++) {
        if(it->second != 0)
            return false;
    }
    return true;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    // cout << isPermu(s1,s2) << endl;

    cout << isPermu2(s1, s2) << endl;
}