#include <bits/stdc++.h>

using namespace std;
bool hasPath(int** edges, int n, int a, int b, int* visited){
	//Base Case
	if (a==b)
	{
		return 1;
	}
	int result = 0;
	
	for (int i = 0; i < n; ++i)
	{
		if (edges[a][i] == 1 && visited[i] == 0)
		{
			visited[i] = 1;
			result = hasPath(edges, n, i, b, visited);
			if (result==1)
			{
				return 1;
			}
		}
	}

	// for (int i = 0; i < n; ++i)
	// {
	// 	cout << visited[i] << ' ';
	// }

	return result;

}

int main( int argc , char ** argv )
{
	ios_base::sync_with_stdio(false) ; 
	cin.tie(NULL) ; 
	
	int n, e;
	cin>>n>>e;

	int** edges = new int*[n];

	for (int i = 0; i < n; ++i)
	{
		edges[i] = new int[n];
		for (int j = 0; j < n; ++j)
		{
			edges[i][j] = 0;
		}

	}

	int* visited = new int[n];
	for (int i = 0; i < n; ++i)
	{
		visited[i] = 0;
	}

	for (int i = 0; i < e; ++i)
	{
		int a, b;
		cin>>a>>b;

		edges[a][b] = 1;
		edges[b][a] = 1;
	}

	int c, d;
	cin>>c>>d;

	if(hasPath(edges, n, c, d, visited)){
		cout << "true" << '\n';
	}else{
		cout << "false" << '\n';
	}

	return 0 ; 

}

