#include<iostream>
using namespace std;
// i have problem in this code while allocating dynamic array;
//when we take array of size 14 and rotate it from 7 position then there will occur a problem;
//---------------------------------kindly note this-----------------------------------------
int main(){
	int i,j,n,pos;
	int A[100],B[100];
	cin>>n;
	//A = new int [n];
	//B = new int [n];
	//static volatile int r=7;
	
	for(i=0;i<=n;i++){
		A[i]=i;
		B[i]=0;
	}
	cout<<"enter the positon";
	cin>>pos;
	for(i=0;i<n;i++){
		B[i]=A[pos+i];
	}
	for(i=0;i<n;i++){
		cout<<A[i]<<" ";
	}
	cout<<"\n";
	for(i=0;i<pos;i++){
			swap(A[i],B[i]);
	}	
	for(i=pos;i<n-pos;i++){
		
		A[i]=B[i];
	}
	for(i=pos-1;i>=0;i--){
		A[n-pos+i]=B[i];
	}
	
	for(i=0;i<n;i++){
		cout<<A[i]<<" ";
	}	
	//delete [] A;
	return 0;
}
void swap(int &a,int &b){
		int x;
		x=a;
		a=b;
		b=x;
	}

