#include<iostream>
#include<conio.h>
#include<fstream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{

	ifstream fs;
	ofstream ft;
	char ch[10], fname1[20], fname2[20];
	cout<<"Enter source file name with extension (like files.txt) : ";
	gets(fname1);
	fs.open(fname1);
	if(!fs)
	{
		cout<<"Error in opening source file..!!";
		getch();
		exit(1);
	}
	cout<<"Enter target file name with extension (like filet.txt) : ";
	gets(fname2);
	ft.open(fname2);
	if(!ft)
	{
		cout<<"Error in opening target file..!!";
		fs.close();
		getch();
		exit(2);
	}
		fs.getline(ch);
		ft<<ch;
	cout<<"File copied successfully..!!";
	fs.close();
	ft.close();
	return 0;
}
