#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        int level;
        node* left;
        node* right;
        node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

node* buildTree() {
    int d;
    cin >> d;

    if(d == -1) return NULL;
    
    node* root = new node(d);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}


void rightViewBfs(node* root) {
    queue<pair<node*, int>> q;
    int level = 1;
    q.push(make_pair(root, level));
    int max_level = -1;
    while(!q.empty()) {
        node* temp = (q.front()).first;
        // cout << temp->data << (q.front()).second << endl;
        level = (q.front()).second+1;

        if(level > max_level) {
            cout << temp->data << " " ;
            max_level = level;
        }

        q.pop();
        // level += 1;
        if(temp->right != NULL) {
            q.push(make_pair(temp->right, level));
        }
        if(temp->left != NULL) {
            q.push(make_pair(temp->left, level));
        }
    }
}
int max_level = -1;
void helper(node* root, int level) {
    if(root == NULL) return;

    if(level > max_level) {
        max_level = level;
        cout << root->data;
    }
    helper(root->right, level+1);
    helper(root->left, level+1);
    return;
}

void rightViewDfs(node* root) {  
    helper(root, 0);
    return;
}

int main() {
    node* root = buildTree();
    rightViewDfs(root);
}