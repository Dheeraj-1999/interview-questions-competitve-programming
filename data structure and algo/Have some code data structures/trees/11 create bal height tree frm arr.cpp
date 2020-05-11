#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        node* left;
        node* right;
    node(int d) {
        data = d;
        left = NULL;
        right = NULL; 
    }
};

node* buildTreeArray(int*arr, int s, int e) {

    if(s > e) {
        return NULL;
    }
    int mid = (s+e)/2;
    node* root = new node(arr[mid]);

    root->left = buildTreeArray(arr, s, mid-1);
    root->right = buildTreeArray(arr, mid+1, e);
    return root;

}

node* buildTreeArray2(int*arr, int n, int treeNode) {

    if(treeNode > n) {
        return NULL;
    }
    cout << treeNode << " fd";
    node* root = new node(arr[treeNode]);
    root->left = buildTreeArray2(arr, n, 2*treeNode);
    root->right = buildTreeArray2(arr, n, 2*treeNode+1);
    return root;

}

void BFS(node* root) {
    queue<node*> q;
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        cout << temp->data << " ";
        q.pop();
        
        if(temp->left) {
            q.push(temp->left);
        }
        if(temp->right) {
            q.push(temp->right);
        }
    }
    return;
}

int main() {
    // node* root = buildTreeArray();
    int n;
    cin >> n;
    int* arr = new int[n+1];

    for(int i=1; i<=n; i++){
        cin >> arr[i];
    }

    node*root = buildTreeArray2(arr, n, 1);
    BFS(root);
}