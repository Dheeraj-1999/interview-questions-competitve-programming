#include<bits/stdc++.h>
using namespace std;

struct node {
    int data;
    struct node* address;

    node(int x) {
        data = x;
        address = NULL;
    }

};

int main(int argc, char const *argv[])
{
    /* code */
    node *node1 = new node(1);
    node *node2 = new node(3);
    node *node3 = new node(2);
    
    node1->address = node2;
    node2->address = node3;
    node3->address = NULL;
    
    return 0;
}
