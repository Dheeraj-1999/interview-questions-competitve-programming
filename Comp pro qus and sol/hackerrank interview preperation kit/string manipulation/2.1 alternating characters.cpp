#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		string a;
		int count = 0;
		cin >> a;
		for(int i = 1; i<a.size(); i++){
//			cout<<a[i] << a[i-1] <<" ";
			if(a[i] == a[i-1]){
				count += 1;
			}else{
				continue;
			}
		}
		cout << count <<endl;
	}
}
