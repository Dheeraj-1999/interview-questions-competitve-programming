#include<iostream>

using namespace std;

class person
{
	int age;
	char name[40];
	
	public:
		void getvalue()
		{
			cout<<"enter your names:";
			cin>>name;
			cout<<"enter your age :";
			cin>>age;
		}
		
		void display()
		{
			cout<<name<<"\n";
			cout<<age;
		}
};

int main()
{
	person ram;
	ram.getvalue();
	ram.display();
	return 0;	
}

