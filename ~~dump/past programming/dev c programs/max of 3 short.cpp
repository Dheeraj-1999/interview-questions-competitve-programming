#include<stdio.h>
#include<conio.h>
int main()
{
	int a,b,c,max;
	scanf("%d%d%d",&a,&b,&c);
	printf("MAXIMUM OF THREE NUMBER SHORTEST CODE I HAVE LEARNT TILL NOW:\nv");
	if(a>b)
	{
		max=a;
    }
    else 
	    max=b;
    
    if(max>c)
       printf("maximum number is %d",max);
       
    else
    {
    	printf("maximum number is %d",c);
	}
    return 0;   
       
	
}
