#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

void traversal(Node* root) {
    if(root == NULL) {
        return;
    }
    cout << root->data << " ";
    traversal(root->left);
    traversal(root->right);
}

Node* buildTree() {
    int data;
    cin >> data;

    if(data == -1) {
        return NULL;
    }

    Node* root = new Node(data);
    root->left = buildTree();
    root->right = buildTree();
    return root;
}

void BFT(Node* root) {
    queue<Node*> q;
    // Node* temp = root;
    q.push(root);
    while(!q.empty()) {
        Node* temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if(temp->left != NULL) {
            q.push(temp->left);
        }
        if(temp->right != NULL) {
            q.push(temp->right);
        }
    }
    return;
}


int main(int argc, char const *argv[])
{
    // int d1, d2, d3;

    // cin >> d1 >> d2 >> d3;
    // Node* root = build3Nodes(d1, d2, d3);

    Node* root = buildTree();
    BFT(root);
    traversal(root);    
    return 0;
}
