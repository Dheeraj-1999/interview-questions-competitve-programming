#include<bits/stdc++.h>
using namespace std;

int countPalindromic(string str) {
    int len = str.length();
    int count = 0;

    // odd length palindromes
    for(int i=0; i<len; i++) {
        int mid = i;
        int left = mid-1;
        int right = mid+1;
        count += 1;
        while(left >= 0 and right < len) {
            if(str[left] == str[right]) {
                count += 1;
                left -= 1;
                right += 1;
            } else {
                break;
            }
        }
    }

    // even lenght palindrome
    for(int i=0; i<len; i++) {
        int mid1 = i;
        int mid2 = i+1;
        if(str[mid1] == str[mid2]) {
            count += 1;
            int left = mid1 - 1;
            int right = mid2 + 1;
            while(left >= 0 and right < len) {
                if(str[left] == str[right]) {
                    count += 1;
                    left -= 1;
                    right += 1;
                } else {
                    break;
                }
            }
        }
    }
    return count;
}

int main(int argc, char const *argv[])
{
    
    string str;
    cin >> str;
    cout << countPalindromic(str);
    return 0;
}
