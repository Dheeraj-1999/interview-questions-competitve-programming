#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2, int m, int n) {
	if(n == 0 or m == 0)
		return 0;
	if(s1[m] == s2[n]) {
		return (1 + lcs(s1, s2, m-1, n-1));
	} else {
		int option1 = lcs(s1, s2, m-1, n);
		int option2 = lcs(s1, s2, m, n-1);
		return (max(option1, option2));
	}
}

int lcsDp(string s1, string s2, int m, int n) {
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
    return dp[m][n];
}

int main() {
	string s1, s2;
	cin >> s1 >> s2;
    int m, n;
    m = s1.length();
    n = s2.length();
	int result = lcs(s1, s2, m, n);
	cout << result << endl;
}
