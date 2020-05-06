#include<bits/stdc++.h>
using namespace std;

void printBFS(int** edges, int n , int sv){
	queue<int>pendingVertics;
		
	bool* visited = new bool [n];
	for(int i = 0; i<n; i++)
		visited[i] = false;
		
	pendingVertics.push(sv);
	visited[sv] = true;
	while(!pendingVertics.empty()){
		int currentvertex = pendingVertics.front();
		cout << currentvertex << endl;
		pendingVertics.pop();
		for(int i = 0; i<n; i++){
			if(i == currentvertex)
				continue;
			if(!visited[i] && edges[currentvertex][i] == 1){
				pendingVertics.push(i);
				visited[i] = true;
			}
		}
	}
	delete [] visited;
}

int main(){
	int n , e;
	cin >> n >> e;
	
	int** edges = new int* [n];
	for(int i = 0; i<n; i++){
		edges[i] = new int [n];
		for(int j = 0; j<n; j++ )
			edges[i][j] = 0;
	}
	
	for(int i = 0; i<e; i++){
		int f, s;
		cin >> f >> s;
		edges[f][s] = 1;
		edges[s][f] = 1;
	}

	printBFS(edges, n, 0);
}
