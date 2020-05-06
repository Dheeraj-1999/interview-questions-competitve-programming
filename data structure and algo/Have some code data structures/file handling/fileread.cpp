#include<iostream>
#include<fstream>
#include<conio.h>
#include<string.h>
using namespace std;
int main(){
	char ch[20];
	ofstream myfile;
	myfile.open("writefile.txt");
	ifstream myfile1;
	myfile1.open("readfile.txt");
	//ch=myfile1.get();
	while(!myfile1.eof()){
		myfile1.getline(ch,20);
		
		myfile<<ch<<"\n";
		myfile<<"\n";
		//myfile1>>ch;
	}
	cout<<"\ncopied successfully";
	myfile.close();
	myfile1.close();
}
