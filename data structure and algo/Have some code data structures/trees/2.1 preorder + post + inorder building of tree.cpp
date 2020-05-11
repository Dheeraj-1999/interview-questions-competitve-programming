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

void printTreePre(node* root) {
    if(root == NULL)
        return;
    cout << root->data << " ";
    printTreePre(root->left);
    printTreePre(root->right);
    return;
}

void printTreeIn(node* root) {
    if(root == NULL)
        return;
    printTreeIn(root->left);
    cout << root->data << " ";
    printTreeIn(root->right) ;
    return;
}

void printTreePost(node* root) {
    if(root == NULL)
        return;
    
    printTreePost(root->left);
    printTreePost(root->right);
    cout << root->data << " ";
    return;
}

int main(int argc, char const *argv[])
{
    node* root = buildTree();
    printTreePre(root);
    cout << endl;
    printTreeIn(root);
    cout << endl;
    printTreePost(root);
    return 0;
}

