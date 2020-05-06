#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
struct node{
	int value;
	struct node *next;
};
struct node * createNode(){
	struct node *temp;
	temp=(node*)malloc(sizeof(node));
	return temp;
}
bool compare(struct node *llist1,struct node *llist2){
	struct node *t1,*t2;
	t1=llist1;
	t2=llist2;
	while(t1->next!=NULL){
		if(t1->value!=t2->value){
			return 0;
		}
		else{
			if(t2->next!=NULL){
        		t1 = t1->next;
        		t2 = t2->next;
			}
     		else{
          		return 0;
			}
		}	
	}
	return 1;
}
struct node * insertNode(struct node *start){
	int value;
	struct node *t1,*temp2;
	t1=temp2=NULL;
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
		return start;
}
struct node * createlist(){
	int i,n;
	struct node *head=NULL;
	cout<<"enter the length of a list";
	cin>>n;
	for(i=0;i<n;i++){
		head=insertNode(head);
	}
	cout<<"\nlist is created\n";
	return head;
}
int main(){
	bool i;
	struct node *llist1,*llist2;
	cout<<"\nenter the elements for first list\n";
	llist1=createlist();
	cout<<"\nenter the elements for second list\n";
	llist2=createlist();
	i=compare(llist1,llist2);
	if(i){
		cout<<"yes";
	}
	else{
		cout<<"no";
	}
	return 0;
}
