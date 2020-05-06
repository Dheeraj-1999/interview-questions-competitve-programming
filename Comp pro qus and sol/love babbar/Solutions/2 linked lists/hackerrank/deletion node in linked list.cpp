#include<iostream>
#include<stdlib.h>
#include<conio.h>
using namespace std;
struct node{
	int value;
	struct node *next;
};
struct node *s=NULL;
struct node *start=NULL;
struct node * createNode(){
	struct node *temp;
	temp=(node*)malloc (sizeof(node));
	return temp;
}
void deleteNode(){
	int value;
	cout<<"\n";
	cin>>value;
	struct node *t1,*t2,*temp;
	t1=t2=temp=NULL;
	temp=createNode();
	temp->value=value;
	while(start->next!=NULL){
		t2=start->next;
		t1=start;
		start=t2;
	}
	start=NULL;
	cout<<"\nnode inserted";
	
}
void print(){
	struct node *t1,*t2,*temp;
	t1=t2=temp=NULL;
	while(start!=NULL){
		cout<<"\n"<<start->value<<"\n";
		t2=start->next;
		t1=start;
		start=t2;
	}
}
int main(){
	int j=1;
		int value;
		struct node *p;
		cout<<"\nenter any value to store\n";
		cin>>value;
		p=createNode();
		p->value=value;
		start=p;
		s=p;
		p->next=NULL;
	while(j==1){
	cout<<"\nwant to insert node at the end\n";
	cin>>j;
	
		if(j){
			deleteNode();
		}
	}
		print();
	return 0;
}
