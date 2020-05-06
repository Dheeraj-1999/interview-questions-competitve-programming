#include <iostream>
#include <string.h>
 
using namespace std;
 
void sort(char *arr[])
{
    char * temp;
    for(int j=0; j<6;j++)
    {
        for(int i=0; i<6; i++)
        { 
            if(strncmp(arr[i],arr[i+1],50)>0)
            {
            temp=arr[i];
            arr[i]=arr[i+1];
            arr[i+1]=temp;
            }
        }
    }
}
int main()
{
	char *arr[]={"santosh","amol","santosh jain","kishore","rahul","amolkumar","hemant"};  
	sort(arr);  
	for(int i=0; i<7;i++)   
	{
	    cout<<arr[i]<<endl;
	}  
	return 0;  
}
