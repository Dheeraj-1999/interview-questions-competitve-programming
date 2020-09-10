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


Node* build3Nodes(int d1, int d2, int d3) {
    Node *root = new Node(d1);
    Node *child1 = new Node(d2);
    Node *child2 = new Node(d3);
    root->left = child1;
    root->right = child2;
    return root;
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
void BFT(Node* root, int data) {
    queue<Node*> q;
    // Node* temp = root;
    q.push(root);
    while(!q.empty()) {
        Node* temp = q.front();
        cout << temp->data << " ";
        q.pop();

        if(!temp->left) {
            Node* temp = new Node(data);
            temp->left = temp;
            break;
        }
        else {
            q.push(temp->left);
        }
        if(temp->right != NULL) {
            Node* temp = new Node(data);
            temp->right = temp;
            break;
        }
        else {
            q.push(temp->right);
        }
    }
    return;
}

void insertNodeBfs(Node* root, int data) {

}

void insertNode(Node* root, int data) {
    // int data;
    // cin >> data;
    if(root->left == NULL) {
        root->left = new Node(data); 
        return;
    }

    else if(root->right == NULL) {
        root->right = new Node(data); 
        return;
    }
    else{
        insertNode(root->left, data);
        insertNode(root->right, data);
    }
    
}

int main(int argc, char const *argv[])
{
    // int d1, d2, d3;

    // cin >> d1 >> d2 >> d3;
    // Node* root = build3Nodes(d1, d2, d3);

    Node* root = buildTree();

    traversal(root);
    cout << "insert:";
    
    insertNode(root, 50);
    traversal(root);
    
    return 0;
}
