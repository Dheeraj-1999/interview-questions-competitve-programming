// Input : forxxorfxdofr
//         for
// Output : 3
// Explanation : Anagrams of the word for - for, orf, 
// ofr appear in the text and hence the count is 3.

// Input : aabaabaa
//         aaba
// Output : 4
// Explanation : Anagrams of the word aaba - aaba, 
// abaa each appear twice in the text and hence the
// count is 4.



#include<bits/stdc++.h>
using namespace std;

void calcAnagrams(string str, string word, int n, int k) {
    map<char, int> origin;
    for(int i=0; i<word.length(); i++) {
        origin[word[i]] += 1;
    }
    int count = 0;
    for(int i=0; i<n-k+1; i++) {  
        bool flag = false;  
        for(int j=i; j<i+word.length(); j++) {
            if(origin[str[j]] != 1) {
                flag = true;
                break;
            }
        }
        if(!flag)
            count += 1;
    }
}

int main(int argc, char const *argv[])
{
    
    string str, word;
    cin >> str >> word;

    
    
    return 0;
}

