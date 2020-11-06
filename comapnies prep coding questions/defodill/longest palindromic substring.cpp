#include<bits/stdc++.h>
using namespace std;

int longestPalinSubstr(string str) {
    int n = str.length();
    int** dp = new int*[n];
    for(int i=0; i<n; i++) {
        dp[i] = new int[n];
        for(int j=0; j<n; j++) {
            dp[i][j] = 0;
        }
    }

    for(int i=0; i<n; i++) {
        dp[i][i] = 1;
    }

    for(int i=0; i<n-1; i++) {
        if(str[i] == str[i+1]) {
            dp[i][i+1] = 1;
        }
    }


    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {

        }
    }
}

int main(int argc, char const *argv[])
{
    
    string str;
    cin >> str;
    return 0;
}
