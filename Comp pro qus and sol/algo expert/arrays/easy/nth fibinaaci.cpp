// Question:
// The Fibonacci sequence is defined as follows: the first number of the sequence is 0, the second number is 1, and the nth number is the sum of the (n - 1)th and (n - 2)th numbers. Write a function that takes in an integer n and returns the nth Fibonacci number.

// # Add, edit, or remove tests in this file.
// # Treat it as your playground!

#include<bits/stdc++.h>
using namespace std;

int nthFib(int n) {
    int a, b, c;
    a = 0;
    b = 1;
    for(int i=2; i<n; i++) {
        c = a+b;
        a = b;
        b = c;
        // cout << c << " ";
    }
    return c;
}

int main() {
    int n;
    cin >> n;
    cout << nthFib(n);
}