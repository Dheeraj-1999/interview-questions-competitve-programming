#include<bits/stdc++.h>
using namespace std;

int go(int* arr, int size) {
	int* dp = new int[size]();
	if(arr[0] > 0)
		dp[0] = arr[0];
	else
		dp[0] = 0;
	if(arr[1] > 0)
		dp[1] = arr[1];
	else
		dp[1] = 0;
	for(int i=2; i<size; i++) {
		dp[i] = max(dp[i-2]+arr[i], arr[i]);
	}
	for(int i=0; i<size; i++) {
		cout << dp[i] <<" ";
	}
	int curr_max = INT_MIN;
	for(int i=0; i<size; i++) {
		curr_max = max(curr_max, dp[i]);
	}
	return curr_max;
}

int main(){
	int size;
	int sum ;
	cout<<"enter size and array"<<endl;
	cin>> size;
	int arr[size];
	for(int i= 0; i<size; i++ )
		cin>>arr[i];
	cout << endl<< go(arr, size);
//	cout<<"sum:"<<sum<<endl;
}
