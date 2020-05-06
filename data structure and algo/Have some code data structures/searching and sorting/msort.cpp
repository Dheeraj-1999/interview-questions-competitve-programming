#include<stdio.h>
void merge(int arr[] , int low , int high ,int mid , int barr[]){
	int i=low;int k=0;
	int l=low;
	int j=mid+1;
	while(l<=mid && j<=high){
		if(arr[l]<arr[j]){
			barr[i]=arr[l];
			l++;i++;
		}
		else{
			barr[i]=arr[j];
			j++;
			i++;
		}
	}
	if(l>mid){
		for(k=j;k<high;k++){
			barr[i]=arr[k];
			i++;
		}
	}
	else{
		for(k=l;k<mid;k++){
			barr[i]=arr[k];
			i++;
		}
	}
}
void mergesort(int arr[],int low,int high,int barr[]){
	int  mid=low+(high-1)/2;
	mergesort(arr,low,mid-1,barr);
	mergesort(arr,mid+1,high,barr);
	merge(arr,low,high,mid,barr);
}

void print(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("n"); 
} 
int main(){
	int arr[6]={5,4,3,2,1,8};
	int barr[6]={0,0,0,0,0,0};
	int n = sizeof(arr)/sizeof(arr[0]); 
	mergesort(arr,0,n-1,barr);
	print(barr,n);
	return 0;
	
}
