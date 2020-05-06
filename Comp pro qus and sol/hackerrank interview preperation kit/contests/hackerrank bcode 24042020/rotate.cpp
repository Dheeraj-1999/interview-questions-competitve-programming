#include<bits/stdc++.h> 
using namespace std; 
  
// In-place rotates s towards left by d 
string leftrotate(string &s, int d) 
{ 
    reverse(s.begin(), s.begin()+d); 
    reverse(s.begin()+d, s.end()); 
    reverse(s.begin(), s.end()); 
    return s;
} 
  
// In-place rotates s towards right by d 
string rightrotate(string &s, int d) 
{ 
   string temp;
   temp = leftrotate(s, s.length()-d); 
   return temp;
} 
  
// Driver code 
int main() 
{ 
    int t;
    cin >>t;
    while(t--) {
        int n, q;
        cin >> n >> q;      
        string str1;
        cin >> str1;
        for(int i=0; i<q; i++) {
            int typ, index;
            cin >> typ >> index;
            if(typ == 1){
               cout << str1 << endl;
               str1 = rightrotate(str1, 2); 
               cout << str1;
            }
            if(typ == 2){
                cout << str1[index];
            } 
        }
    }
    return 0; 
} 