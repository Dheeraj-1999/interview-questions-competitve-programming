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

void kLevelOrderPrint(node* root, int k) {
    if(root == NULL)
        return;
    if(k == 1) {
        cout << root->data << " ";
        return;
    }
    kLevelOrderPrint(root->left, k-1);
    kLevelOrderPrint(root->right, k-1);
    return;
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

int main(int argc, char const *argv[])
{
    node* root = buildTree();
    int height = calcuHeight(root);
    for(int i=1; i<=height; i++){  
        kLevelOrderPrint(root, i);
        cout << endl;
    }
    return 0;

    // int n = 1034006;
    // stack<int> a;
    // // vector<char> a;
    // // for(int i=1; i<=7; i++) {
    // //     int tenMill = 10;

    // // }
    // //     i = 10000000;
    // cout << n/1000000;
}