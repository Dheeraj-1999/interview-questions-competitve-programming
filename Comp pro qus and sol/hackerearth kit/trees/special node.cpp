#include<bits/stdc++.h>
using namespace std;
//vector<int> special(n, 0);
int counts = 1;

//5 4
//3 1
//3 2
//2 4
//2 5
//1 1 2 2 1

void go(int** edges, int n, int sv, int* visited){
//	special.push_back(sv+1);
//	cout << sv+1 <<" ";
	visited[sv] = counts;
	counts++;
	for(int i = 0; i<n; i++){
		if(i == sv)
			continue;
		if(edges[sv][i] == 1){
			if(visited[i])
				continue;
			go(edges, n, i, visited);
		}
	}
//	return special;
}

int main(){
	int n,e;
	cin >> n >> e;
	
//	2d Array generation
	int** edges = new int* [n];
	for(int i = 0; i<n; i++){
		edges[i] = new int [n];
		for(int j = 0; j<n; j++)
			edges[i][j] = 0;
	}
	
//	input of edges in 2d Matrix
	for(int i = 0; i<e; i++){
		int f,s;
		cin >> f >> s;
		edges[f-1][s-1] = 1;
		edges[s-1][f-1] = 1;
	}
	
//	Print the edges
	int* visited = new int[n];
	int* arr = new int[n];
	for(int i = 0; i<n; i++)
		cin >> arr[i];
	for(int i = 0; i<n; i++)
		visited[i] = 0;
	go(edges, n, 0, visited);
	int t;
	int c= 0;
	cin >>t;
	while(t--) {
		
		int x, index;
		cin >> x;
		int color = arr[x-1];
		for(int i = 0; i<n; i++) {
			if(visited[i] != x) {
				continue;
			}
			index = i;
//			cout <<"index" << index << endl;
			break;
		}
		for(int i = index; i<n; i++) {
			cout << "visted[i] " << visited[i] << " color " << color <<" " << arr[visited[i]] <<endl;
			if(arr[visited[i]-1] == color) 
				c += 1;
		}
		
		cout << endl;	
		cout << c;
	}
	delete [] visited;
	for(int i = 0; i<n; i++)
		delete [] edges[i];
	delete [] edges;
}
