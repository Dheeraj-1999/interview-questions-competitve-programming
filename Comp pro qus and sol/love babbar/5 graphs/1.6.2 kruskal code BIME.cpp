#include<bits/stdc++.h>
using namespace std;

class Edge{
	public:
		int src;
		int dest;
		int weight;
};
bool compare(Edge e1, Edge e2){
	return(e1.weight<e2.weight);
}

int getParent(int vertex, int* parent){
	if(parent[vertex] == vertex)
		return parent[vertex];
	return(getParent(parent[vertex], parent));
}
Edge* kruskal(Edge* edges, int n, int E){
	int count = 0;
	Edge* output = new Edge[n-1]; 
	int * parent = new int[n];
	
	for(int i = 0; i<n; i++)
		parent[i] = i;
		
		
	sort(edges, edges+E, compare);
	int i = 0;
	while(count<n-1){
//		check the topmost parent of v1 and v2
		Edge currentEdge = edges[i];
		int srcparent = getParent(currentEdge.src, parent);
		int destParent = getParent(currentEdge.dest, parent);
		if(srcparent !=  destParent){
			output[count] = currentEdge;
			count += 1;
			parent[srcparent] = parent[destParent];
		}
		i++;
	}
	return output;
	
}

int main(){
	int n,E;
	cin >> n >> E;
	Edge* edges = new Edge[E];
	for (int i = 0; i<E; i++)
		cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
	Edge* output = kruskal(edges, n, E);
	for(int i = 0 ;i<n-1; i++)
		cout<<output[i].src << output[i].dest <<endl;
}
