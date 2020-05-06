#include<iostream>
#include<string.h>
#include<stdlib.h>
using namespace std; 
int main(){
	string string[10],query[10];
	int i,j,n,B[10],m;
	int count=0;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>string[i];
	}
	//cout<<"\n";
	cin>>m;
	for(i=0;i<m;i++){
		cin>>query[i];
	}
	for(i=0;i<m;i++){
		for(j=0;j<n;j++){
			if(query[i]==string[j]){
				count=count+1;
			}
		}
		B[i]=count;
		count=0;
	}
	for(i=0;i<m;i++){
		cout<<B[i]<<"\n";
	}
	return 0;
}
