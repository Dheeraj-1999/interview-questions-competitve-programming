#include<bits/stdc++.h>
using namespace std;

int rangeSumOpt(int* sum) {
    int l;
    int r;
    cin >> l >> r;
    return(sum[r] - sum[l-1]);
}

int main(int argc, char const *argv[])
{
    
    int n;
    cin >> n;
    int* Aarr = new int[n+1]();
    int* Barr = new int[n+1]();
    for(int i=1; i<=n; i++) {
        cin >> Aarr[i];
        Barr[i] = Barr[i-1] + Aarr[i];
    }

    int nQueries;
    cin >> nQueries;

    while(nQueries--)
        cout << rangeSumOpt(Barr) << endl;
    return 0;
}
