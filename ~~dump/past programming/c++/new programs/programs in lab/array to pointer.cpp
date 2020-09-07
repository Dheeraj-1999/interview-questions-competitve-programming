#include<iostream>
using namespace std;

int main(){
	int *ptr,i,input;
	int a[5]={1,2,3,4};
	ptr=a;
	cin>>input;
	cout<<*ptr[1];
	/*for(i=0;i<5;i++){
		if(*ptr[i]==input){
			cout<<"string present";
			
		}
	}*/
	return 0;
	
}
