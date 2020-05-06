#include<iostream>
#include<stdlib.h>
using namespace std;
int main(){
	int A[6][6],B[6][6],i,j,k,l,sum;
	for(i=0;i<6;i++){
		for(j=0;j<6;j++){
			A[i][j]=-j;
			B[i][j]=0;
		}
		cout<<endl;
	}

	for(i=0;i<6;i++){
		for(j=0;j<6;j++){
			cout<<A[i][j];
		}
		cout<<endl;
	}
	int max=-9090909;

	for(k=0;k+2<6;k++){
		for(l=0;l+2<6;l++){
			for(i=k;i<k+3;i++){
                if(i==k+1){
                    B[k][l]=B[k][l]+A[i][l+1];
                }
                else{
                    for(j=l;j<l+3;j++){
						B[k][l]=B[k][l]+A[i][j];
                    }
				}
			}
			if(B[k][l]>=max){
				max=B[k][l];
			}
		}
	}
	for(i=0;i<4;i++){
		for(j=0;j<4;j++){
			cout<<B[i][j]<<" ";
		}

		cout<<endl;
	}
	cout<<"MAx:"<<max;
	return 0;

}
