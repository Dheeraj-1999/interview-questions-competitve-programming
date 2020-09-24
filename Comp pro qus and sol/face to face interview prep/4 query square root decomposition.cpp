#include<bits/stdc++.h>
using namespace std;

int rangeSumOpt(vector<int> sum, int* arr, int blockSize) {
    int l;
    int r;
    cin >> l >> r;
    int left = l;
    int right = r;
    l = l/blockSize;
    r = r/blockSize;
    
    // claculate middle blocks sum
    int middle = 0;
    for(int i=l+1; i<r; i++) {
        middle += sum[i];
    }

// calculate extremes ends sum
    int b1End = (l+1)*blockSize;
    cout << "extreme1 end:" << " " << b1End << endl;
    int extreme1 = 0;
    for(int i=left; i<=b1End; i++) {
        extreme1 += arr[i];
        // cout << "extreme1 end:" << " " << b1End << " " << i << " " << extreme1 << endl;
    }

    int extreme2 = 0;
    int b2Begin = (r+1)*blockSize - blockSize;
    cout << "extreme2 end:" << " " << b2Begin << endl;
    for(int i=b2Begin+1; i<=right; i++) {
        extreme2 += arr[i];
    }
    cout << extreme1 << " " << extreme2 << " " <<middle << endl;
    return(extreme1+extreme2+middle);
}

vector<int> updateBarr(vector<int> Barr, int prev, int index, int blocksize, int current) {
    // for(int i=index; i<=n; i++) {
    //     sum[i] = sum[i-1] + Aarr[i];
    // }
    index = index/blocksize;
    Barr[index] = Barr[index] - prev + current;
    return Barr;
}

int main(int argc, char const *argv[])
{
    
    int n;
    cin >> n;
    int* Aarr = new int[n+1]();
    vector<int> Barr;
    for(int i=1; i<=n; i++) {
        cin >> Aarr[i];
    }

// *************** creating block-block sum array *******************
    
    int blockSize = sqrt(n);
    int sum = 0;
    int count = 0;
    for(int i=1; i<=n; i++) {
        
        sum += Aarr[i];
        count += 1;

        if(count == blockSize) {
            count = 0;
            Barr.push_back(sum);
            sum = 0;   
        }
    }
    // Barr.push_back(sum);
    // /*
    int nQueries;
    cin >> nQueries;

    while(nQueries--) {
        cout << "enter query: Q,U " << endl;
        string query;
        cin >> query;

        if(query == "Q") {
            cout << rangeSumOpt(Barr, Aarr, blockSize) << endl;
        } else if(query == "U") {
            int index, value;
            cout << endl << "enter index: " << endl;
            cin >> index >> value;
            
            int prev;
            prev = Aarr[index];
            Aarr[index] = value;

            Barr = updateBarr(Barr, prev, index, blockSize, value);
            cout << "Updated! " << endl;
        }
        // cout << rangeSumOpt(Barr) << endl;    
    }
    // */

//    for(int i=0; i<Barr.size(); i++)
//     cout << Barr[i] << " ";
    return 0;
}
