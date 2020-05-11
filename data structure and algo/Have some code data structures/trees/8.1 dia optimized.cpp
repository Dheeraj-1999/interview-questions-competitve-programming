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

pair<int, int> findDiaFast(node* root) {
    pair<int, int> p;

    // BASE CASE
    if(root == NULL){
        int height = 0;
        int dia = 0;
        p = make_pair(height, dia);
        return p;
    }

    pair<int,int> left = findDiaFast(root->left);
    pair<int,int> right = findDiaFast(root->right);

    // h1 = left.first
    // h2 = right.first
    // dia1 = left.second;
    // dia2 = rigth.second
    // dia = max(h1+h2, dia1, dia2)

    int height = max(left.first, right.first)+1;
    int dia = max(left.first + right.first, max(left.second, right.second));
    p = make_pair(height, dia);
    return p;
}

class pairs{
    public:
        int height;
        int dia;
};

pairs findDiaFastClass(node* root) {
    pairs p;

    // BASE CASE
    if(root == NULL){
        p.height = p.dia = 0;
        return p;
    }

    pairs left = findDiaFastClass(root->left);
    pairs right = findDiaFastClass(root->right);

    // h1 = left.first
    // h2 = right.first
    // dia1 = left.second;
    // dia2 = rigth.second
    // dia = max(h1+h2, dia1, dia2)

    p.height = max(left.height, right.height)+1;
    p.dia = max(left.height + right.height, max(left.dia, right.dia));
    return p;
}

int main(int argc, char const *argv[])
{
    node* root = buildTree();
    cout << findDiaFast(root).first << " " << findDiaFast(root).second << endl;
    // cout << findDiaFastClass(root).height << " " << findDiaFastClass(root).dia << endl;
    return 0;
}