#include<bits/stdc++.h>
using namespace std;

void printLcs(string s1, string s2, int m, int n) {
    int dp[m+1][n+1];
    dp[0][0] = 0;	
	
    for(int i=1; i<m+1; i++)
		dp[i][0] = 0;
	for(int j=1; j<n+1; j++)
		dp[0][j] = 0;


    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++) {
            // if(i == 0 or j == 0) dp[i][j] = 0;
            
            if(s1[i-1] == s2[j-1]) {
                dp[i][j] = 1 + dp[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    int i=m, j=n;
    string ans = ""; 
    while(i != 0 and j != 0) {
        if(s1[i-1] == s2[j-1]) {
            ans += s1[i-1];
            i -= 1;
            j -= 1;
        } else {
            if(dp[i-1][j]  > dp[i][j-1]) {
                i -= 1;
            } else {
                j -= 1;
            }
        }
    }
    cout << ans;
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
    int m, n;
    m = s1.length();
    n = s2.length();

	printLcs(s1, s2, m, n);
	// cout << result << " " << ans << endl;
}
