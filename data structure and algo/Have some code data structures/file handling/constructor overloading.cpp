#include<iostream>
#include<conio.h>
using namespace std;
class complex{
	protected:
		int x,y,a;
	public:
		complex(){
		}
		complex(int);
		complex(int,int);
		complex sum(complex c1,complex c2){
				complex c3;
				c3.x=c2.x+c1.x;
				c3.y=c2.y+c1.y;
				return c3;
		}
		friend void show(complex);
};
complex::complex(int p){
	a=p=x;
}
complex::complex(int s,int t){
	x=s;y=t;
}

void show(complex c ){
	cout<<c.x<<"+ i"<<c.y<<"\n";
}

int main(){
	complex c1(1,2);
	complex c2(8,9);
	complex c;
	c.sum(c1,c2);
	show(c);
	return 0;
	
}
