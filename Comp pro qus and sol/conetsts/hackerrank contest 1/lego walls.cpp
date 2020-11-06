
#include <stdlib.h> 
#include <bits/stdc++.h> 
using namespace std;
// enum {false, true}; 
void f(int n) {
    if(n <= 1) {
        cout << n;
    }
    else {
        f(n/2);
        cout << n%2;
    }
}

void m(int* p) {
    int i=0;
    for(i=0; i<5; i++) {
        cout << p[i] << " ";
    }
}
int main() 
{ 
//   f(270);
    // int i, x[5], y, z[5];
    int a[5] = {6,5,3};
    m(&a);
    // for(int i =0; i<5 ; i++) 

}
