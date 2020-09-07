#include<stdio.h>
#include<conio.h>

 int array[20];
 
 int main(){
 	int j,j1;
     printf("enter number of elements \n");
 	for(j = 0 ; j < 20 ; j++){
     	scanf("%d",array[j]);
	 }
	 for(j1 = 0 ; j1 < 20 ; j1++){
     	printf("%d",array[j1]);
	 }
	 return 0;
 }
