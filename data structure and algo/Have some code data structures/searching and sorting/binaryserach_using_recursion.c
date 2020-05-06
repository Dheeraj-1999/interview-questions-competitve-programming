#include<stdio.h>
#include<conio.h>
int binsearch();

int main()
{
	int a[25],key,l,h,size,i;
	printf("enter number of elements \n");
	scanf("%d",&size);
	
	printf("enter the elements\n");
	for(i=1;i<size;i++)
	{
		scanf("%d",&a[i]);
		
	}

	printf("enter element you want to serach \n");
	scanf("%d",&key);
	
	l=1;
	h=size;
	
	binsearch(a[1],key,l,h);
	return 0;
	
}


int binsearch(int a[1],int key,int low,int high)
{
	int mid;
	mid=(low+high)/2;
	if(low==high)
	{
		if(a[low]==key)
		{
			return low;
		}
		else
		{
			return 0;
		}	
	}
	
	else
	{
		if(a[mid]==key)
		{
			return mid;
		}
		
		else if(a[mid]<key)
		{
			return(binserch(a[1],key,mid+1,high));
			
		}
		else
		{
			return(binserch(a[1],key,low,mid-1));
		}
	}

	
	
}

