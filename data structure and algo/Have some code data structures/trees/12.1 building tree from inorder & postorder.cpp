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

node* buildTreeInPre(int* inorder, int* preorder, int s, int e) {
    static int i = 0;
    if(s > e)
        return NULL;
    
    node* root = new node(preorder[i]);
    // int index = binary_search(inorder, inorder+e, root->data);
    int index = -1;
    for(int j=s; j<=e; j++){
        if(preorder[i] == inorder[j])
            index = j;
            break;
    }
    cout << s << " " << e << " " << index << " " << preorder[i] << endl;

    i++;
    // root->left = buildTreeInPre(inorder, preorder, s, index-1);
    // root->right = buildTreeInPre(inorder, preorder, index+1, e);
    return root;
}

// 8
// 3 2 8 4 1 6 7 5
// 1 2 3 4 8 5 6 7
void BFS(node* root) {
    queue<node*> q;
    q.push(root);
    int t = 9;
    while(!q.empty()) {
        node* temp = q.front();
        cout << temp->data << " ";
        q.pop();

// mistake i had done:P instead of temp->left I wrote root->left and pushed it in queue
// same childs had been pushed in q again and again
// causing infinite loop
        if(temp->left != NULL) 
            q.push(temp->left);
        if(temp->right != NULL)
            q.push(temp->right);
    }
    return;
}

int main() {
    int n;
    cin >> n;
    int* inorder = new int[n+1];
    int* preorder = new int[n+1];

    for(int i=0; i<n; i++)
        cin >> inorder[i]; 
    for(int i=0; i<n; i++)
        cin >> preorder[i];
    // BFS(root);
    // int index = binary_search(inorder, inorder+n, 4);
    node* root = buildTreeInPre(inorder, preorder, 0, n-1);
    BFS(root);
    // cout << index;
}