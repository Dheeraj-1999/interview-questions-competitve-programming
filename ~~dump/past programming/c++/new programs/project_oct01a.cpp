#include<iostream>
using namespace std;
class refrence
{
int a,b;
    public:
refrence(int x,int y)
    {
    a=x;
    b=y;

        swap(&a,&b);
}
    void swap(int *c,int *d)
    {
        a=*c;
        b=*d;
        int temp;

        temp=a;
        a=b;
        b=temp;
        cout<<a<<b;
}
    };
int main()
{
refrence r(3,2);
    }
