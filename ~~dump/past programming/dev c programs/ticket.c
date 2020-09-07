#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int main()
{
	int i;
	char ticket[20],a,b,m,f;
	printf("yur tikt is of 5 numbers:\n");
	printf("enetr your ticket number\n");
	for(i=1;i<=2;i++)
	{
		printf("print charcter");
		scanf("%c",&ticket[i]);
			
	}
	//printf("bjh");
	/*for(i=3;i<=5;i++)
	{
		scanf("%d",&ticket[i]);
	}*/
	
	if((ticket[0]==a&&ticket[1]==b)||(ticket[0]==m&&ticket[1]==f))
	{
		printf("valid ticket");
	}
	
	else if((ticket[0]!=a&&ticket[1]==b)||(ticket[0]!=m&&ticket[1]==f))
	{
		printf("invalid ticket");
	}
	return 0;
}
