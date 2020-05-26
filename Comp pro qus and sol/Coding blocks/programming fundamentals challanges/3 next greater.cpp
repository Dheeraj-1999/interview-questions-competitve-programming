#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int* arr= new int[n+1];
	int* temp = new int[n+1];
	for(int i=0; i<n; i++){
		cin >> arr[i];
		temp[i] = arr[i];
	}
	sort(arr, arr+n);
	for(int i=1; i<n; i++) {
		int ind = lower_bound(arr, arr+n, temp[i]) - arr;
		if(ind == n) cout << "-1" << " ";
		cout << temp[ind] << " ";
	}
	return 0;
}