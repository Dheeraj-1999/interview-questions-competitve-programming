#include<bits/stdc++.h>
using namespace std;

int rangeSumOpt(int* sum) {
    int l;
    int r;
    cin >> l >> r;
    return(sum[r] - sum[l-1]);
}

int* updateBarr(int* sum, int* Aarr, int index, int n) {
    for(int i=index; i<=n; i++) {
        sum[i] = sum[i-1] + Aarr[i];
    }
    return sum;
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

    while(nQueries--) {
        cout << "enter query: Q,U " << endl;
        string query;
        cin >> query;

        if(query == "Q") {
            cout << rangeSumOpt(Barr) << endl;
        } else if(query == "U") {
            int index, value;
            cout << endl << "enter index: " << endl;
            cin >> index >> value;
            Aarr[index] = value;

            Barr = updateBarr(Barr, Aarr, index, n);
            cout << "Updated! " << endl;
        }
        // cout << rangeSumOpt(Barr) << endl;    
    }
    return 0;
}
