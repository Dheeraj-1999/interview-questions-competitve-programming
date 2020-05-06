#include<iostream>
using namespace std;

void display(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void merge(int arr[], int p, int q, int r ){
	int n1 = q-p+1;
	int n2 = r-q;
	
	int *L = new int[n1];
	int *M = new int[n2];
	
	for(int i = 0; i<n1; i++ )
		L[i] = arr[p+i];
	for(int j = 0; j<n2; j++ )
		M[j] = arr[q+j+1];
	int i,j,k;
	i = 0; j = 0; k = p;
	
	while(i<n1 && j<n2){
		if(L[i] <= M[j]){
			arr[k] = L[i];
			i++ ;
		}
		else{
			arr[k] = M[j];
			j++;
		}
		k++;
	}
	
	while(i<n1){
		arr[k] = L[i];
		i++;
		k++; 
	}
	while(j<n2){
		arr[k] = M[j];
		j++;
		k++; 
	}
	
}

void mergesort(int arr[], int p, int r){
	if(p<r){
		int q = p+(r-p)/2;
		mergesort(arr, p,q);
		mergesort(arr, q+1,r);
		merge(arr, p, q,r);
	}
}

int main(){
	int size;
	cin>>size;
	int *arr = new int[size];
	for(int i = 0 ;i<size; i++)
		cin>>arr[i];
	mergesort(arr, 0, size-1);
	display(arr, size);
}
