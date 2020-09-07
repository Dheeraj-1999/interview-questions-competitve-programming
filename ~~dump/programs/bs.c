#include<stdio.h>
#include<conio.h>
void binsearch(int[],int,int,int);

int main()
{
	int key,l,h,size,i;
	printf("enter number of elements \n");
	scanf("%d",&size);
	int a[size];
	printf("enter the elements\n");
	for(i=1;i<size;i++)
	{
		scanf("%d",&a[i]);
		
	}

	printf("enter element you want to serach \n");
	scanf("%d",&key);
	
	l=1;
	h=size;
	
	binsearch(a,key,l,h);
	return 0;
	
}


void binsearch(int a[],int key,int low,int high)
{

	
	int mid;
	mid=(low+high)/2;
	if(low==high)
	{
		if(a[low]==key)
		{
			 printf("keyfounnd");
		}
	
	}
	
	else
	{
		if(a[mid]==key)
		{
			printf("keyfounnd");
		}
		
		else if(a[mid]<key)
		{
			binserch(a,key,mid+1,high);
			
		}
		else
		{
			binserch(a,key,low,mid-1);
		}
	}

	
	
}

