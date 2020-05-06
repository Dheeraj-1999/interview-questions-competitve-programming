#include<bits/stdc++.h>
using namespace std;

int main(){
	map<char, int> freq;
	string input;
	cin >> input;
	
	for(int i = 0; i<input.size(); i++){	
		freq[input[i]] += 1;
	}
	vector<int> frequency;
	map<char, int> :: iterator it;
	bool flag = false; 
	int a, b;
	for(it = freq.begin(); it != freq.end(); it++){
		frequency.push_back(it->second);
	}
	
	for(int i = 0 ;i<frequency.size(); i++)
		cout << frequency[i] << " " ;
	cout<< endl;
	b= 0;
	if(frequency[0] == frequency[1]){
		a = frequency[0];
		b = 2;
	}
	else if(frequency[1] == frequency[2]){
		if(frequency[0] != frequency[1]+1){
			cout<<"false";
			return false;
		}
		flag = true;	
		a = frequency[1];
		b = 1;
	}	
	
	for(int i = b; i<frequency.size(); i++){
		if(frequency[i] == a)
			continue;
		if(flag == true){
			cout<<"false";
			return false;
		}
		if(frequency[i] != a and flag == false)
			if(frequency[i] != a+1){
				cout<<"false";
				return false;
			}
			flag = true;
			continue;
	}
	cout<<"true";
	return true;
}
