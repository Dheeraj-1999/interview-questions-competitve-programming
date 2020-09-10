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

// Inorder Tree Traversal without recursion and without stack!
// Morris Traversal 

// ********************* ALGORITHM ***********************************************

// Initialize current as root 
// 2. While current is not NULL
//    If the current does not have left child
//       a) Print current’s data
//       b) Go to the right, i.e., current = current->right
//    Else
        //  ************ FIND PREDECCESOR ******************
        // PREDECCESOR = FINDPREDECCOR(CURRENT) ie go to the rightmost node 
//       a) Make current as the right child of the rightmost 
//          node in current's left subtree
//       b) Go to this left child, i.e., current = current->left

// ************************************* CODE ***********************************************

// // https://www.youtube.com/watch?v=Bdhgc5tJDHE
void inorderWthutRecStack(Node* root) {
    Node* current = root;
    while(current != NULL){

        if(current->left == NULL) {
            cout << current->data << " ";
            current = current->right;   
        } else {
            Node* temp = current->left; 
            Node* leftPointer = current->left;
            while (temp->right != NULL){ 
                temp = temp->right; 
            }
            temp->right = current;
            current->left = NULL;
            current = leftPointer;
        }
    }
}

// inorder using stack without recursion........

// *************************************** ALGORITHM *************************************************** 

// 1) Create an empty stack S.
// 2) Initialize current node as root.
// 3) Push the current node to S and set current = current->left until current is NULL
// 4) If current is NULL and stack is not empty then 
//      a) Pop the top item from stack.
//      b) Print the popped item, set current = popped_item->right 
//      c) Go to step 3.
// 5) If current is NULL and stack is empty then we are done.

void inorderUsingStack(Node* root) {
    stack<Node*> s;
    Node* current = root;

    while(current != NULL or s.empty() == false){

        while(current != NULL) {
            s.push(current);
            current = current->left;
        }

        current= s.top();
        s.pop();
        cout << current->data << " ";
        current = current->right;
    }
}

// 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1


int main(int argc, char const *argv[])
{
    // Node* root = new Node()
    Node* root = buildTree();
    // traversal(root);
    inorderUsingStack(root);
    cout << endl;
    inorderWthutRecStack(root);
    return 0;
}

