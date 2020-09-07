#include<conio.h>
#include<stdio.h>
	
int main()
{
	int i,ch,j,a[10];
	for(i=0;i<10;i++)
	{
		scanf("%d",&a[i]);
	}
	
	
	for(int y=0;y<10;y++)
	{
		ch=0;
		if(a[y]!=-1)
		{
			for(j=i+1;j<10;j++)
			{
				if(a[y]==a[j])
				{
					if(ch==0)
					{
						printf("%d",a[j]);
						
					}
					a[j]=-1;
					ch=1;
				}
			}
		}
	}
	getch();
	return 0;
}

