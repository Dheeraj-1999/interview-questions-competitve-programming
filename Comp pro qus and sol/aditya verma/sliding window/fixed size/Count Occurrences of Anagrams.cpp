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

void calcAnagrams(string str, string word) {
    
    map<char, int> original;
    for(int i=0; i<word.length(); i++) 
        original[word[i]] += 1;


    int k = word.length();
    map<char, int> temp;

    for(int i=0; i<k; i++) {
        temp[str[i]] += 1;
    }
    int count = 0;
    for(int i=0; i<k; i++) {
        if(temp[str[i]] != original[word[i]])
            break;
    }
    count += 1;
    //
}

int main(int argc, char const *argv[])
{
    
    string str, word;
    cin >> str >> word;

    
    
    return 0;
}

