#include<iostream>
using namespace std;
int main(){
	int a=10;
	float b=10.3;
	int *p;
	float*q;
	p=&a;
	q=&b;
	cout<<sizeof(p)<<sizeof(q);
	return 0;
}
