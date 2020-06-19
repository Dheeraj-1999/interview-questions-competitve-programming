#include<bits/stdc++.h>
using namespace std;

void printSolution(int** solution, int n){
	for(int i = 0; i<n; i++)
		for(int j =0 ; j< n; j++)
			cout<<solution[i][j] << " ";
	cout << endl;
}


void ratInMaze(int maze[][20], int** solution, int i, int j, int m, int n) {
    if(i == m and j ==n) {
        solution[m][n] = 1;
        printSolution(solution, n);
        return;
    }
    if((i >= m or j >= n or i < 0 or j < 0) or (maze[i][j] == 0) or (solution[i][j] == 1))
        return;
    
    // assume solution exist through current cell
    solution[i][j] = 1; 
    ratInMaze(maze, solution, i-1, j, m, n); //move up
    ratInMaze(maze, solution, i+1, j, m, n);// move down
    ratInMaze(maze, solution, i, j-1, m, n); // move left
    ratInMaze(maze, solution, i, j+1, m, n); //move right
    solution[i][j] = 0;
}

int main(){
	int n; 
	cin >> n;
	int maze[20][20];
    int**solution = new int*[20];
    for(int i=0; i<n; i++) {
        solution[i] = new int[20];
        for(int j=0; j<n; j++) {
            solution[i][j] = 0;
        }
    }
    for(int i = 0; i<n; i++) {
		for(int j = 0; j<n; j++)
            cout << solution[i][j] << " ";
        cout << endl;
    }
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
			cin >> maze[i][j];
	ratInMaze(maze, solution, 0, 0, n, n);
}