#include<iostream>
#include<conio.h>
using namespace std;
class base{
 	private:
 		int m_private=90;
 	protected:
 		int m_protected=90;
 	public:
 		int m_public=90;
 		//object.m_public;
 	
 };
 
class derived : public base{
	
	m_private=0;
	m_protected=0;
	m_public=0;
	
};

int main(){
	derived object;
	cout<<object.m_private;
	cout<<object.m_protected;
	cout<<object.m_public;
	return 0;
}
