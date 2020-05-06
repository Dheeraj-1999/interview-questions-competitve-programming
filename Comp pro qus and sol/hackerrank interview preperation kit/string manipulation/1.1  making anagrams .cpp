#include<bits/stdc++.h>
using namespace std;
//fcrxzwscanmligyxyvym
//jxwtrhvujlmrpdoqbisbwhmgpmeoke
int main(){
	vector<int>freq(26,0);
	int count = 0;
	string a, b;
	cin >> a >> b;
	for(int i = 0; i<a.size(); i++){
		++freq[a[i]- 'a'];  
	}
	for(int i = 0; i<b.size(); i++){
//		cout << b.size() <<endl;
		--freq[b[i]- 'a'];  
	}
	for(int i = 0; i<26; i++){
		cout << freq[i]<<" ";  
	}
	for(int i = 0; i<26; i++){
//		if(abs(freq[i])>= 1)
//			count += 1;
			count += abs(freq[i]);  
	}
	cout << endl << count <<endl;

}
