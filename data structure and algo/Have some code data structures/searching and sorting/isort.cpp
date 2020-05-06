#include<iostream>
using namespace std;
void isort(int arr[] , int n){
	int key,i,j;
	for(i=1;i<n;i++){
		key=arr[i];
		j=i-1;
		while(j>=0 && arr[j]>key){
			arr[j+1]=arr[j];
			j--;
		}
		arr[j+1]=key;
	}
}
void print(int arr[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", arr[i]); 
    printf("n"); 
} 
int main(){
	int arr[5]={5,4,3,2,1};
	isort(arr,5);
	print(arr,5);
	return 0;
}
