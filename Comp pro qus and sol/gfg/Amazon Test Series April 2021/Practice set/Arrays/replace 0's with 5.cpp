#include<bits/stdc++.h>
using namespace std;
 
 
int convertFive(int n) {
    // int m = 10;
    // int y = 0;
    // int x = n%10;
    // if( x == 0) x = 5;
    // n = n/10;
    
    // while(n != 0) {
    //     y = n%10;
    //     if(y == 0) {
    //         y = 5;
    //     }
    //     x = y*m + x;
    //     m *= 10;
    //     n /= 10;
    //     // cout << x << " ";
    // }
    for (int i = 0; i < 5; i++)
    {
        int rem = n%10;
        if(rem == 0) {
            rem = 5;
        }
        n = n/10;
        int a = n*10+rem;
        cout << a << " " << n << endl;
    }
    

    

}

int convertFiveRec(int n) {
    if(n == 0) {
        return 0;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    convertFive(n);
    return 0;
}
