#include<iostream>
#include<cmath>
#include<vector>
#include<stdlib.h>
using namespace std;
int main(){
	long int a,b,k,size,no_of_op,max,x=0;
	cin>>size>>no_of_op;
    long int *arr=new long int [size+1]();
	
	//cout<<"\n";
	long int i,j;
	max=0;
	for(i=1;i<=size;i++){
		arr[i]=0;
	}
	for(i=1;i<=no_of_op;i++){
		cin>>a>>b>>k;
		for(j=a;j<=b;j++){
			arr[j]=arr[j]+k;
		}
	}
	for(i=1;i<=size;i++){
		x=x+arr[i];
		if(x>max){
			max=x;
		}
	}
	cout<<max;
	return 0;
}

