#include<iostream>
#include<conio.h>
using namespace std;

int main(){
	int  B[10],A[10],i,n;
	cin>>n;
	for ( i=0;i<n;i++){
		cin>>A[i];
	}
	for(i=0;i<n;i++){
		B[i]=A[n-i-1];
		cout<<"\n"<<B[i]<<"\n";
	}
	return 0;
	
} 
