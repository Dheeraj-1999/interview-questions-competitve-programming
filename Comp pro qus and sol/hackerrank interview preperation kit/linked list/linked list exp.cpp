#include<bits/stdc++.h>
using namespace std;

int main() {
	int counter = 0;
	int n ,m;
	cin >> n;
	int arr[n+1];
	for(int i=1; i<=n; i++) 
		cin >> arr[i];
	cin >> m;
	
	list<int> queue1;
//	list<int> queue2(n+1);
	for(int i=1; i<=n; i++) {
		queue1.push_front(arr[i]);
	}
	list<int> :: iterator it;
	for(int i=1; i<=n; i++) {
		counter += m%n;
		advance(it, counter);
		queue1.erase(it);
	}
	
	
	for(it=queue1.begin(); it!=queue1.end(); it++)
		cout<< *it << " ";
	
}
