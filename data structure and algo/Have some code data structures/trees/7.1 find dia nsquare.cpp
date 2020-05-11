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

int calcuHeight(node* root) {
    if(root == NULL) {
        return 0;
    }

    int ls = calcuHeight(root->left);
    int rs =  calcuHeight(root->right);
    int ans = max(ls, rs) + 1;
    return ans;
}

int findDia(node* root) {
    if(root == NULL)
        return 0;

    int hL = calcuHeight(root->left);
    int hR = calcuHeight(root->right);

    int opt1 = hL+hR;
    int opt2 = findDia(root->left);
    int opt3 = findDia(root->right);
    cout << root->data << " " << opt1 << " " << opt2 << " " << opt3 <<endl;
    return(max(opt1, max(opt2, opt3)));
}

int main(int argc, char const *argv[])
{
    node* root = buildTree();
    cout << findDia(root) << endl;
    return 0;
}