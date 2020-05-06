#include<bits/stdc++.h>
using namespace std;
//7 7
//0 1
//0 3
//1 2
//3 2
//3 4
//2 5
//5 6
void printDFS(int** edges, int n, int sv, int* visited){
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
		edges[f][s] = 1;
		edges[s][f] = 1;
	}
	
//	Print the edges
	int* visited = new int[n];
	for(int i = 0; i<n; i++)
		visited[i] = 0;
	
	printDFS(edges,n,0,visited);
	for (int i = 0; i < n; ++i)
	{
		if (visited[i] == 0)
		{
			cout << "false" << '\n';
			return 0;
		}

	}
	cout << "true" << '\n';
	delete [] visited;
	for(int i = 0; i<n; i++)
		delete [] edges[i];
	delete [] edges;
}
