#include<iostream>
#include<conio.h>
using namespace std;
class student{
	protected:
		int rollnumber;
	public:
		void getnumber(int a){
			rollnumber=a;
		}
		void putnumber(){
			cout<<"roll_number:"<<rollnumber;
			
		}
		
};
class test:public virtual student{
	protected:
		float part1,part2;
	public:
		void getmarks(float c,float d){
			part1=c;part2=d;
		} 
		void putmarks(){
			cout<<"part1 marks:\n"<<part1<<"part2 marks:\n"<<part2;
			
		}
};
class sports:public virtual student{
	protected:
		float part;
	public:
		void getscore(float c){
		
			part=c;
		} 
		void putscore(){
			cout<<"part marks:\n"<<part;
			
		}
	
};
class result:public sports,public test{
	float total;
	public:
		void display(){
			total=part1+part2+part;
			putnumber();
			putmarks();
			putscore();
			cout<<"\ntotal:\n"<<total;
		}
};
int main(){
	result student1;
	student1.getnumber(678);
	student1.getmarks(23.4,24.5);
	student1.getnumber(24);
	student1.display();
	return 0;
	
}





