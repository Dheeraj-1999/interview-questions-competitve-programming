#include<bits/stdc++.h>
using namespace std;

void fi(vector<int> a, int k, int N) {
    int z,i,inc[k];

    for(i=0 ; i<k ; i++) {
      a[i] = 0;     // initialize our array if needed
      inc[i] = 1;   // all digits are in +1 mode
    }
    int p = k-1;    // p, position: start from last digit (right)
    int count = 0; 
    while(p >= 0) {
        if (p == k-1) {
            int sumTuple = 0;
            for(z=0 ; z<k ; z++){
                // printf("%d", a[z]);
                sumTuple += a[z];
            }
            if(sumTuple % 2 == 0) count += 1;
            // printf("\n");
        }
        if (inc[p]<0 && a[p]>0 || inc[p]>0 && a[p]<N-1) {
          a[p] += inc[p];
          p = k-1;
        }
        else {
          inc[p] = -inc[p];
          p--;
        }
    }
    cout << count;
}

int main() {
    int n1, n2, k;
    cin >> n1 >> n2 >> k;

    vector<int> a;
    for(int i=n1; i<=n2; i++) {
        a.push_back(i);
    }
    fi(a, k, n2-n1+1);
}