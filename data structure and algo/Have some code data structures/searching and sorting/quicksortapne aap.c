#include<stdio.h>
void qsort(int arr[] , int low , int high){
	int pi;
	if(low<high){
		pi = partition(arr,low,high);
		qsort(arr,low,pi-1);
		qsort(arr,pi+1,high);
	}
}
int partition(int arr[] , int low , int high){
	int pivot;
	pivot = arr[high];
	int i = low-1; int j = 0;  
	for(j=low;j<=high-1;j++){
		if(arr[j]<=pivot){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return (i+1);	
}
void swap(int * a , int * b){
	int c;
	c=*a;
	*a=*b;
	*b=c;
}
void printArray(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("n"); 
} 
int main(){
	int arr[6]={9,8,7,6,5,4};
	int n = sizeof(arr)/sizeof(arr[0]); 
	qsort(arr,0,n-1);
	printArray(arr,n);
	return 0;
}
