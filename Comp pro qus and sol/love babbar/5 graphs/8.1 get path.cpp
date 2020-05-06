#include<bits/stdc++.h>
using namespace std;
vector<int> path;
void getpathDFS(int** edges, int n, int sv, int* visited, int ev){
	
	if(sv==ev){
		path.push_back(ev);
		return;
	}
	
	visited[sv] = 1;
	for(int i = 0; i<n; i++){
		if(i == sv)
			continue;
		if(edges[sv][i] == 1){
			if(visited[i])
				continue;
			getpathDFS(edges, n, i, visited, ev);
//			if(!path.empty()){
				cout<<sv<<endl;
				path.push_back(sv);
				return;
//			}
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
	
	int sv, ev;
	cin>>sv>>ev;
	getpathDFS(edges,n,sv,visited, ev);
	
	for(int i = 0; i < path.size(); i++)
        cout<<path[i]<<" ";
        
	delete [] visited;
	for(int i = 0; i<n; i++)
		delete [] edges[i];
	delete [] edges;
}
