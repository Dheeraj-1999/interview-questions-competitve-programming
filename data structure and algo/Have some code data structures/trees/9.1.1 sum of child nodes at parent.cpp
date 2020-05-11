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
            right =  NULL; 
        }
};

node* buildTree() {
    int d;
    cin >> d;

    if(d == -1) {
        return NULL;
    }
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void BFS(node* root) {
    queue<node*> q;
    q.push(root);
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

int sumChild(node* root) {
    if(root == NULL) 
        return 0;
        
    if(root->left == NULL and root->right == NULL)
        return root->data;
    int child1 = sumChild(root->left);
    int child2 = sumChild(root->right);
    int temp = root->data;
    root->data = child1 + child2;
    return(temp + root->data);
}
// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
int main(int argc, char const *argv[])
{
    node* root = buildTree();
    BFS(root);
    cout << endl;
    sumChild(root);
    BFS(root);
    return 0;
}