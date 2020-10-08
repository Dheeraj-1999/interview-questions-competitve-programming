#include<bits/stdc++.h>
using namespace std;

void print1ton(int b) {
    if(b == 0)
        return;
    print1ton(b-1);
    cout << b << " "; 
}

void printNto1(int b) {
    if(b == 0)
        return;
    cout << b << " "; 
    print1ton(b-1);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    print1ton(n);
    cout << endl;
    printNto1(n);
    return 0;
}
