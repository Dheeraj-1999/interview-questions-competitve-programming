#include <bits/stdc++.h>
using namespace std;
                     
#define int  long long
// #define endl '\n'



int get(int x)
{
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)
            return x/i;
    }
    return 1;
}



void solution()
{   
    int danisha,danishb;
    cin>>danisha>>danishb;

    if(danisha<danishb)swap(danisha,danishb);
    
    if(danisha==danishb){cout<<0;return;}
    
    map<int,int> m;
    
    int c=0;
    while(danisha!=1)
    {
        c++;
        danisha=get(danisha);
        m[danisha]=c;
    }
    
    c=0;
    while(!m.count(danishb))
    {
        c++;
        danishb=get(danishb);
    }
    cout<<c+m[danishb];
}


int32_t main()
{   
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    solution();
    return 0;
}