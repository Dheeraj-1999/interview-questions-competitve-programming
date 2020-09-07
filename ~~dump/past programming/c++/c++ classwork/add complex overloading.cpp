#include<iostream>
using namespace std;

class complex{
	protected:
		int real;
		float imag;
	public:
		complex(){};
		complex(int r,float f){
			real=r ; imag=f ;
		}
	complex operator + (complex);
	void display();
};
complex complex :: operator +(complex c){
	complex temp;
	temp.real=real+ c.real;
	temp.imag=imag+ c.imag;
	return(temp);
}
void complex :: display(){
	cout<<"real:"<<real<<"imaginary:"<<imag<<"\n";
}
int main(){
	complex c1(2,3);
	complex c2 (4,5);
	complex c3;
	c3=c1+c2;
	c3.display();
	return 0;
}
