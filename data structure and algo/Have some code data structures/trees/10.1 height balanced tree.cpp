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

class HBpair {
    public:
        int height;
        bool balanced;
};

HBpair isHeightBalance(node* root) {
    HBpair p;
    if(root == NULL) {
        p.height = 0;
        p.balanced = true;
        return p;
    }

    HBpair left = isHeightBalance(root->left);
    HBpair right = isHeightBalance(root->right);

    p.height = max(left.height, right.height) + 1;
    if(abs(left.height - right.height) <= 1 and left.balanced == true and right.balanced == true) {
        p.balanced = true;
        return p;
    } else{ 
        p.balanced = false;
        return p;
    }
}

int main() {
    node* root = buildTree();
    if(isHeightBalance(root).balanced == true)
        cout << "balanced height" << endl;
    else cout << "Not balanced height" << endl;
}