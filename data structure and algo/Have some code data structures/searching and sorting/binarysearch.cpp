#include <stdio.h>
#define MAX_LEN 10
 
/* Non-Recursive function*/
void b_search_nonrecursive(int l[],int num,int ele)
{
   int l1,i,j, flag = 0;
   l1 = 0;
   i = num-1;
   while(l1 <= i)
   {
      j = (l1+i)/2;
      if( l[j] == ele)
      {
    printf("\nThe element %d is present at position %d in list\n",ele,j);
         flag =1;
         break;
      }
      else
        if(l[j] < ele)
           l1 = j+1;
        else
           i = j-1;
   }
   if( flag == 0)
   printf("\nThe element %d is not present in the list\n",ele);
}
 
/* Recursive function*/
int b_search_recursive(int l[],int arrayStart,int arrayEnd,int a)
{
  int m,pos;
  if (arrayStart<=arrayEnd)
  {
    m=(arrayStart+arrayEnd)/2;
    if (l[m]==a)
      return m;
    else if (a<l[m])
      return b_search_recursive(l,arrayStart,m-1,a);
    else
      return b_search_recursive(l,m+1,arrayEnd,a);
   }
   return -1;
}
 
void read_list(int l[],int n)
{
   int i;
   printf("\nEnter the elements:\n");
   for(i=0;i<n;i++)
       scanf("%d",&l[i]);
}
 
void print_list(int l[],int n)
{
    int i;
   for(i=0;i<n;i++)
       printf("%d\t",l[i]);
}
 
/*main function*/
main()
{
   int l[MAX_LEN], num, ele,f,l1,a;
   int ch,pos;
 
   //clrscr();
 
   printf("======================================================");
   printf("\n\t\t\tMENU");
   printf("\n=====================================================");
   printf("\n[1] Binary Search using Recursion method");
   printf("\n[2] Binary Search using Non-Recursion method");
   printf("\n\nEnter your Choice:");
   scanf("%d",&ch);
 
   if(ch<=2 & ch>0)
   {
     printf("\nEnter the number of elements : ");
     scanf("%d",&num);
     read_list(l,num);
     printf("\nElements present in the list are:\n\n");
     print_list(l,num);
     printf("\n\nEnter the element you want to search:\n\n");
     scanf("%d",&ele);
 
 
   switch(ch)
   {
     case 1:printf("\nRecursive method:\n");
        pos=b_search_recursive(l,0,num,ele);
        if(pos==-1)
        {
        printf("Element is not found");
        }
        else
        {
        printf("Element is found at %d position",pos);
        }
        //getch();
        break;
 
     case 2:printf("\nNon-Recursive method:\n");
        b_search_nonrecursive(l,num,ele);
        //getch();
        break;
     }
   }
//getch();
}
