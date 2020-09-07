#include<stdio.h>
#include<conio.h>
void swap(int*a,int*b){
	int temp;
	temp=*a;
	*a = *b;
	*b=temp;
}

int partition(int a[],int low,int high){
	int pivot=a[high];
	int i=low-1;
	int j;
	for(j=low;j<=high-1;j++){
		if(a[j]<=pivot){
			i++;
			swap(&a[i],&a[j]);
			
		}
	} 
	swap(&a[i+1],&a[high]);
	return (i+1);
}

void print(int a[],int size){
	int i;
	for(i=0;i<size;i++){
		printf("%d HELLO ",a[i]);
		
	}
	printf("\n");
}
int QuickSort(int a[],int low,int high){
	if(low<high){
		int pi;
		pi=partition(a,low,high);
		
		QuickSort(a,pi+1,high);
		QuickSort(a,low,pi-1);
	
	}

}
int main(){
	

	int n=10000;
	int a[n],i;
	for (i=n;i>0;i--){
		a[i]=i;
	}
	QuickSort(a,0,n-1);
	printf("sorted arrray");
	print(a,n);
	return 0;
	
}




















