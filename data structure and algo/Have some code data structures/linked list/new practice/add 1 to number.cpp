#include<bits/stdc++.h>
using namespace std;

class node {
    public:
        int data;
        node* address;

    node(int d) {
        data = d;
        address = NULL;
    }
};
// ******************** implementation ***********************************

// Linked List class
/*
class LinkedList {
    node* head;
    node* tail;


    void insert() {

    }

};
*/
// or 

// implement using functions

// insert----------------------- {a: insert at head}
                                // {a: insert at tail}
                                // {a: insert in b/w}

void insertAtHead(node* &head, int d) { //passing a pointer by refernce
    if(head == NULL) {
        head = new node(d);
        return;
    }
    node* firstNode = new node(d);
    firstNode->address = head; // ..........or........ (*firstNode).address = head
    head = firstNode;
}

void insertAtTail(node* &tail, int d) { //passing a pointer by refernce
    if(tail == NULL) {
        tail = new node(d);
        return;
    }
    node* lastNode = new node(d);
    tail->address = lastNode; // ..........or........ (*head).address ie(NULL) =  lastNode
    tail = lastNode;
}

int length(node* head) {
    int cnt = 0;
    while(head->address) {
        cnt++;
        head = head->address;
    }
    return cnt;
}
void insertInMiddle(node* head, int d, int p) {
    if(head == NULL or p == 0) {
        insertAtHead(head, d);
        return;
    }
    else if(p > length(head)) {
        insertAtTail(head, d);
    } else {
        int jump = 1;
        while(jump != p-1) {
            head = head->address;
            jump ++;
        }

        node* n = new node(d);
        n->address = head->address;
        head->address = n;
    }
}

void print(node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->address;
    }    
}

int main(int argc, char const *argv[])
{

    node* head = NULL;
    insertAtHead(head, 1);
    node* tail = head;
    insertAtHead(head, 9);
    insertAtHead(head, 9);
    insertAtHead(head, 9);
    insertAtTail(tail, 9);
    insertAtTail(tail, 9);
    insertAtTail(tail, 9);
    insertAtTail(tail, 9);

    insertInMiddle(head, 100, 4);
    print(head);
}
