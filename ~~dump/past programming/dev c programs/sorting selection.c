#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int main()
{
	int i,j,k,arr[20],n;
	int min=0;
//	int *min, *arr[20];
	printf("enter the number of array elements");
	scanf("%d",&n);
	printf("enter yur array elements \n");
	for(i=0;i<n;i++)
	{
			scanf("%d",&arr[i]);
	}

	
	for(i=0;i<n;i++)
	{
			printf("your elements before sorting are %d\n",arr[i]);
	}

	
	for(i=0;i<n;i++)
	{
			k=i;
	
	
	    for(i=1;i<n;i++)     //to find minimum value in array
       	{
	      	if(arr[i]<arr[k])      
	    	{
		    	min=arr[i];
			     
					

		    }
		    
	    	else
	    	{
		    	min=arr[k];
		    } 
	    }
	    int swap;
    	swap=min;
	    min=arr[i];
    	arr[i]=swap;		

    
	
	
	//now swaping min with first element
	
    	
    }
	
	//pinting the sorted array
	for(i=0;i<n;i++)
	{
		printf("elments after sorting are%d\n",arr[i]);
	}
	
	return 0;
}
/*swap(int *i,int *j)
{
	int swap;
	swap=*i;
	*i=*j;
	*j=swap;		

}*/
	
	
    

		
	
	
	
	

