#include<iostream>
#include<stdlib.h>
using namespace std; 
struct node{
	int value;
	int count=0;
	struct node *next;
};
struct node *s=NULL;
struct node *start=NULL;
struct node * createNode(){
	struct node *temp;
	temp=(node*)malloc(sizeof(node));
	return temp;
}
void insertNode(){
	int value;
	struct node *t1,*temp2;
	temp2=createNode();
	cin>>temp2->value;
	temp2->next=NULL;
		t1=start;
		if (start==NULL){
			start=temp2;
		}
		else{
		
			while(t1->next!=NULL){
				t1=t1->next;
			}
			t1->next=temp2;
		}
}
void print(){
	if(start==NULL){
		cout<<"\nempty list"<<endl;
	}
	else{
		
		struct node *t,*t2,*temp;
		t=start;
		while(t!=NULL){
			cout<<t->value<<"\n";
			t=t->next;
		}
	}
}
int main(){
	int i,n;
	cin>>n;
	for(i=0;i<n;i++){
		insertNode();
	}
	print();
	return 0;
}





