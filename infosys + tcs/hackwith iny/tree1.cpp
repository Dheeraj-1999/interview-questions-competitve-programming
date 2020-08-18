#include<bits/stdc++.h>
using namespace std;

void preorder(vector<vector<int>> edges, int n, int* visited, int sv, int treeNode) {
    visited[sv] = 1;

    for(int i=)


}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<vector<int>> edges(n);
    int* visited = new int[n]();
    for(int i=0; i<n; i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    
    preorder(edges, n, visited, 1, 1);

    return 0;
}

