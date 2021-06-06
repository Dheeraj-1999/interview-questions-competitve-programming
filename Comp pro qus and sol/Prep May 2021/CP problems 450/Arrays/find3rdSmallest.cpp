#include<bits/stdc++.h>
using namespace std;

int find3rdSmallest(int a[], int n) {
    int f,s,t = INT_MAX;
    if(n < 3) return-1;
    for(int i=0; i<n; i++) {
        if(a[i] < f) {
            t = s;
            s = f;
            f = a[i];
            cout << "f:" << f << " " << s << " " << t << endl;
        } else if( a[i] > f and a[i] < s ) {
            t = s;
            s = a[i];
            cout << "s:" << f << " " << s << " " << t << endl;
        } else if(a[i] > s and a[i] < t ) {
            t = a[i];
            cout << "t:" << f << " " << s << " " << t << endl;
        }
    }
    return t;

}

int find3rdLargest(int a[], int n) {
    int f,s,t = INT_MIN;
    for(int i=0; i<n; i++) {
        if(t < a[i]) {
            f = s;
            s = t;
            t = a[i];
            cout << "f:" << f << " " << s << " " << t << endl;
        } else if(t > a[i] and s < a[i]) {
            f = s;
            s = a[i];
            cout << "s:" << f << " " << s << " " << t << endl;
        } else if(a[i] < s and a[i] > f ) {
            f = a[i];
            cout << "t:" << f << " " << s << " " << t << endl;
        }
    }
    return f;

}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int a[n]; 

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }  
    cout << find3rdLargest(a, n);
    return 0;
}
