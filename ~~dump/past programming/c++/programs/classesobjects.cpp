#include<iostream>
#include<iostream>
using namespace std;



class person
{
	char name[20];
	int age;
	
	
	public:
		void getvalue();
		void display();
		
};

void person::getvalue()
{
	cout<<"enter your name:";
	cin>>name;
	cout<<"\nenter your age:";
	cin>>age;
	
}

void person::display()
{
	
	cout<<"name="<<name<<"\n";
	cout<<"\n age="<<age;
}

int main()
{
	person ram;
	
	ram.getvalue();
	ram.display();
	
	return 0;
}
	
