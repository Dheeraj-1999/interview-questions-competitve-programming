#include<iostream>
#include<conio.h>
using namespace std;
int  main(){
	int A[10],i,n;
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>A[i];
	}
	for(i=1;i<=n/2;i++){
		swap(A[i],A[n-i+1]);
	}
	cout<<"\n"<<"array after rotation\n";
	for(i=1;i<=n;i++){
		cout<<A[i];
	}
	return 0;
}
void swap(int &a ,int &b){
	int c;
	c=a;
	a=b;
	b=c;
}
