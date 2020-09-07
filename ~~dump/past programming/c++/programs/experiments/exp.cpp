#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
int main(){
	int (* ptr)[3][3];
	int data[3][3]={{2,3,4},{5,6,7}};
	ptr=&data;
	cout<<*ptr[0][2];
	return 0;
}
