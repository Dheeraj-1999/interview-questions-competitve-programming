#include<bits/stdc++.h>
using namespace std;

int alphaCode(int* arr, int n) {
    if(n == 0 or n == 1) {
        return 1;
    }
    int output = alphaCode(arr, n-1);

    if(arr[n-2]*10 + arr[n-1] <= 26) {
        output += alphaCode(arr, n-2);
    }
    cout << output << endl;
    return output;
}

int alphaCodeDp(int* arr, int n) {
    int* dp = new int[n+1]();
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<n+1; i++) {
        dp[i] = dp[i-1];
        if(arr[i-2]*10 + arr[i-1] <= 26) {
            dp[i] += dp[i-2];
        }
    }
}

int main(int argc, char const *argv[])
{
    
    int n;
	cin >> n;
	// int* code = new int[n];
	int* arr = new int[n]();
	for(int i = 0; i<n; i++)
		cin >> arr[i];
	int result = alphaCode(arr, n);
    cout << endl << result << endl;
    return 0;
}


