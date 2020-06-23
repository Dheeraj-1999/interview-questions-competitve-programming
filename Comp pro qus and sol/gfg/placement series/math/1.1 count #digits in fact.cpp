#include<bits/stdc++.h>
using namespace std;

int digitsInFactorial(int n)
{
    //Your code here
    if (n < 0) 
        return 0; 
  
    // base case 
    if (n <= 1) 
        return 1; 
  
    // else iterate through n and calculate the 
    // value 
    double digits = 0; 
    for (int i=2; i<=n; i++){ 
        digits += log10(i);
        cout << digits << " " << log10(i) << endl;
    }
    cout << endl;
    return floor(digits) + 1; 
}

int main(int argc, char const *argv[])
{
    
    int n;
    cin >> n;
    digitsInFactorial(n);
    return 0;
}
