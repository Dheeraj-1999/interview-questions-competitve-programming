#include<iostream>
#include<string.h>
using namespace std;
int main(){
	char * string1 = "yo yo honey singh";
	char * string2 = "yoyo";
	char * yes = strstr(string1 , string2);
	if(yes){
		cout<<"hello";
	} 
	else{
		cout<<"false";
	}
	return 0;
}
