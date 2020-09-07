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

void lca1(node* root, int* l1, int p) {
    if(root == NULL){
        // l1.push_back(root->data);
        return l1;
    }
    ;
    // cout << root->data << " ";
    lca1(root->left, l1, p);
    lca1(root->right, l1, p);
    return;
}
void printTreePre(node* root) {
    if(root == NULL)
        return;
    cout << root->data << " ";
    printTreePre(root->left);
    printTreePre(root->right);
    return;
}
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

int main(int argc, char const *argv[])
{
    
    node* root = buildTree();
    printTreePre(root);
    int p, q;
    cin >> p >> q;
    vector<int> l1;
    vector<int> l2;
    lca1(root, l1, p);
    cout << endl;
    for(int i=0; i<l1.size(); i++)
        cout << l1[i] << " ";
    return 0;
}
