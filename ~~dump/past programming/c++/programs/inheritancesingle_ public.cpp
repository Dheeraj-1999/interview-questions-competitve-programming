#include<iostream>
#include<conio.h>
using namespace std;

class parent{
	protected:
		int a;	
	public:
	//	int a;
		int b;
		void get_ab();
		int return_a(){
				return a;
		}
		void show_a();
		
};

class child:public parent{
	private:
		int c;
	public:
		void multiply();
		void display();
}; 

void parent::get_ab(){
	a=5;b=10;
}

/*int parent::return_a(){
	return a;
}*/

void parent :: show_a(){
	cout<<"a="<<a<<"\n";
	
}

void child::multiply(){
	c=b*return_a();
	
}

void child::display(){
	cout<<"a="<<a<<"\n";
	cout<<"b="<<b<<"\n";
	cout<<"c="<<c<<"\n";	
}

int main(){
	child object;
	
	object.get_ab();
	object.multiply();
	object.show_a();
	object.display();
	return 0;
}










