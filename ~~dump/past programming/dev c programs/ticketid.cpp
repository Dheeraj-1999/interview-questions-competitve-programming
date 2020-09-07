#include <iostream>
using namespace std;
int main()
{
	string ticket,ab,mf,c1;
	c1=ticket.substr(0,2);
	cout<<"enter ticket id";
	cin>>ticket;
	if(c1=="ab"||c1=="mf")
	{
		cout<<"valid ticket";
		
	}
	else
	{
		cout<<"invalid";
	}
	return 0;
}


