#include<bits/stdc++.h>
using namespace std;

// 1.5 cracking the coding interview

bool go(string str1, string str2, map<char, int> m1, map<char, int> m2) {
    map<char, int>:: iterator it;
 
    int counts = 0;
    for(it = m1.begin(); it != m1.end(); it++) {
        cout <<it->first << " " << it->second << endl;
        if(counts > 2)
            return false;
        counts += abs(it->second);
    }
    return true;

}

bool oneEditInsert(string str1, string str2) {
    int index1 = 0, index2 = 0;
    while(index1 < str1.length() and index2 < str2.length()) {
        if(str1[index1] != str2[index2]) {
            if(index1 != index2)
                return false;
            index2++;
        } else {
            index1 += 1;
            index2 += 1;
        }
    } 
    return true;
}

bool oneEditReplace(string str1, string str2) {
    bool flag = false;
    for(int i=0; i<str1.length(); i++) {
        if(str1[i] != str2[i]) {
            if(flag) 
                return false;
            flag = true;
        }
    }
    return true;
}
bool oneEditAway(string str1, string str2) {
    if(str1.length() == str2.length()) {
        return oneEditReplace(str1, str2);
    } else if(str1.length()+1 == str2.length()) {
        return oneEditInsert(str1, str2);
    } else if(str1.length()-1 == str2.length()) {
        return oneEditInsert(str1, str2);
    }
    return false;
}

int main() {
    string str1, str2;
    getline(cin, str1);
    getline(cin, str2);
    map<char, int> m1;
    map<char, int> m2;

    // 1st approach
    int* arr = new int[128]();

    for(int i=0; i<str1.length(); i++) {
        arr[str1[i]] += 1;
        arr[str2[i]] -= 1;
    }
    for(int i=0; i<128; i++)
        cout << arr[i] << " ";
    cout << endl;

// 2nd approach
    for(int i=0; i<str1.length(); i++)
        m1[str1[i]] += 1;
    
    for(int i=0; i<str2.length(); i++)
        m1[str2[i]] -= 1;
    cout << go(str1, str2, m1, m2);

//  Another approach
   cout << oneEditAway(str1, str2);

}