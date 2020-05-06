#include<iostream>
using namespace std;

int partition(int arr[], int l, int h){
	int pivot,index;
	index = l;
	pivot = h;
	for (int i = l; i<h; i++){
		if(arr[i]<a[pivot]){
			swap(&arr[i], &arr[index]);
			index++
		}
	}
	swap(&arr[pivot], &arr[index]);
	return index;
}

int quicksort(int arr[], int l, int h){
	int pivot = partition(arr,l,h);
	quicksort(arr,l,pivot-1);
	quicksort(arr, pivot, h);
}
int main(){
	
}
