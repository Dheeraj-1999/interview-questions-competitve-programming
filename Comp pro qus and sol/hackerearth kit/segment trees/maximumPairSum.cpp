#include<bits/stdc++.h>
using namespace std;

class node {
	public:
		int maximum;
		int smaximum;
};


void buildTree(int* arr, node* tree, int start, int end, int treeNode) {
	if(start == end) {
		tree[treeNode].maximum = arr[start];
		tree[treeNode].smaximum = INT_MIN;
		return;
	}
	
	int mid = (start+end)/2;
	buildTree(arr, tree, start, mid, 2*treeNode);
	buildTree(arr, tree, mid+1, end, 2*treeNode+1);
	
	node left = tree[2*treeNode];
	node right = tree[2*treeNode+1];
	
	tree[treeNode].maximum = max(left.maximum, right.maximum);
	tree[treeNode].smaximum = min(max(left.maximum, right.smaximum), max(left.smaximum, right.maximum));
	return;
}


void updateTree(int* arr, node* tree, int start, int end, int treeNode, int idx, int value) {
	if(start == end) {
		arr[idx] = value;
		tree[treeNode].maximum = arr[start];
		tree[treeNode].smaximum = INT_MIN;
		return;
	}
	
	int mid = (start+end)/2;
	if(idx < mid) {
		updateTree(arr, tree, start, mid, 2*treeNode, idx, value);
	} else {
		updateTree(arr, tree, start, mid, 2*treeNode+1, idx, value);
	}
	
	node left = tree[2*treeNode];
	node right = tree[2*treeNode+1];
	tree[treeNode].maximum = max(left.maximum, right.maximum);
	tree[treeNode].smaximum = min(max(left.maximum, right.smaximum), max(left.smaximum, right.maximum));
	return;	
}

node query(node* tree, int start, int end, int treeNode, int left, int right) {
	if(start > right or end < left) {
		node temp;
		temp.maximum = INT_MIN;
		temp.smaximum = INT_MIN;
		return temp;
	}
	if(start >= left or end <= right)
		return tree[treeNode];
	
	int mid = (start+end)/2;
	node l = query(tree, start, mid, 2*treeNode, left, right);
	node r = query(tree, mid+1, end, 2*treeNode+1, left, right);
	
	node ans;
	ans.maximum = max(l.maximum, r.maximum);
	ans.smaximum = min(max(l.maximum, r.smaximum), max(l.smaximum, r.maximum));
	return ans; 		
}

int main() {
	int n;
	cin >> n;
	int* arr = new int[n];
	node* tree = new node[3*n];
	for(int i=0; i<n; i++)
		cin >> arr[i];
	
	buildTree(arr, tree, 0, n-1, 1);
	
	int t;
	cin >> t;
	while(t--) {
		char a;
		int b, c;
		cin >> a >> b >> c;
		
		if(a == 'Q') {
			node ans = query(tree, 1, n, 1, b, c);
			cout << ans.maximum <<" " << ans.smaximum << endl;
		}
		if(a == 'U') {
			updateTree(arr, tree, 1, n, 1, b, c);
		}
		
	}
	
	
}
