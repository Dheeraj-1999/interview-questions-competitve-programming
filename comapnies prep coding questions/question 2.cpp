#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	int total = 0;
	vector<int> sums(m, 0);
	vector<int> array(n, 0);
	for(int t = 1; t<=n; t++)
		cin >> array[t];

	for(int i=1; i<=n; i++) {
		total += array[i];
		cout << total << " ";
		if(m%i == 0) {
			sums.push_back(total);
			total = 0; 
		}
	}
	vector<int> :: iterator it;
	cout << endl;
	for(it=sums.begin(); it != sums.end(); it++)
		cout << *it << " ";
}
