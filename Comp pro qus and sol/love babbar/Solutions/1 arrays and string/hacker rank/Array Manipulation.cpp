#include<iostream>
using namespace std;
int main(){
	int a,b,k,arr[10],size,no_of_op,max;
	cin>>size>>no_of_op;
	cout<<"\n";
	int i,j;
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
		if(arr[i]>max){
			max=arr[i];
		}
	}
	cout<<max;
	return 0;
}
