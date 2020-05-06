#include<iostream>
#include<conio.h>
#include<string.h>
#include<iterator>
using namespace std;

char * xstr(char * str1,char * str2){
	int a=0;
	int b=0;
	int d=0;int c=0;
	while(str1[d]!=NULL){
		a=d;
	
		while(str1[a]!=NULL){
			if(str1[a]==str2[b]){
				a++;
				b++;
			}
			if(str2[b]==NULL){
				cout<<"\nsubstring present\n";
				break;
			}
			if(str1[a]!=str2[b]){
				b=0;
				a++;
			}
		}
		if(str1[a]==NULL){
			d++;
		}
		else if(str2[b]==NULL){
			break;
		}
	}
	if(str2[b]!=NULL){
			cout<<"string not sub\n";
	}
	
		
	
}
int main(){
	char str1[20],str2[10]
	
	;
	/*char *str1=new char[1];
	char *str2=new char[1];
	char*ptr;*/
	int a;
	cout<<"enter first string\n";
	gets(str1);
	cout<<"enter second string\n";
	gets(str2);
	xstr(str1,str2);
	return 0;
		
}

