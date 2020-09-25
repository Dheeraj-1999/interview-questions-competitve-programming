#include<bits/stdc++.h>
using namespace std;

class List {
    public:
        int data;
        int* address;

    List(int d) {
        data = d;
        address = NULL;
    }
};

int main(int argc, char const *argv[])
{
    cout << " enter the four digit number with space" << endl ;
    int digit;
    cin >> digit;
    List *head = new List(digit);
    for (int i=1; i<4; i++){
        cin >> digit;
        List *node = new List(digit);
        
    }
    
    return 0;
}
