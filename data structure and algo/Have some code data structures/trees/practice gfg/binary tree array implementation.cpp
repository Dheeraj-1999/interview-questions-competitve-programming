#include<bits/stdc++.h>
using namespace std;

void arrayBuild(int n) {
    int* tree = new int[n+1]();
    int i = 1;
    int data;
    cin >> data;
    tree[1] = data;

    while(i != n) {
        int left, right;
        cin >> left >> right;
        if(left != -1) {
            tree[2*i] = left;
            i = 2*i
        } else {
            i += 1;
        }

        if(right != -1) {
            tree[2*i + 1] = right;
        }
    } 
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
