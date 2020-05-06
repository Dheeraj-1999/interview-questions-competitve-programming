#include<bits/stdc++.h>
using namespace std;

void printDFS(int** edges, int n, int sv, bool* visited){
	cout << sv <<" ";
	visited[sv] = 1;
	for(int i = 0; i<n; i++){
		if(i == sv)
			continue;
		if(edges[sv][i] == 1){
			if(visited[i])
				continue;
			printDFS(edges, n, i, visited);
		}
	}
}

void printBFS(int** edges, int n , int sv, bool * visited){
	queue<int>pendingVertics;
			
	pendingVertics.push(sv);
	visited[sv] = true;
	while(!pendingVertics.empty()){
		int currentvertex = pendingVertics.front();
		cout << currentvertex << " ";
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
//	delete [] visited;
}
void BFS(int** edges, int n){
	bool* visited = new bool [n];
	for(int i = 0; i<n; i++)
		visited[i] = false;
		
	for(int i = 0; i<n; i++){
			if(!visited[i])
		printBFS(edges, n, i, visited);
		
	}
	delete [] visited; 
}

void DFS(int** edges, int n){
	bool* visited = new bool [n];
	for(int i = 0; i<n; i++)
		visited[i] = false;
	for(int i = 0; i<n; i++){
		if(!visited[i])
			printDFS(edges, n, i, visited);	
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
	cout << "BFS" <<endl;
	BFS(edges, n);	
	
	
	cout << "DFS" <<endl;
	DFS(edges, n);
	
}
