#include<bits/stdc++.h>
using namespace std;

int fib(int t1, int t2, int n) {
    if(n == 0) {
        return(t1);
    }
    if(n == 1) {
        return t2;
    }

    // cout << t1+t2 << " ";
    return(fib(t1, t2, n-2) + (fib(t1, t2, n-1)*fib(t1, t2, n-1)));
}

int main(int argc, char const *argv[])
{
    
    int t1, t2, n;
    cin >> t1 >> t2 >> n;
    cout << fib(t1, t2, n-1);    
    return 0;
}
