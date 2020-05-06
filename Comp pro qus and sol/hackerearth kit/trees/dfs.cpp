#include<bits/stdc++.h>
using namespace std;
int dp[16];
int arr[16];
void printDFS(vector<int>* edges, int n, int sv, int par){
	cout << sv <<" ";
	dp[sv] = arr[sv];
//	cout << "dpsv" << dp[sv] << " ";
	int mx = 0;
	for(int v: edges[sv]){
//		cout << sv <<" "<< v<<" ";
		if(v == par)
			continue;
		printDFS(edges, n, v, sv);
		
		mx = max(mx, dp[v]);
		cout << "dp" << dp[v] <<" "<<"mx"<< mx<< endl;
//		cout << mx;
	}
//	return value to parent node;
	dp[sv] += mx;
}
//14 13
//1 2
//1 3
//1 4
//2 5
//2 6
//3 7
//4 8
//4 9
//4 10
//5 11
//5 12
//7 13
//7 14
//3 2 1 10 1 3 9 1 5 3 4 5 9 8
int main(){
	int n,e;
	cin >> n >> e;
//	int arr[n];
	vector<int> edges[n+1];
	for(int i=0; i<e; i++) {
		int u, v;
		cin >> u >> v;
		edges[u]. push_back(v);
		edges[v]. push_back(u);
	}
	for(int i=1; i<=n; i++)
		cin >>arr[i];
	
//	for(int i=1; i<=n; i++)
//		cout << dp[i] << " ";
	
//	for(int i : edges[0]) {
//		cout << i<<" ";
//	}
	printDFS(edges, n, 1, 0);
//	cout<<dp[1];
	for(int i=1; i<=n; i++)
		cout << dp[i] << " ";
	
}
