#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int data[5]={5,4,3,2,1};
	sort(data,data+3);
	cout<<data[0]<<"exp:"<<data+3;
}
