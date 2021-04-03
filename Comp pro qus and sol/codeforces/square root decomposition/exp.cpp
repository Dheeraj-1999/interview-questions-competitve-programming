#include<bits/stdc++.h>
using namespace std;
 
#define ff              first
#define ss              second
#define int             long long
#define pb              push_back
#define mp              make_pair
#define pii             pair<int,int>
#define vi              vector<int>
#define mii             map<int,int>
#define pqb             priority_queue<int>
#define pqs             priority_queue<int,vi,greater<int> >
#define setbits(x)      __builtin_popcountll(x)
#define zrobits(x)      __builtin_ctzll(x)
#define mod             1000000007
#define inf             1e18
#define ps(x,y)         fixed<<setprecision(y)<<x
#define mk(arr,n,type)  type *arr=new type[n];
#define w(x)            int x; cin>>x; while(x--)
mt19937                 rng(chrono::steady_clock::now().time_since_epoch().count());
typedef                 vector<vi>		vvi;
 
const int N = 3e5, M = N;
vi g[N];

void ipgraph(int n, int m){
    int i, u, v;
    while(m--){
        cin>>u>>v;
                u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
}


void dfs(int u, int par){
    for(int v:g[u]){
        if (v == par) continue;
        dfs(v, u);
    }
}







 
int32_t main()
{
    w(t) {
        cout << t << " ";
    }
    return 0;
}