#include<bits/stdc++.h>
using namespace std;
// #define int long long

int FindFactors(int number) {
    int factor;
    for(int i = 1; i <= number/2; ++i)
    {
        if(number % i == 0)
            factor = i;
            // cout << i << endl;
    }
    return factor;
}

int main()
{
    int n1, n2;
    cin >> n1 >> n2;

    if(n1 == n2) 
        return 0;

    vector<int> factorsN1;
    int tempN1 = FindFactors(n1);
    while(tempN1 != 1) {
        factorsN1.push_back(tempN1);
        tempN1 = FindFactors(tempN1);
    }
    factorsN1.push_back(1);

    vector<int> factorsN2;
    int tempN2 = FindFactors(n2);
    while(tempN2 != 1) {
        factorsN2.push_back(tempN2);
        tempN2 = FindFactors(tempN2);
    }
    factorsN2.push_back(1);
    int count = 0;
    if(n1 < n2) {
        // check n2%n1 == 0
        if(n2%n1 == 0) {
            
            for(unsigned int i=0; i<factorsN2.size(); i++) {
                if(factorsN2[i] != n1) {
                    count += 1;
                } else {
                    count += 1;;
                    break;
                }
            }
            cout << count;
        } 
        else {
            // elseResult(factorsN1, factorsN2);

            for(int i=0; i<factorsN1.size(); i++) {
                count += 1;
            }
            for(int i=0; i<factorsN2.size(); i++) {
                count += 1;
            }
        }
    }
    else {
        // check n1%n2 == 0
        if(n1%n2 == 0) {
            
            for(int i=0; i<factorsN1.size(); i++) {
                if(factorsN1[i] != n2) {
                    count += 1;
                }
                else {
                    count += 1;;
                    break;
                }
            }
            cout << count;
        }
        else {
            // elseResult(factorsN1, factorsN2);
            for(int i=0; i<factorsN1.size(); i++) {
                count += 1;
            }
            for(int i=0; i<factorsN2.size(); i++) {
                count += 1;
            }
            // count =  count;
            cout << count;
        }

    }
    return 0;
}
