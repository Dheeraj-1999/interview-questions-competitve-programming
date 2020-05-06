#include<stdio.h>
#include<conio.h>

int main()
{
	int a[10],l,r,key,mid,size,i;
	printf("enter size of array");
	scanf("%d",&size);
	printf("enter your array");
	for(i=1;i<=size;i++)
	{
		scanf("%d",&a[i]);
		
	
	}
	printf("enter thr number you want to find");
	scanf("%d",&key);
	
	l=1;
	r=size;
	
	while(l<r)
	{
		mid=(l+r)/2;
		printf("%d",mid);
		if(key>a[mid])
		{
			return l=mid+1;
		}
		else if(key < a[mid])
		{
			return r=mid-1;
		}
		else
		{
				
				return mid;;	
		}
		
	}

	return 0;
}
