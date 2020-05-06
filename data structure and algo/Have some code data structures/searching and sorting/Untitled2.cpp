#include<iostream>
using namespace std;

void swap(int *a, int *b) {
   int temp;
   temp = *a;
   *a = *b;
   *b = temp;
}
int partition(int arr[], int l, int h){
	int pivot,index;
	index = l;
	pivot = h;
	for (int i = l; i<h; i++){
		if(arr[i]<arr[pivot]){
			swap(&arr[i], &arr[index]);
			index++;
		}
	}
	swap(&arr[pivot], &arr[index]);
	return index;
}

int quicksort(int arr[], int l, int h){
	if(l<h){
	
		int pivot = partition(arr,l,h);
		quicksort(arr,l,pivot-1);
		quicksort(arr, pivot+1, h);
	}return 0;
}
int main(){
	int n, i;
   cout<<"\nEnter the number of data element to be sorted: ";
   cin>>n;
   int arr[n];
   for(i = 0; i < n; i++) {
      cout<<"Enter element "<<i+1<<": ";
      cin>>arr[i];
   }
   quicksort(arr, 0, n-1);
   cout<<"\nSorted Data ";
   for (i = 0; i < n; i++)
      cout<<"->"<<arr[i];
   return 0;
}
