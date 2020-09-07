#include<stdio.h>

int binsearch(int[],int,int,int);

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

	l=0;
	h=size;

	binsearch(a,key,0++++,h);
	return 0;

}


int binsearch(int a[],int key,int low,int high)
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
			return(binserch(a,key,mid+1,high));

		}
		else
		{
			return(binserch(a,key,low,mid-1));
		}
	}



}
