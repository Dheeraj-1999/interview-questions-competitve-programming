#include<iostream>
#include<conio.h>
using namespace std;
class complex{
	private:
		float x ,y;
	public:
		complex(){
		}
		complex(float real,float imag ){
			x=real;y=imag;
		}
		complex operator + (complex c){
			complex temp;
			temp.x=x+c.x;
			temp.y=y+c.y;
			return (temp);
		}
		void display(){
			cout<<x<<"+"<<y<<"\n";
		}
		
};
int main(){
	complex c1(5.6,7.8);
	complex c2(4.5,4.5);
	complex c3;
	c3=c1+c2;
	c3.display();
	return 0;
}
