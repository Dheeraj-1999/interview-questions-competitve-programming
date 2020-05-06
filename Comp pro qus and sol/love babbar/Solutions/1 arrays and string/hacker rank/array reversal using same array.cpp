#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	int A[10],i,n;
	cin>>n;
	for ( i=0;i<n;i++){
		cin>>A[i];
	}
	for(i=0;i<n;i++){
		cout<<"\n"<<A[n-i-1]<<"\n";
	}
	return 0;
	
} 
